/*
 * @Descripttion:
 * @version:
 * @Author: faker
 * @Date: 2022-10-07 16:39:02
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-10-08 09:51:36
 */
#include "adjListGraph.hpp"
#include <string>
using namespace std;


void test_traverse() {
	const char* s = "abcdefg";
	adjListGraph<char, int> g(7, s);
	g.insert('a', 'b', 10);
	g.insert('a', 'c', 12);
	g.insert('a', 'd', 10);
	g.insert('b', 'd', 12);
	g.insert('b', 'f', 10);
	g.insert('b', 'c', 12);
	g.insert('c', 'd', 10);
	g.insert('d', 'g', 12);
	g.insert('e', 'f', 10);
	g.insert('e', 'g', 12);
	g.insert('g', 'f', 10);

	cout << "深度优先" << endl;
	g.dfs();

	cout << "广度优先" << endl;
	g.bfs();
}

void test_dijstra() {
	const char* s = "abcdefg";
	adjListGraph<char, int> g(7, s);
	g.insert('a', 'b', 10);
	g.insert('a', 'c', 12);
	g.insert('a', 'd', 10);
	g.insert('b', 'd', 12);
	g.insert('b', 'f', 10);
	g.insert('b', 'c', 12);
	g.insert('c', 'd', 10);
	g.insert('d', 'g', 12);
	g.insert('e', 'f', 10);
	g.insert('e', 'g', 12);
	g.insert('g', 'f', 10);

	g.dijstra('a', 0xffff);
}

void test_prim() {
	int array[6] = { 1,2,3,4,5,6 };
	adjListGraph<int, int> g(6, array);
	g.insert(1, 2, 6);
	g.insert(2, 1, 6);
	g.insert(1, 3, 1);
	g.insert(3, 1, 1);
	g.insert(1, 4, 5);
	g.insert(4, 1, 5);
	g.insert(2, 3, 5);
	g.insert(3, 2, 5);
	g.insert(2, 5, 3);
	g.insert(5, 2, 3);
	g.insert(3, 4, 5);
	g.insert(4, 3, 5);
	g.insert(3, 5, 6);
	g.insert(5, 3, 6);
	g.insert(3, 6, 4);
	g.insert(6, 3, 4);
	g.insert(4, 6, 2);
	g.insert(6, 4, 2);
	g.insert(5, 6, 6);
	g.insert(6, 5, 6);
	g.prim(0xff);
}


void test_kruskal() {
	int array[6] = { 1,2,3,4,5,6 };
	adjListGraph<int, int> g(6, array);
	g.insert(1, 2, 6);
	g.insert(2, 1, 6);
	g.insert(1, 3, 1);
	g.insert(3, 1, 1);
	g.insert(1, 4, 5);
	g.insert(4, 1, 5);
	g.insert(2, 3, 5);
	g.insert(3, 2, 5);
	g.insert(2, 5, 3);
	g.insert(5, 2, 3);
	g.insert(3, 4, 5);
	g.insert(4, 3, 5);
	g.insert(3, 5, 6);
	g.insert(5, 3, 6);
	g.insert(3, 6, 4);
	g.insert(6, 3, 4);
	g.insert(4, 6, 2);
	g.insert(6, 4, 2);
	g.insert(5, 6, 6);
	g.insert(6, 5, 6);
	g.kruskal();
}


void test_topSort() {
	string array[7] = { "数学", "程序设计", "离散数学", "软件工程", "数据结构", "数据库", "编译原理" };
	adjListGraph<string, int> g(7, array);
	g.insert(array[0], array[1], 1);
	g.insert(array[0], array[2], 1);
	g.insert(array[2], array[4], 1);
	g.insert(array[2], array[6], 1);
	g.insert(array[1], array[4], 1);
	g.insert(array[1], array[5], 1);
	g.insert(array[1], array[3], 1);
	g.insert(array[4], array[5], 1);
	g.insert(array[4], array[6], 1);
	g.insert(array[5], array[3], 1);
	g.topSort();
}

void test_criticalPath() {
	string array[6] = { "v1", "v2", "v3", "v4", "v5", "v6" };
	adjListGraph<string, int> g(6, array);
	g.insert("v1", "v2", 1);
	g.insert("v1", "v3", 3);
	g.insert("v1", "v4", 5);
	g.insert("v2", "v5", 2);
	g.insert("v2", "v3", 1);
	g.insert("v3", "v4", 1);
	g.insert("v3", "v6", 2);
	g.insert("v4", "v5", 1);
	g.insert("v4", "v6", 2);
	g.insert("v5", "v6", 2);
	g.criticalPath();
}

int main()
{
	//test_traverse();
	//test_dijstra();
	//test_prim();
	//test_kruskal();
	//test_topSort();
	test_criticalPath();
	return 0;
}