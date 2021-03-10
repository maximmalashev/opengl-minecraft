#pragma once

#include "../engine/glf.h"

class Game : public Updatable
{
public:
	Game();
	~Game();

	void Update() override;
};