#include "Node.h"
#include<vector>
//#include "TreeElement.h"

Node::Node(TreeElement* left, TreeElement* right, TreeElement* parent): TreeElement(parent) {
	this->left = left;
	left->setParent(this);
	this->right = right;
	right->setParent(this);
	/*setLeftChild(left);
	setRightChild(right);*/
}

Node::~Node() {
	delete left;
	delete right;
}

void Node::setLeftChild(TreeElement* newChild) {
	left = newChild;
	left->setParent(this);
}

void Node::setRightChild(TreeElement* newChild) {
	right = newChild;
	right->setParent(this);
}



Aabb Node::getAabb() const {
	if (isNotChildrenExist()) return Aabb();

	return Aabb::combine(left->getAabb(), right->getAabb());
}


float Node::getCost() const {
	if (isNotChildrenExist()) return 0.0;

	return left->getCost() + right->getCost() + getAabb().getArea();
}

void Node::addIntoVectorIfIncludeInScope(std::vector<Aabb>& boxes, Camera camera) const {
	auto box = getAabb();
	if (!camera.isCameraInsideBox(box))
		return;

	if (isNotChildrenExist())
		return;

	left->addIntoVectorIfIncludeInScope(boxes, camera);
	right->addIntoVectorIfIncludeInScope(boxes, camera);
}

void Node::replaceChildren(const TreeElement* oldChildren,TreeElement* newChildred) {
	if (isNotChildrenExist())
		return;

	if (oldChildren == left) {
		setLeftChild(newChildred);
		return;
	}

	if (oldChildren == right) {
		setRightChild(newChildred);
		return;
	}

	left->replaceChildren(oldChildren, newChildred);
	right->replaceChildren(oldChildren, newChildred);
}

int Node::getChildrenCount() const {
	if (isNotChildrenExist())
		return 0;

	return left->getChildrenCount() + right->getChildrenCount();
}

TreeElement* Node::getElementForAdding() const {
	if (isNotChildrenExist()) return nullptr;
	auto leftChildrenCount = left->getChildrenCount();
	auto rightChildrenCount = right->getChildrenCount();
	if ( leftChildrenCount > rightChildrenCount)
	{
		if (leftChildrenCount == 1) return left;
		return right->getElementForAdding();
	}
	else
	{
		if (rightChildrenCount == 1) return right;
		return left->getElementForAdding();
	}
}