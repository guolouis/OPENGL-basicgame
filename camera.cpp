#include"camera.h"



Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
}

void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}



void Camera::Inputs(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * -Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		Orientation =  glm::rotate(Orientation, glm::radians(-2.0f), Up);
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		Orientation = glm::rotate(Orientation, glm::radians(2.0f), Up);
	}

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		Orientation = glm::rotate(Orientation, glm::radians(-2.0f), Ho);
	}

	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		Orientation = glm::rotate(Orientation, glm::radians(2.0f), Ho);
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		Position += speed * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		Position += speed * -Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		speed = 0.4f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		speed = 0.1f;
	}
}
