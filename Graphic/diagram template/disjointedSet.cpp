#include "disjointedSet.h"

disjointedSet::disjointedSet(int s) {
	size = s;
	parent = new int[size];
	for (int i = 0; i < size; ++i)
		parent[i] = -1;
}

//压缩路径
int disjointedSet::Find(int x) {
	if (parent[x] < 0) return x; //根节点
	return parent[x] = Find(parent[x]); //往上走，高度降低
}

void disjointedSet::Union(int root1, int root2) {
	if (root1 == root2) return;
	if (parent[root1] > parent[root2]) {
		/*判断树的规模--绝对值*/
		parent[root2] += parent[root1];
		parent[root1] = root2;
	}
	else {
		parent[root1] += parent[root2];
		parent[root2] = root1;
	}
}
