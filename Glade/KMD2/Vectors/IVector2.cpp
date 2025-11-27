#include "IVector2.h"
#include "Vector2.h"

vector2 ivector2::ToVector2() const {

	return vector2(static_cast<float>(X), static_cast<float>(Y));
}
