#pragma once
#include <glm.hpp>
class Vert
{
public:
	Vert(glm::vec3, glm::vec3);

	glm::vec3& GetPositions();
	glm::vec3 GetPositions() const;
	glm::vec3& GetRGB();
private:
	glm::vec3 m_position;
	glm::vec3 m_RGB;
};

