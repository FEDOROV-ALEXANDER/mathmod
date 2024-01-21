#include "Point.h"
#include<iostream>

std::ostream& operator << (std::ostream& stream, const Point& point) {
	stream << "{ x = " << point.x << ", y = " << point.y << " } ";
	return stream;
}

Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}

Point Point::rotation(float angle) const {
	Point result = Point();

	result.x = this->x * std::cos(angle) - this->y * std::sin(angle);
	result.y = this->x * std::sin(angle) + this->y * std::cos(angle);

	return result;
}

Point Point::move(float x, float y) const {
	Point result = Point();
	result.x = this->x + x;
	result.y = this->y + y;
	return result;
}

Point Point::moveWithRotate(float angle, float x, float y) const {
	Point movedPoint = move(x, y);
	return movedPoint.rotation(angle);
}

Point operator + (Point left, Point right)
{
	Point result = Point();
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	return result;
}

Point operator - (Point left, Point right)
{
	Point result = Point();
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	return result;
}