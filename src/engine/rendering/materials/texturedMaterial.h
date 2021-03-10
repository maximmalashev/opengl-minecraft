#pragma once

#include "../material.h"
#include "../texture.h"

namespace engine {

	class TexturedMaterial : public Material
	{
	public:
		TexturedMaterial(Shader* shader, Texture* texture);
		~TexturedMaterial();

		inline Texture* GetTexture() const { return m_texture; }
	private:
		Texture* m_texture;
	};

}