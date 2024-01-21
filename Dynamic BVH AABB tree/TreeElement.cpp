#include "TreeElement.h"
#include "Aabb.h"
#include "Leaf.h"
#include "Node.h"

TreeElement::TreeElement(TreeElement* parent) {
	this->parent = parent;
}

TreeElement* TreeElement::getParent() const {
	return parent;
}

void TreeElement::setParent(TreeElement* newParent) {
	parent = newParent;
}

void TreeElement::addSibling(Aabb newBox) {
	TreeElement* newElement = new Leaf(newBox);

	TreeElement* newParent = new Node(newElement, this, parent);
	newElement->parent = newParent;
	parent->replaceChildren(this, newParent);

	parent = newParent;
}