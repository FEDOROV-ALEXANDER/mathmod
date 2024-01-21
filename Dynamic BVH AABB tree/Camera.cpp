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

bool Camera::isPointIncluded(Point point) const {
	Point pointInCameraCoordinates = point.moveWithRotate(-angle, -coordinates.x, -coordinates.y);

	float a = tan(fov / 2);

	if (a * pointInCameraCoordinates.x < pointInCameraCoordinates.y) return false;
	if (pointInCameraCoordinates.y < -a * pointInCameraCoordinates.x) return false;
	if (pointInCameraCoordinates.x < nearestDistance) return false;
	if (pointInCameraCoordinates.x > farestDistance) return false;

	return true;
}