﻿#include <iostream>
#include<vector>

#include "Tree.h"
#include "Aabb.h"
#include "Camera.h"
#include "Point.h"

using namespace std;

int main()
{
	Tree tree = Tree();
	tree.addAabb(Aabb(Point(1, 1), Point(2, 2)));
	tree.addAabb(Aabb(Point(6, 1), Point(10, 2)));
	tree.addAabb(Aabb(Point(3, 7), Point(5, 11)));
	tree.addAabb(Aabb(Point(10, 7), Point(14, 9)));
	Camera camera(180, 90, 1, 10, Point(0, 0));
	auto boxes = tree.getIncludedBoxes(camera);

	for (auto box: boxes)
	{
		cout << box;
	}

	//int a;
	//cin >> a;
}