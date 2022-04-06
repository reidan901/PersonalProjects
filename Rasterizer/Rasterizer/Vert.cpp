#include "Vert.h"
#include <iostream>

Vert::Vert(glm::vec3 position, glm::vec3 RGB):
    m_position(position),
    m_RGB(RGB)
{
}

glm::vec3& Vert::GetPositions()
{
    return m_position;
}

glm::vec3 Vert::GetPositions() const
{
    return m_position;
}

glm::vec3& Vert::GetRGB()
{
    return m_RGB;
}
