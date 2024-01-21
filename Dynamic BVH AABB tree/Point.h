#pragma once
#include<iostream>
class Point {
public:
	float x;
	float y;

	Point(float x = 0.0, float y = 0.0);

	Point rotation(float angle) const;

	Point move(float x, float y) const;

	Point moveWithRotate(float angle, float x, float y) const;
};

std::ostream& operator << (std::ostream& stream, const Point& point);