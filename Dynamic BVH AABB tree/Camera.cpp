#include "Camera.h"

bool Camera::isAabbIncluded(Aabb box) const {
	Point leftPoint = box.getLeftPoint();
	Point rightPoint = box.getRigthPoint();

	if (isPointIncluded(leftPoint)) return true;
	if (isPointIncluded(rightPoint)) return true;
	if (isPointIncluded(box.lowerBound)) return true;
	if (isPointIncluded(box.upperBound)) return true;

	return false;
}
Camera::Camera(float angle,
	float fov,
	float nearestDistance,
	float farestDistance,
	Point coordinates
) {
	this->angle = angle/180*pi;
	this->fov = fov/180*pi;
	this->nearestDistance = nearestDistance;
	this->farestDistance = farestDistance;
	this->coordinates = coordinates;
}
std::vector<Point> Camera::getTrapezoidPoints() const {
	std::vector<Point> points(4);
	Point upperpointLeft = Point(nearestDistance, nearestDistance/tan(fov/2));
	points.push_back(upperpointLeft.moveWithRotate(angle, coordinates.x, coordinates.y));
	Point upperpointRight = Point(farestDistance, farestDistance / tan(fov / 2));
	points.push_back(upperpointRight.moveWithRotate(angle, coordinates.x, coordinates.y));
	Point lowerpointLeft = Point(nearestDistance, -nearestDistance / tan(fov / 2));
	points.push_back(lowerpointLeft.moveWithRotate(angle, coordinates.x, coordinates.y));
	Point lowerpointRight = Point(farestDistance, -farestDistance / tan(fov / 2));
	points.push_back(lowerpointRight.moveWithRotate(angle, coordinates.x, coordinates.y));
	return points;

}

bool Camera::isCameraInAabb(const Aabb& box) const {
	auto points = getTrapezoidPoints();
	for (auto point : points) {
		if (box.isPointInBox(point)) return true;
	}

	return false;
}

bool Camera::isPointIncluded(Point point) const {
	Point pointInCameraCoordinates = point.moveWithRotate(-angle, -coordinates.x, -coordinates.y);

	float a = tan(fov / 2);

	if (a * pointInCameraCoordinates.x < pointInCameraCoordinates.y) return false;
	if (pointInCameraCoordinates.y < -a * pointInCameraCoordinates.x) return false;
	if (pointInCameraCoordinates.x < nearestDistance) return false;
	if (pointInCameraCoordinates.x > farestDistance) return false;

	return true;
}
bool Camera::isCameraInsideBox(Aabb box) const {
	if (isAabbIncluded(box)) return true;
	if (isCameraInAabb(box)) return true;
	return false;
}
//bool Camera::areCameraAndBoxCross(Aabb box) const {
//	auto points = getTrapezoidPoints();
//	std::vector<Point> boxPoints;
//	boxPoints.push_back(box.lowerBound);
//	boxPoints.push_back(box.upperBound);
//	boxPoints.push_back(box.getLeftPoint());
//	boxPoints.push_back(box.getRigthPoint());
//	for (auto point : points) {
//		for (Point boxPoint : boxPoints) {
//			bool isCross;
//
//		}
//	}
//
//	bool isCross;
//	cross(, , , , isCross);
//
//	if (isCross)
//}

