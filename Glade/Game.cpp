#include "Game.h"

void GameCore::_Ready() {

	// Seu Script

}

void GameCore::_Input(InputEvent Input) {

	if (Input.Type == InputType::QUIT) _Finish();

	// Seu Script

}

void GameCore::_Process(double Delta) {

	Renderer->Clear();

	Renderer->ShaderProgram.Use();
	Renderer->VAO.Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// Seu Script

	Renderer->Draw(Window);
}

void GameCore::_Finish() {

	// Seu Script

	Running = false;
}