#include "TestInput.h"

std::vector<Vert> TestInput::GetCubeInput()
{
	std::vector<Vert> Vertices= {
	  Vert(glm::vec3(5,  5, -5), glm::vec3(0.f, 1.f, 0.f)),
	  Vert(glm::vec3(5, -5, -5), glm::vec3(1.f, 0.f, 0.f)),
	  Vert(glm::vec3(-5, -5, -5), glm::vec3(0.f, 0.f, 1.f)),

	  Vert(glm::vec3(-5,  -5, -5), glm::vec3(0.f, 1.f, 0.f)),
	  Vert(glm::vec3(-5,  5, -5), glm::vec3(1.f, 0.f, 0.f)),
	  Vert(glm::vec3(5, 5, -5), glm::vec3(0.f, 0.f, 1.f)),

	  Vert(glm::vec3(-5, -5,  5), glm::vec3(0.f, 0.f, 1.f)),
	  Vert(glm::vec3(5, -5,  5), glm::vec3(0.f, 1.f, 0.f)),
	  Vert(glm::vec3(5, 5, 5), glm::vec3(1.f, 0.f, 0.f)),

	  Vert(glm::vec3(5,  5,  5), glm::vec3(0.f, 0.f, 1.f)), 
	  Vert(glm::vec3(-5, 5,  5), glm::vec3(0.f, 1.f, 0.f)),
	  Vert(glm::vec3(-5, -5, 5), glm::vec3(1.f, 0.f, 0.f)),

	  Vert(glm::vec3(-5,  5,  5), glm::vec3(0.f, 0.f,1.f)),
	  Vert(glm::vec3(-5,  5, -5), glm::vec3(0.f, 1.f,0.f)),
	  Vert(glm::vec3(-5, -5, -5), glm::vec3(1.f, 0.f,0.f)),

	  Vert(glm::vec3(-5, -5, -5), glm::vec3(0.f, 0.f,1.f)),
	  Vert(glm::vec3(-5, -5,  5), glm::vec3(0.f,1.f,0.f)),
	  Vert(glm::vec3(-5,  5,  5), glm::vec3(1.f, 0.f,0.f)),

	  Vert(glm::vec3(5,  5,  5), glm::vec3(0, 0,1)),
	  Vert(glm::vec3(5,  5, -5), glm::vec3(0, 1,0)),
	  Vert(glm::vec3(5, -5, -5), glm::vec3(1, 0,0)),

	  Vert(glm::vec3(5, -5, -5), glm::vec3(0, 0,1)),
	  Vert(glm::vec3(5, -5,  5), glm::vec3(0, 1,0)),
	  Vert(glm::vec3(5,  5,  5), glm::vec3(1, 0,0)),

	  Vert(glm::vec3(-5, -5, -5), glm::vec3(0, 0,1)),
	  Vert(glm::vec3(5, -5, -5), glm::vec3(0, 1,0)),
	  Vert(glm::vec3(5, -5,  5), glm::vec3(1, 0,0)),

	  Vert(glm::vec3(5, -5,  5), glm::vec3(0, 0,1)),
	  Vert(glm::vec3(-5, -5,  5), glm::vec3(0, 1,0)),
	  Vert(glm::vec3(-5, -5, -5), glm::vec3(1, 0,0)),

	  Vert(glm::vec3(-5,  5, -5), glm::vec3(0, 0,1)),
	  Vert(glm::vec3(5,  5,  5), glm::vec3(0, 1,0)),
	  Vert(glm::vec3(5,  5, -5), glm::vec3(1, 0,0)),

	  Vert(glm::vec3(5,  5,  5), glm::vec3(0, 0,1)),
	  Vert(glm::vec3(-5,  5, -5), glm::vec3(0, 1,0)),
	  Vert(glm::vec3(-5,  5,  5), glm::vec3(1, 0,0))
	};
	return Vertices;
}
