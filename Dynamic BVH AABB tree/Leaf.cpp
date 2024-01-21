#include "Leaf.h"
#include "TreeElement.h"
#include <vector>
Leaf::Leaf(Aabb box, TreeElement* parent) : TreeElement(parent) {
	aabb = box;
}

float Leaf::getCost() const {
	return 0.0;
}

Aabb Leaf::getAabb() const {
	return aabb;
}

void Leaf::addIntoVectorIfIncludeInScope(std::vector<Aabb>& boxes, Camera camera) const {
	if (!camera.isAabbIncluded(aabb))
		return;

	boxes.push_back(aabb);
}

int Leaf::getChildrenCount() const {
	return 1;
}

//const TreeElement* Leaf::getElementForAdding() const {
//	return this;
//}