#include "application.h"

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../rendering/buffers/vao.h"
#include "../rendering/buffers/vbo.h"
#include "../rendering/buffers/ibo.h"
#include "../rendering/shader.h"
#include "../rendering/renderer.h"
#include "../rendering/materials/texturedMaterial.h"


namespace engine {

	bool Application::InitializeWindow(int width, int height, std::string title)
	{
		m_width = width;
		m_height = height;

		if (!glfwInit())
		{
			std::cout << "GLFW initialization error." << std::endl;
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


		m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!m_window)
		{
			std::cout << "GLFW window error." << std::endl;
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glViewport(0, 0, width, height);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "GLEW failed to initialize." << std::endl;
		}

		glEnable(GL_DEPTH_TEST);

		return true;
	}

	void Application::Start()
	{
		/* Background colour */
		Renderer::SetBackgroundColor(0.0f, 0.0f, 0.0f);
		
		while (!glfwWindowShouldClose(m_window))
		{
			Renderer::Clear();

			for (auto& renderer : renderers)
				renderer->Draw();

			for (auto& updatable : updatables)
				updatable->Update();

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}

		glfwTerminate();
	}

	void Application::AddRenderer(Renderer* renderer)
	{
		renderers.push_back(renderer);
	}

	void Application::RemoveRenderer(Renderer* renderer)
	{
		auto it = find(renderers.begin(), renderers.end(), renderer);

		if (it != renderers.end())
			renderers.erase(it);
	}

	void Application::AddUpdatable(Updatable* updatable)
	{
		updatables.push_back(updatable);
	}

	void Application::RemoveUpdatable(Updatable* updatable)
	{
		auto it = find(updatables.begin(), updatables.end(), updatable);

		if (it != updatables.end())
			updatables.erase(it);
	}

}