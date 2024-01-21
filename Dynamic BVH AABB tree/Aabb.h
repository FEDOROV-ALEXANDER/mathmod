#pragma once
#include "Point.h"

class Aabb
{
public:
	Aabb(Point lowerBound = Point(), Point upperBound = Point()) {
		this->lowerBound = lowerBound;
		this->upperBound = upperBound;
	}
	Point upperBound;
	Point lowerBound;
	static Aabb combine(Aabb left, Aabb right);
	Point getLeftPoint() const;
	Point getRigthPoint() const;
	float getArea() const;

	bool isPointInBox(Point point) const;
};

std::ostream& operator <<(std::ostream& stream, const Aabb& box);