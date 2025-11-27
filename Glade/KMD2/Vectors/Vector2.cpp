#include "Vector2.h"
#include "IVector2.h"

ivector2 vector2::ToIVector2() const {

	return ivector2(static_cast<int>(X), static_cast<int>(Y));
}