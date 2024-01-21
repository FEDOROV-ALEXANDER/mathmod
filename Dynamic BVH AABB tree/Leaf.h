#pragma once
#include "TreeElement.h"
#include "Aabb.h"
#include<vector>
#include "Camera.h"

class Leaf : public TreeElement {
	Aabb aabb;
public:
	Leaf(Aabb box, TreeElement* parent = nullptr) /*: TreeElement(parent)*/;
	~Leaf();
	float getCost() const;

	Aabb getAabb() const;

	void addIntoVectorIfIncludeInScope(std::vector<Aabb>& boxes, Camera camera) const;
	int getChildrenCount() const;

	//const TreeElement* getElementForAdding() const;
};