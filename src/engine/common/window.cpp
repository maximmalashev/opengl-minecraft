#include "window.h"

#include <iostream>

namespace engine
{
	Window* Window::m_instance = nullptr;

	Window::Window(GLFWwindow* glfwWindow) : m_glfwWindow(glfwWindow) { }
	Window::~Window() { }

	Window* Window::Initialize(const int width, const int height, const std::string title)
	{
		if (m_instance)
		{
			std::cout << "The window has been already created." << std::endl;
			return nullptr;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


		GLFWwindow* glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!glfwWindow)
		{
			std::cout << "GLFW window error." << std::endl;
			glfwTerminate();
			return nullptr;
		}

		m_instance = new Window(glfwWindow);
		return m_instance;
	}
}
