#include "MacGrid_2D.h"

MacGrid_2D::MacGrid_2D(const Vector2i &_cellCounts, const double &_dx, const Vector2d &_domainMin) :
	cellCounts(_cellCounts),
	dx(_dx),
	domainMin(_domainMin)
{
	// compute faceCounts[], cellCnt and faceCnt[]
	cellCnt = cellCounts.prod();
	for (int axis = 0; axis < 2; ++axis)
	{
		faceCounts[axis] = cellCounts + Vector2i::Unit(axis);
		faceCnt[axis] = faceCounts[axis].prod();
	}
	// compute cellMin and faceMin[]
	cellMin = domainMin + Vector2d::Ones() * dx * 0.5;
	for (int axis = 0; axis < 2; ++axis)
		faceMin[axis] = cellMin - Vector2d::Unit(axis) * dx * 0.5;
}
