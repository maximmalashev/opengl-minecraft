#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

#include "../rendering/renderer.h"
#include "updatable.h"
#include "window.h"


namespace engine {

	class Application 
	{
	public:

		struct Config
		{
			int width = 0, height = 0;
			std::string title = "OpenGL Window";
		};

		bool Initialize(const Config& config);
		void Start();

		void AddRenderer(Renderer& renderer);
		void RemoveRenderer(Renderer& renderer);

		void AddUpdatable(Updatable& updatable);
		void RemoveUpdatable(Updatable& updatable);
	private:
		Window* m_window = nullptr;

		std::vector<Renderer*> m_renderers;
		std::vector<Updatable*> m_updatables;
	};

}