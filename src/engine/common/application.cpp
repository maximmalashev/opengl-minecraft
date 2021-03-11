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

	bool Application::Initialize(const Config& config)
	{
		if (!glfwInit())
		{
			std::cout << "GLFW initialization error." << std::endl;
			return false;
		}

		m_window = Window::Initialize(config.width, config.height, config.title);

		glfwMakeContextCurrent(m_window->GetGLFWWindow());
		glViewport(0, 0, config.width, config.height);

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
		
		while (!glfwWindowShouldClose(m_window->GetGLFWWindow()))
		{
			Renderer::Clear();

			for (auto& renderer : m_renderers)
				renderer->Draw();

			for (auto& updatable : m_updatables)
				updatable->Update();

			glfwSwapBuffers(m_window->GetGLFWWindow());
			glfwPollEvents();
		}

		glfwTerminate();
	}

	void Application::AddRenderer(Renderer& renderer)
	{
		m_renderers.push_back(&renderer);
	}

	void Application::RemoveRenderer(Renderer& renderer)
	{
		auto it = find(m_renderers.begin(), m_renderers.end(), &renderer);

		if (it != m_renderers.end())
			m_renderers.erase(it);
	}

	void Application::AddUpdatable(Updatable& updatable)
	{
		m_updatables.push_back(&updatable);
	}

	void Application::RemoveUpdatable(Updatable& updatable)
	{
		auto it = find(m_updatables.begin(), m_updatables.end(), &updatable);

		if (it != m_updatables.end())
			m_updatables.erase(it);
	}

}