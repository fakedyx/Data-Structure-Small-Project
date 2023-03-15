#pragma once

#ifndef DISJOINTEDSET
#define DISJOINTEDSET

class disjointedSet {
private:
	int* parent;
	int size;
public:
	disjointedSet(int s);
	int Find(int x);
	void Union(int root1, int root2);
	~disjointedSet() { delete[] parent; }
};

#endif
