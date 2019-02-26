#include "Field_2D.h"

Field_2D::Field_2D(const MacGrid_2D &_macGrid, const int &axis, const double &value) :
	macGrid(_macGrid),
	mempool(_macGrid.faceCnt[axis], value),
	nodeCounts(_macGrid.faceCounts[axis]),
	nodeCnt(_macGrid.faceCnt[axis]),
	nodeMin(_macGrid.faceMin[axis])
{
}

Field_2D::Field_2D(const MacGrid_2D &_macGrid, const double &value) :
	macGrid(_macGrid),
	mempool(_macGrid.cellCnt, value),
	nodeCounts(_macGrid.cellCounts),
	nodeCnt(_macGrid.cellCnt),
	nodeMin(_macGrid.cellMin)
{
}

Vector2i Field_2D::LeftBound(const Vector2d &coord, Vector2d &frac) const
{
	Vector2i node = ((coord - nodeMin) / macGrid.dx).cast<int>();
	frac = (coord - nodeMin - node.cast<double>() * macGrid.dx) / macGrid.dx;
	return node;
}

double Field_2D::operator()(const Vector2d &coord) const
{
	Vector2d frac;
	Vector2i node = LeftBound(coord, frac);
	return frac[0] * frac[1] * this->operator[](node + Vector2i(1, 1))
		+ frac[0] * (1 - frac[1]) * this->operator[](node + Vector2i(1, 0))
		+ (1 - frac[0]) * frac[1] * this->operator[](node + Vector2i(0, 1))
		+ (1 - frac[0]) * (1 - frac[1]) * this->operator[](node + Vector2i(0, 0));
}
