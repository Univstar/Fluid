#ifndef __FaceField_2D_h__
#define __FaceField_2D_h__

#include "../common/constants.h"
#include "MacGrid_2D.h"
#include "Field_2D.h"

class FaceField_2D
{
protected:

	const MacGrid_2D &macGrid;
	
	array<Field_2D, 2> fields;

public:

	FaceField_2D(const MacGrid_2D &_macGrid, const Vector2d &value = Vector2d::Zero());

	Field_2D &operator[](const int &axis) { return fields[axis]; }
	const Field_2D &operator[](const int &axis) const { return fields[axis]; }
	Vector2d operator()(const Vector2d &coord) const { return Vector2d(fields[0](coord), fields[1](coord)); }
};

#endif // !__FaceField_2D_h__
