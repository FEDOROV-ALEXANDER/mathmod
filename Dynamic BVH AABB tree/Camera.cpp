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
	std::vector<Point> points;
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
	if (areBoxAndCameraCross(box)) return true;
	return false;
}
bool Camera::CrossLine(Point point1, Point point2) const {
	Point point1InCameraCordinates = point1.moveWithRotate(-angle, -coordinates.x, -coordinates.y);
	Point point2InCameraCordinates = point2.moveWithRotate(-angle, -coordinates.x, -coordinates.y);
	float a = tan(fov / 2);
	if ((point1InCameraCordinates.x < nearestDistance) && (point2InCameraCordinates.x < nearestDistance)) return false;
	if ((point1InCameraCordinates.x > farestDistance) && (point2InCameraCordinates.x > farestDistance	)) return false;
	if ((a * point1InCameraCordinates.x < point1InCameraCordinates.y) && (a * point2InCameraCordinates.x < point2InCameraCordinates.y)) return false;
	if ((-a * point1InCameraCordinates.x > point1InCameraCordinates.y) && (-a * point2InCameraCordinates.x > point2InCameraCordinates.y)) return false;

	return true; 
}
bool Camera::areBoxAndCameraCross(Aabb box) const {
	Point leftPoint = box.getLeftPoint();
	Point rightPoint = box.getRigthPoint();
	if (CrossLine(box.lowerBound, leftPoint)) return true;
	if (CrossLine(leftPoint, box.upperBound)) return true;
	if (CrossLine(box.upperBound, rightPoint)) return true;
	if (CrossLine(rightPoint, box.lowerBound)) return true; 

	return false;
}
