#include "CameraSingleton.h"
#include <gtc/matrix_transform.hpp>
#include <gtx/rotate_vector.hpp>
#include <iostream>

glm::mat4 CameraSingleton::GetMVPMatrix()
{
	return proj * view * model;
}

void CameraSingleton::MoveDown()
{
	m_position -= glm::normalize(glm::cross(m_forward, m_up)) * m_movementSpeed;
	view = glm::lookAt(m_position, m_position +m_forward, m_up);
}

void CameraSingleton::MoveUp()
{
	m_position += glm::normalize(glm::cross(m_forward, m_up)) * m_movementSpeed;
	view = glm::lookAt(m_position, m_position + m_forward, m_up);
}

void CameraSingleton::MoveRight()
{
	m_position += m_movementSpeed * m_up;
	view = glm::lookAt(m_position, m_position + m_forward, m_up);
}

void CameraSingleton::MoveLeft()
{
	m_position -= m_movementSpeed * m_up;
	view = glm::lookAt(m_position, m_position + m_forward, m_up);
}

void CameraSingleton::MoveForwards()
{
	m_position += m_movementSpeed * m_forward;
	view = glm::lookAt(m_position, m_position + m_forward, m_up);
}

void CameraSingleton::MoveBackwards()
{
	m_position -= m_movementSpeed * m_forward;
	view = glm::lookAt(m_position, m_position + m_forward, m_up);
}

void CameraSingleton::RotateRight()
{
	model = glm::rotate(model, glm::radians(10.f), glm::vec3(1, 0,0));
}

void CameraSingleton::RotateLeft()
{
	model = glm::rotate(model, glm::radians(-10.f), glm::vec3(1, 0, 0));
}

void CameraSingleton::ReverseForwardDirection()
{
	m_forward = -m_forward;
}

float CameraSingleton::GetWidth() const
{
	return m_width;
}

float CameraSingleton::GetHeight() const
{
	return m_height;
}

float CameraSingleton::GetFarClippingPlane() const
{
	return m_farClippingPlane;
}

CameraSingleton::CameraSingleton():
	m_position(glm::vec3(0,0,30)),
	m_forward(glm::vec3(0,0,-1)),
	m_up(glm::vec3(0,1,0)),
	m_right(glm::vec3(1,0,0))
{
	proj = glm::perspective(m_FOV, m_width / m_height, m_nearClippingPlane, m_farClippingPlane);
    view = glm::lookAt(m_position, m_position +m_forward, m_up);
	model = glm::mat4(1.0f);
}
