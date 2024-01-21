#include "Aabb.h"
//#include <algorithm>
#include <iostream>

Aabb Aabb::combine(Aabb left, Aabb right)
{
	float upperX = std::max(left.upperBound.x, right.upperBound.x);
	float upperY = std::max(left.upperBound.y, right.upperBound.y);
	float lowerX = std::min(left.upperBound.x, right.upperBound.x);
	float lowerY = std::min(left.upperBound.y, right.upperBound.y);

	Point lowerPoint = Point(lowerX, lowerY);
	Point upperPoint = Point(upperX, upperY);

	return Aabb(lowerPoint, upperPoint);
}

float Aabb::getArea() const {
	float a = upperBound.x - lowerBound.x;
	float b = upperBound.y - lowerBound.y;
	return a * b;
}

Point Aabb::getLeftPoint() const {
	return Point(lowerBound.x, upperBound.y);
}

Point Aabb::getRigthPoint() const {
	return Point(upperBound.x, lowerBound.y);
}

std::ostream& operator <<(std::ostream& stream, const Aabb& box) {
	stream << "box" << std::endl;
	stream << "lowerBound = " << box.lowerBound << std::endl;
	stream << "upperBound = "<< box.upperBound << std::endl;
	return stream;
}