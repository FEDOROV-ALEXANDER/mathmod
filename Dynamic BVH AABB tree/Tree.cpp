#include "Tree.h"
#include "Node.h"
#include<iostream>

Tree::~Tree() {
	delete root;
}

void Tree::addAabb(const Aabb& box) {
	if (initializeTree(box)) return;

	TreeElement* element = root->getElementForAdding();

	if (element == nullptr)
		return;

	addNewNode(element, box);

	if (root == element) 
		std::cout << "Equals";
	//element->addSibling(box);
}

void Tree::addNewNode(TreeElement* selectedElement, const Aabb& newBox) {
	auto parentOfElement = selectedElement->getParent();
	Leaf* newElement = new Leaf(newBox);
	Node* newNode = new Node(newElement, selectedElement, parentOfElement);
	if (parentOfElement == nullptr)
	{
		root = newNode;
	}
	else 
	{
		Node* parentNode = (Node*)parentOfElement;

		if (parentNode == nullptr)
		{
			std::cout << "Parent leaf" << std::endl;
			return;
		}

		parentNode->replaceChildren(selectedElement, newNode);
	}


}

bool Tree::initializeTree(const Aabb& box) {
	if (root != nullptr) return false;
	root = new Leaf(box);
	return true;
}

std::vector<Aabb> Tree::getIncludedBoxes(Camera camera) const {
	std::vector<Aabb> boxes = std::vector<Aabb>();

	if (root == nullptr)
		return boxes;

	root->addIntoVectorIfIncludeInScope(boxes, camera);

	return boxes;
}

float Tree::getCost() const {
	if (root == nullptr)
		return 0;

	return root->getCost();
}