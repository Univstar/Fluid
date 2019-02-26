#include "FaceField_2D.h"

FaceField_2D::FaceField_2D(const MacGrid_2D &_macGrid, const Vector2d &value) :
	macGrid(_macGrid),
	fields({ Field_2D(_macGrid, 0, value[0]), Field_2D(_macGrid, 1, value[1]) })
{
}
