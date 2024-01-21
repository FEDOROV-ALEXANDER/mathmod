#pragma once
#include "Point.h"
#include "Aabb.h"
#include<vector>


class Camera {
	float angle;
	float fov;
	float nearestDistance;
	float farestDistance;
	Point coordinates;
	const float pi = 3.14;
public:
	Camera(float angle,
		float fov,
		float nearestDistance,
		float farestDistance,
		Point coordinates);
	bool isPointIncluded(Point point) const;
	bool isAabbIncluded(Aabb box) const;
	std::vector<Point> getTrapezoidPoints() const;
	bool isCameraInAabb(const Aabb& box) const;
	bool isCameraInsideBox(Aabb box) const;
	//bool areCameraAndBoxCross(Aabb box) const;
	
};