#pragma once

#include <iostream>
#include <string>

#include <SDL3/SDL.h>

struct ivector2;

// 
// Variável de dois vetores flutuantes (float) equivalentes ao espaço bidimensional:
// I
// vector2::Zero() : Retorna dois vetores contendo (0.0f, 0.0f);
// vector2::Vector2ToFRect(vector2 Position, vector2 Scale) : Retorna um FRect (SDL3) com os posição e escala correspondente aos vector2's fornecidos;
// I
// vector2().ToIVector2() : Converte o vector2 atual para sua versão de inteiro (int);
// 
struct vector2 {

	float X;
	float Y;

	vector2(float X = 0.0f, float Y = 0.0f) : X(X), Y(Y) {}

	// Operações:

		// Soma:

	vector2 operator + (const vector2 &Other) const {

		return vector2(Other.X + X, Other.Y + Y);
	}

	vector2 operator + (const float& Value) const {

		return vector2(Value + X, Value + Y);
	}

		// Subtração:

	vector2 operator - (const vector2 &Other) const {

		return vector2(X - Other.X, Y - Other.Y);
	}

	vector2 operator - (const float& Value) const {

		return vector2(X - Value, Y - Value);
	}

		// Multiplicação:

	vector2 operator * (const vector2 &Other) const {

		return vector2(Other.X * X, Other.Y * Y);
	}

	vector2 operator * (const float Value) const {

		return vector2(Value * X, Value * Y);
	}

		// Divisão:

	vector2 operator / (const vector2 &Other) const {

		return vector2(X / Other.X, Y / Other.Y);
	}

	vector2 operator / (const float &Value) const {

		return vector2(X / Value, Y / Value);
	}

	// Lógica:

	bool operator == (const vector2& Other) const {

		return Other.X == X && Other.Y == Y;
	}

	bool operator != (const vector2& Other) const {

		return Other.X != X && Other.Y != Y;
	}

	// Funções estáticas:

	static vector2 Zero() {

		return vector2(0.0f, 0.0f);
	}

	static SDL_FRect Vector2ToFRect(const vector2 &Position, const vector2 &Scale) {

		return { Position.X, Position.Y, Scale.X, Scale.Y };
	}

	// Funções:

	ivector2 ToIVector2() const;

	std::string ToString() {

		return "vector2(" + std::to_string(X) + ", " + std::to_string(Y) + ")";
	}
};