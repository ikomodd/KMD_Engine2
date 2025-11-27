#pragma once

#include <SDL3//SDL.h>

struct vector2;

// 
// Variável de dois vetores inteiros (int) equivalentes ao espaço bidimensional:
// I
// ivector2::Zero() : Retorna dois vetores contendo (0, 0);
// ivector2::Vector2ToRect(ivector2 Position, ivector2 Scale) : Retorna um Rect (SDL3) com os posição e escala correspondente aos ivector2's fornecidos;
// I
// ivector2().ToVector2() : Converte o ivector2 atual para sua versão de flotuante (float);
// 
struct ivector2 {

	int X;
	int Y;

	ivector2(int X = 0.0f, int Y = 0.0f) : X(X), Y(Y) {}

	// Operações:

		// Soma:

	ivector2 operator + (const ivector2& Other) const {

		return ivector2(Other.X + X, Other.Y + Y);
	}

	// Subtração:

	ivector2 operator - (const ivector2& Other) const {

		return ivector2(X - Other.X, Y - Other.Y);
	}

	// Multiplicação:

	ivector2 operator * (const ivector2& Other) const {

		return ivector2(Other.X * X, Other.Y * Y);
	}

	ivector2 operator * (int Value) const {

		return ivector2(Value * X, Value * Y);
	}

	// Divisão:

	ivector2 operator / (const ivector2& Other) const {

		return ivector2(X / Other.X, Y / Other.Y);
	}

	ivector2 operator / (int Value) const {

		return ivector2(Value / X, Value / Y);
	}

	// Lógica:

	bool operator == (ivector2 Other) {

		return Other.X == X && Other.Y == Y;
	}

	bool operator != (ivector2 Other) {

		return Other.X != X && Other.Y != Y;
	}

	// Funções estáticas:

	static ivector2 Zero() {

		return ivector2(0.0f, 0.0f);
	}

	static SDL_Rect Vector2ToRect(const ivector2& Position, const ivector2& Scale) {

		return { Position.X, Position.Y, Scale.X, Scale.Y };
	}

	// Funções:

	vector2 ToVector2() const;
};