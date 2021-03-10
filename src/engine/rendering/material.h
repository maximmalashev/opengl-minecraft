#pragma once

#include "shader.h"

namespace engine {

	class Material
	{
	public:
		Material(Shader* shader);
		~Material();

		inline Shader* GetShader() const { return m_shader; } 
	private:
		Shader* m_shader;
	};

}