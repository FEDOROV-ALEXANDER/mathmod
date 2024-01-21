#pragma once
#include "TreeElement.h"
#include "Aabb.h"
#include "Camera.h"
#include <vector>

class Node : public TreeElement {

	bool isNotChildrenExist() const {
		return left == nullptr || right == nullptr;
	}
public:
	TreeElement* left;
	TreeElement* right;
	Node(TreeElement*, TreeElement*, TreeElement* parent = nullptr);
	~Node();
	void setLeftChild(TreeElement*);
	void setRightChild(TreeElement*);
	Aabb getAabb() const;
	float getCost() const;

	void addIntoVectorIfIncludeInScope(std::vector<Aabb>& boxes, Camera camera) const;

	void replaceChildren(const TreeElement*, TreeElement*);

	int getChildrenCount() const;

	TreeElement* getElementForAdding() const;
};