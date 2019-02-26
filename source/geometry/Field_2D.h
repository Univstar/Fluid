#ifndef __Field_2D_h__
#define __Field_2D_h__

#include "../common/constants.h"
#include "MacGrid_2D.h"

class Field_2D
{
protected:

	const MacGrid_2D &macGrid;

	vector<double> mempool;

	Vector2i nodeCounts;
	int nodeCnt;

	Vector2d nodeMin;

	Field_2D(const MacGrid_2D &_macGrid, const int &axis, const double &value);

public:

	Field_2D(const MacGrid_2D &_macGrid, const double &value = 0.0);
	
	int NodeSize() const { return nodeCnt; }
	int Index(const Vector2i &node) const { return node[0] * nodeCounts[1] + node[1]; }
	Vector2i Node(int index) const { return Vector2i(index / nodeCounts[1], index % nodeCounts[1]); }
	Vector2d Position(const Vector2i &node) const { return node.cast<double>() * macGrid.dx + nodeMin; }
	Vector2i LeftBound(const Vector2d &coord, Vector2d &frac) const;

	double &operator[](const Vector2i &node) { return mempool[Index(node)]; }
	const double &operator[](const Vector2i &node) const { return mempool[Index(node)]; }
	double operator()(const Vector2d &coord) const;

	friend class FaceField_2D;
};

#endif // !__Field_2D_h__
