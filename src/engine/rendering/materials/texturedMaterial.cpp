#include "texturedMaterial.h"

namespace engine {

	TexturedMaterial::TexturedMaterial(Shader* shader, Texture* texture)
		: Material(shader), m_texture(texture) { }

	TexturedMaterial::~TexturedMaterial()
	{
		delete m_texture;
	}

}


