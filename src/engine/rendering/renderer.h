#pragma once

#include <glm/glm.hpp>

#include "texture.h"
#include "buffers/vao.h"
#include "material.h"

namespace engine {

	class Renderer 
	{
	public:
		static void SetBackgroundColor(float red, float green, float blue);
		static void Clear();

		static inline void SetProjection(glm::mat4x4 projection) { m_projection = projection; }
		static inline void SetView(glm::mat4x4 view) { m_view = view; }
		
		virtual void Draw() = 0;
	protected:
		static glm::mat4x4 m_projection;
		static glm::mat4x4 m_view;
	};
}