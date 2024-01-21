#include "TreeElement.h"
#include "Aabb.h"
#include "Leaf.h"
#include "Node.h"

TreeElement::TreeElement(TreeElement* parent) {
	this->parent = parent;
}

TreeElement::~TreeElement() {
	delete parent;
}

TreeElement* TreeElement::getParent() const {
	return parent;
}

void TreeElement::setParent(TreeElement* newParent) {
	parent = newParent;
}