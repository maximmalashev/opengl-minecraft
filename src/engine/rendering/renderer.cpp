#include "renderer.h"

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

namespace engine {
	
	glm::mat4x4 Renderer::m_projection;
	glm::mat4x4 Renderer::m_view;

	void Renderer::SetBackgroundColor(float red, float green, float blue)
	{
		glClearColor(red, green, blue, 1.0f);
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

}

