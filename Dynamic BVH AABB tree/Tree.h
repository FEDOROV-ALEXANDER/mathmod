#pragma once
#include "TreeElement.h"
#include<vector>
#include "Aabb.h"
#include "Camera.h"
#include "Leaf.h"

class Tree
{
	TreeElement* root;
	bool initializeTree(const Aabb&);
	void addNewNode(TreeElement*, const Aabb&);
public:
	~Tree();
	void addAabb(const Aabb& box);

	float getCost() const;

	std::vector<Aabb> getIncludedBoxes(Camera camera) const;

//private:
//	void addSibling(Aabb newBox, Node* baseNode, bool isLeft) {
//		Leaf* newSibling = new Leaf(newBox, baseNode);
//
//		TreeElement* otherElement;
//
//		if (isLeft)
//		{
//			otherElement = baseNode->left;
//		}
//		else
//		{
//			otherElement = baseNode->right;
//		}
//
//		Node* newNode = new Node(baseNode, newSibling, otherElement);
//
//		if (isLeft)
//		{
//			baseNode->left = newNode;
//		}
//		else
//		{
//			baseNode->right = newNode;
//		}
//	}
};