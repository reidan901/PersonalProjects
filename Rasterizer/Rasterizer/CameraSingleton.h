#pragma once
#include <glm.hpp>
class CameraSingleton
{
public:
	static CameraSingleton& GetInstance() {
		static CameraSingleton instance;
		return instance;
	}
	glm::mat4 proj;
	glm::mat4 view;
	glm::mat4 model;

	glm::mat4 GetMVPMatrix();

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void MoveForwards();
	void MoveBackwards();

	void RotateRight();
	void RotateLeft();

	void ReverseForwardDirection();

	float GetWidth() const;
	float GetHeight() const;
	float GetFarClippingPlane() const;
private:
	CameraSingleton();
	CameraSingleton(const CameraSingleton&) = delete;
	const float m_nearClippingPlane = 1.f;
	const float m_farClippingPlane = 100.f;
	const float m_FOV = 45.f;
	const float m_movementSpeed = 1.f;
	const float m_width = 512;
	const float m_height = 512;
	glm::vec3 m_position;
	glm::vec3 m_forward;
	glm::vec3 m_up;
	glm::vec3 m_right;	
};

