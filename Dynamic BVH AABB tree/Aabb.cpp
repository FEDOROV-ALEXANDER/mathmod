#include "Aabb.h"
#include "Camera.h"
//#include <algorithm>
#include <iostream>

Aabb Aabb::combine(Aabb left, Aabb right)
{
	float upperX = std::max(left.upperBound.x, right.upperBound.x);
	float upperY = std::max(left.upperBound.y, right.upperBound.y);
	float lowerX = std::min(left.lowerBound.x, right.lowerBound.x);
	float lowerY = std::min(left.lowerBound.y, right.lowerBound.y);

	Point lowerPoint = Point(lowerX, lowerY);
	Point upperPoint = Point(upperX, upperY);

	return Aabb(lowerPoint, upperPoint);
}


bool Aabb::isPointInBox(Point point) const {
	if (point.x > upperBound.x) return false;
	if (point.x < lowerBound.x) return false;
	if (point.y > upperBound.y) return false;
	if (point.y < lowerBound.y) return false;
	return true;
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
