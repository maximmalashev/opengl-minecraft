#pragma once

#include <GL/glew.h>
#include <glfw/glfw3.h>

#include <string>

namespace engine
{
	class Window
	{
	public:
		static Window* Initialize(const int width, const int height, const std::string title);

		static inline Window* GetInstance() { return m_instance; }
		inline GLFWwindow* GetGLFWWindow() const { return m_glfwWindow; }
	private:
		Window(GLFWwindow* glfwWindow);
		~Window();

		static Window* m_instance;

		GLFWwindow* m_glfwWindow = nullptr;
	};
}
