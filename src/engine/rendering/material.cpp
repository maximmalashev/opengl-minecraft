#include "material.h"

namespace engine {

	Material::Material(Shader* shader)
		: m_shader(shader) { }

	Material::~Material()
	{
		delete m_shader;
	}

}

