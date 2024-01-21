#include <iostream>
#include<vector>

#include "Tree.h"
#include "Aabb.h"
#include "Camera.h"
#include "Point.h"

using namespace std;

int main()
{
	Tree tree = Tree();
	
	tree.addAabb(Aabb(Point(6, 1), Point(10, 2)));
	tree.addAabb(Aabb(Point(3, 7), Point(5, 11)));
	tree.addAabb(Aabb(Point(10, 7), Point(14, 9)));
	tree.addAabb(Aabb(Point(4, -10), Point(20, 20)));
	tree.addAabb(Aabb(Point(10, 10), Point(16, 12)));
	tree.addAabb(Aabb(Point(0, 0), Point(1, 1)));
	Camera camera(0, 90, 1, 10, Point(5, 4));
	auto boxes = tree.getIncludedBoxes(camera);

	for (auto box: boxes)
	{
		cout << box;
	}

	//int a;
	//cin >> a;
}
