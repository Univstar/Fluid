#ifndef __MacGrid_2D_h__
#define __MacGrid_2D_h__

#include "../common/constants.h"

class MacGrid_2D
{
protected:
	
	Vector2i cellCounts;
	array<Vector2i, 2> faceCounts;

	int cellCnt;
	array<int, 2> faceCnt;

	double dx;
	Vector2d domainMin;
	Vector2d cellMin;
	array<Vector2d, 2> faceMin;

public:

	MacGrid_2D(const Vector2i &_cellCounts, const double &_dx, const Vector2d &_domainMin = Vector2d::Zero());

	friend class Field_2D;
	friend class FaceField_2D;
};
#endif // !__MacGrid_2D_h__
