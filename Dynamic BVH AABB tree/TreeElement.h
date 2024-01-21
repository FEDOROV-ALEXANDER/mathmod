#pragma once
#include <vector>
#include "Aabb.h"
#include "Camera.h"

class TreeElement
{
protected:
	TreeElement* parent;
public:
	~TreeElement();
	TreeElement* getParent() const;
	void setParent(TreeElement*);
	TreeElement(TreeElement* parent = nullptr);
	virtual Aabb getAabb() const = 0;
	virtual void addIntoVectorIfIncludeInScope(std::vector<Aabb>& boxes, Camera camera) const = 0;
	virtual float getCost() const = 0;
	virtual void replaceChildren(const TreeElement*, TreeElement*) {};
	virtual int getChildrenCount() const = 0;
	virtual TreeElement* getElementForAdding() {
		return this;
	}
	//virtual void insert(TreeElement&, TreeElement*) = 0;
	//virtual void addBox(Aabb box) = 0;
};