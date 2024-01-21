#include "Aabb.h"
#include "Camera.h"
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
//Point Aabb::cross(Point point1, Point point2, Point point3, Point point4, bool& isCross) {
//	float x1 = point1.x;
//	float y1 = point1.y;
//	float x2 = point2.x;
//	float y2 = point2.y;
//	float x3 = point3.x;
//	float y3 = point3.y;
//	float x4 = point4.x;
//	float y4 = point4.y;
//	float n;
//	if (y2 - y1 != 0) {  // a(y)
//		float q = (x2 - x1) / (y1 - y2);
//		float sn = (x3 - x4) + (y3 - y4) * q; 
//		if (!sn) 
//		{ 
//			isCross = false;
//			return Point(0, 0); 
//		}  // c(x) + c(y)*q
//		float fn = (x3 - x1) + (y3 - y1) * q;   // b(x) + b(y)*q
//		n = fn / sn;
//	}
//	else {
//		if (!(y3 - y4)) 
//		{ 
//			isCross = false;
//			return 0; 
//		}  // b(y)
//		n = (y3 - y1) / (y3 - y4);   // c(y)/b(y)
//	}
//	float x = x3 + (x4 - x3) * n;  // x3 + (-b(x))*n
//	float y = y3 + (y4 - y3) * n;  // y3 +(-b(y))*n
//	isCross = true;
//	return Point(x, y);
//}