#pragma once

#include "KMD2/Core/Core.h"

class GameCore : public KMD_Core {
public:

	//

	// Suas Variáveis

	//

	GameCore(): KMD_Core("KMD", ivector2(800, 600), color4::Black(), 0) {};

	//

	// Suas Funções

	//

	void _Ready() override;

	void _Input(SDL_Event event) override;

	void _Process(double Delta) override;

	void _Finish() override;
};