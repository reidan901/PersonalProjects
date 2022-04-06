#include "Rasterizer.h"
#include <SFML/Graphics.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/rotate_vector.hpp>
#include <vector>
#include <algorithm>
#include "CameraSingleton.h"
#include "TestInput.h"
#include <iostream>
#include <chrono>

sf::Image Rasterizer::Rasterization()
{	
	auto&& height = CameraSingleton::GetInstance().GetHeight();
	auto&& width = CameraSingleton::GetInstance().GetWidth();
	sf::Image output;
	sf::Uint8* PixelArray = new sf::Uint8[width * height * 4];
	float* depthBuffer = new float[width * height];
	std::fill_n(depthBuffer, width*height, CameraSingleton::GetInstance().GetFarClippingPlane());
	std::fill_n(PixelArray, width * height * 4, 0);
	std::vector<Vert> Vertices = TestInput::GetCubeInput();
	auto t_start = std::chrono::high_resolution_clock::now();
	for (int x = 0; x < Vertices.size(); x = x + 3)
	{
		Vertices[x].GetPositions() = ToRasterSpace(Vertices[x].GetPositions());
		Vertices[x + 1].GetPositions() = ToRasterSpace(Vertices[x + 1].GetPositions());
		Vertices[x + 2].GetPositions() = ToRasterSpace(Vertices[x + 2].GetPositions());

		auto& c0 = Vertices[x].GetRGB();
		auto& c1 = Vertices[x + 1].GetRGB();
		auto& c2 = Vertices[x + 2].GetRGB();
		float area = EdgeFunction(Vertices[x], Vertices[x + 1], Vertices[x + 2]);
		auto bounds = ComputeBoundingTriangle(Vertices[x], Vertices[x + 1], Vertices[x + 2]);
		for (int i = std::get<0>(bounds); i < std::get<1>(bounds); i++)
		{
			for (int j = std::get<2>(bounds); j < std::get<3>(bounds); j++)
			{
				Vert p(glm::vec3(i+.5f, j+.5f, 0), glm::vec3(0.f, 0.f, 0.f));
				float w0 = EdgeFunction(Vertices[x + 1], Vertices[x + 2], p);
				float w1 = EdgeFunction(Vertices[x + 2], Vertices[x], p);
				float w2 = EdgeFunction(Vertices[x], Vertices[x + 1], p);
				if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
					w0 /= area;
					w1 /= area;
					w2 /= area;
					float z = 1/(Vertices[x].GetPositions().z * w0 + Vertices[x + 1].GetPositions().z * w1 + Vertices[x + 2].GetPositions().z * w2);
					if (z < depthBuffer[i * (int)width + j])
					{						
						depthBuffer[i * (int)width + j] = z;
						float r = w0 * c0.x + w1 * c1.x + w2 * c2.x;
						float g = w0 * c0.y + w1 * c1.y + w2 * c2.y;
						float b = w0 * c0.z + w1 * c1.z + w2 * c2.z;
						PixelArray[(i * (int)width + j) * 4] = r * 255;
						PixelArray[(i * (int)width + j) * 4 + 1] = g * 255;
						PixelArray[(i * (int)width + j) * 4 + 2] = b * 255;
						PixelArray[(i * (int)width + j) * 4 + 3] = 255;
					}
				}
			}
		}
	}
	auto t_end = std::chrono::high_resolution_clock::now();
	auto passedTime = std::chrono::duration<double, std::milli>(t_end - t_start).count();
	std::cout << "Time for frame: " << passedTime << " miliseconds.\n";
	output.create(width, height, PixelArray);
	return output;
}

glm::vec3 Rasterizer::ToRasterSpace(const glm::vec3& point)
{
	auto&& height = CameraSingleton::GetInstance().GetHeight();
	auto&& width = CameraSingleton::GetInstance().GetWidth();
	glm::vec4 hPoint = glm::vec4(point, 1);
	hPoint = CameraSingleton::GetInstance().GetMVPMatrix() * hPoint;
	hPoint.x /= hPoint.w;
	hPoint.y /= hPoint.w;
	hPoint.z /= hPoint.w;
	hPoint.x = (hPoint.x + 1) / 2 * width;
	hPoint.y = (1 - hPoint.y) / 2 * height;
	hPoint.z = -hPoint.z;
	return glm::vec3(hPoint.x, hPoint.y, hPoint.z);
}

std::tuple<int, int, int, int> Rasterizer::ComputeBoundingTriangle(const Vert& a, const Vert& b, const Vert& c)
{
	auto&& aPos = a.GetPositions();
	auto&& bPos = b.GetPositions();
	auto&& cPos = c.GetPositions();
	float xmin = std::min(aPos.x, std::min(bPos.x, cPos.x));
	float xmax = std::max(aPos.x, std::max(bPos.x, cPos.x));
	float ymin = std::min(aPos.y, std::min(bPos.y, cPos.y));
	float ymax = std::max(aPos.y, std::max(bPos.y, cPos.y));
	int x0 = std::max(0, (int)std::floor(xmin));
	int x1 = std::min((int)CameraSingleton::GetInstance().GetWidth(), (int)std::floor(xmax));
	int y0 = std::max(0, (int)std::floor(ymin));
	int y1 = std::min((int)CameraSingleton::GetInstance().GetHeight(), (int)std::floor(ymax));
	return std::make_tuple(x0, x1, y0, y1);
}

float Rasterizer::EdgeFunction(const Vert& a, const Vert& b, const Vert& p)
{
	auto&& aPos = a.GetPositions();
	auto&& bPos = b.GetPositions();
	auto&& pPos = p.GetPositions();
	return (pPos.x - aPos.x) * (bPos.y - aPos.y) - (pPos.y - aPos.y) * (bPos.x - aPos.x);
}
