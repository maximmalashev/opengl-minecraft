#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

#include "../rendering/renderer.h"
#include "updatable.h"


namespace engine {

	class Application 
	{
	public:
		bool InitializeWindow(int width, int height, std::string title);
		void Start();

		void AddRenderer(Renderer* renderer);
		void RemoveRenderer(Renderer* renderer);

		void AddUpdatable(Updatable* updatable);
		void RemoveUpdatable(Updatable* updatable);
	private:
		GLFWwindow* m_window;

		std::vector<Renderer*> renderers;
		std::vector<Updatable*> updatables;

		int m_width, m_height;
	};

}