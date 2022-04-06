#pragma once
#include "Vert.h"
#include <SFML/Graphics.hpp>
#include <glm.hpp>
#include <tuple>
class Rasterizer
{
public:
	sf::Image Rasterization();
private:
	float EdgeFunction(const Vert& a, const Vert& b, const Vert& p);
	glm::vec3 ToRasterSpace(const glm::vec3& point);
	std::tuple<int, int, int, int> ComputeBoundingTriangle(const Vert& a, const Vert& b, const Vert& c);
};

