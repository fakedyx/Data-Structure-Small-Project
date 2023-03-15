#pragma once
/*
 * @Descripttion:
 * @version:
 * @Author: faker
 * @Date: 2022-10-07 15:52:49
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-10-08 09:53:46
 */

#ifndef ADJLISTGRAPH

#define ADJLISTGRAPH
#include <iostream>
#include "graph.h"
#include "disjointedSet.h"
#include <queue>
using namespace std;

template <class TypeOfVer, class TypeOfEdge>
class adjListGraph : public graph<TypeOfVer, TypeOfEdge> {
public:
	adjListGraph(int vSize, const TypeOfVer d[]);
	virtual void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
	virtual void remove(TypeOfVer x, TypeOfVer y);
	virtual bool exist(TypeOfVer x, TypeOfVer y) const;
	~adjListGraph();

	void bfs() const;
	void dfs() const;
	void dfs(int i, bool visited[]) const;
	//void floyd() const;  邻接矩阵存储的图
	void dijstra(TypeOfVer start, TypeOfEdge noEdge) const;
	void printPath(int startNum, int endNum, int* prev) const;


	void prim(TypeOfEdge noEdge) const;  //选顶点--子图时刻连通
	void kruskal() const;				 //选边

	void topSort() const;
	void criticalPath() const;

private:
	struct edgeNode {
		int end;  //终点编号
		TypeOfEdge weight;  //边的权值
		edgeNode* next;

		edgeNode(int e, TypeOfEdge w, edgeNode* n = NULL) {
			end = e; weight = w; next = n;
		}
	};

	struct verNode {
		TypeOfVer ver;  //顶点值
		edgeNode* head; //对应单链表的头指针

		verNode(edgeNode* h = NULL) { head = h; }
	};

	/*仅在kruskal算法中使用*/
	struct edge {
		int beg, end;
		TypeOfEdge w;
		//将小的往上放
		bool operator<(const edge& rp) const { return w > rp.w; }
	};


	verNode* verList;

	int find(TypeOfVer v)const {
		for (int i = 0; i < this->Vers; ++i) {
			if (verList[i].ver == v) return i;
		}
	}
};






template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::printPath(int startNum, int endNum, int* prev) const {
	/*打印第一个点*/
	if (startNum == endNum) {
		cout << verList[startNum].ver;
		return;
	}
	//回溯
	//加判断？
	if (endNum > this->Vers || endNum < 0) return;
	printPath(startNum, prev[endNum], prev);
	cout << '-' << verList[endNum].ver;
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::prim(TypeOfEdge noEdge) const {
	bool* flag = new bool[this->Vers];
	TypeOfEdge* lowCost = new TypeOfEdge[this->Vers];
	int* startNode = new int[this->Vers];

	//初始化--刚开始所有结点都不在生成树中
	for (int i = 0; i < this->Vers; ++i) {
		flag[i] = false;
		lowCost[i] = noEdge;
	}

	int start = 0;  //将0结点作为开始结点放入生成树
	for (int i = 1; i < this->Vers; ++i) {
		for (edgeNode* p = verList[start].head; p != NULL; p = p->next) {
			//更新距离信息
			if (!flag[p->end] && lowCost[p->end] > p->weight) {
				lowCost[p->end] = p->weight;
				startNode[p->end] = start;
			}
		}

		flag[start] = true;
		int min = noEdge;
		for (int j = 0; j < this->Vers; ++j) {
			//寻找U到V-U的最小权值边
			if (lowCost[j] < min) {
				min = lowCost[j];
				start = j;
			}
		}
		cout << '(' << verList[startNode[start]].ver << ',' << verList[start].ver << ")\t";
		lowCost[start] = noEdge;
	}


	delete[] flag;
	delete[] lowCost;
	delete[] startNode;
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::kruskal() const {
	disjointedSet ds(this->Vers);
	priority_queue<edge> pq;
	edge e;

	//生成优先级队列 -- 自动排序
	for (int i = 0; i < this->Vers; ++i) {
		for (edgeNode* p = verList[i].head; p != NULL; p = p->next) {
			if (i < p->end) {
				e.beg = i;
				e.end = p->end;
				e.w = p->weight;
				pq.push(e);
			}
		}
	}

	int edgesAccepted = 0;
	int u, v;
	//开始归并
	while (edgesAccepted < this->Vers - 1) {
		e = pq.top(); //取出权值最小的边
		pq.pop();
		u = ds.Find(e.beg); v = ds.Find(e.end);
		if (u != v) {
			/*加入(u,v)不会成环*/
			edgesAccepted++;
			ds.Union(u, v);
			cout << "(" << verList[e.beg].ver << ',' << verList[e.end].ver << ")\t";
		}
	}
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::topSort() const {
	queue<int> q;
	int* inDegree = new int[this->Vers];

	/*计算每个点的入度*/
	for (int i = 0; i < this->Vers; ++i) {
		inDegree[i] = 0;
		for (edgeNode* p = verList[i].head; p != NULL; p = p->next) {
			++inDegree[p->end];
			//不是++inDegree[i] 出度
		}
	}

	/*入度为0的点入队*/
	for (int i = 0; i < this->Vers; ++i) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	int currentNode;
	cout << "拓扑排序序列为:" << endl;
	while (!q.empty()) {
		currentNode = q.front();
		q.pop();
		cout << verList[currentNode].ver << ' ';
		for (edgeNode* p = verList[currentNode].head; p != NULL; p = p->next) {
			if (--inDegree[p->end] == 0) {
				/*与currentNode相邻结点的入度减1，如果度为0，入队*/
				q.push(p->end);
			}
		}
	}
	cout << endl;
	delete[] inDegree;
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::criticalPath() const {
	TypeOfEdge* ee = new TypeOfEdge[this->Vers]; //记录最早发生时间
	TypeOfEdge* le = new TypeOfEdge[this->Vers]; //记录最迟发生时间
	int* top = new int[this->Vers];		//保存拓扑序列
	int* inDegree = new int[this->Vers];
	queue<int> q;

	//找出拓扑序列
	for (int i = 0; i < this->Vers; ++i) {
		inDegree[i] = 0;
		for (edgeNode* p = verList[i].head; p != NULL; p = p->next) {
			++inDegree[p->end];
		}
	}

	//将入度为0的结点入队
	for (int i = 0; i < this->Vers; ++i) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	int i = 0;
	while (!q.empty()) {
		top[i] = q.front();
		q.pop();
		for (edgeNode* p = verList[top[i]].head; p != NULL; p = p->next) {
			if (--inDegree[p->end] == 0) {
				q.push(p->end);
			}
		}
		++i;  //为了记录top序列
	}

	//找出最早发生时间
	for (int i = 0; i < this->Vers; ++i) {
		ee[i] = 0;
	}
	for (int i = 0; i < this->Vers; ++i) {
		for (edgeNode* p = verList[top[i]].head; p != NULL; p = p->next) {
			if (ee[p->end] < ee[top[i]] + p->weight) {
				ee[p->end] = ee[top[i]] + p->weight;
			}
		}
	}

	//找出最晚发生时间
	for (int i = 0; i < this->Vers; ++i) {
		le[i] = ee[this->Vers - 1];
	}
	for (int i = this->Vers - 1; i >= 0; --i) {
		for (edgeNode* p = verList[top[i]].head; p != NULL; p = p->next) {
			if (le[p->end] - p->weight < le[top[i]]) {
				le[top[i]] = le[p->end] - p->weight;
			}
		}
	}

	//找出关键路径
	for (int i = 0; i < this->Vers; ++i) {
		if (le[top[i]] == ee[top[i]]) {
			cout << '(' << verList[top[i]].ver << ',' << ee[top[i]] << ")\t";
		}
	}
}

template <class TypeOfVer, class TypeOfEdge>
void  adjListGraph<TypeOfVer, TypeOfEdge>::dijstra(TypeOfVer start, TypeOfEdge noEdge) const {
	TypeOfEdge* distance = new TypeOfEdge[this->Vers];
	int* prev = new int[this->Vers];
	bool* known = new bool[this->Vers];

	//初始化
	for (int i = 0; i < this->Vers; ++i) {
		distance[i] = noEdge;
		known[i] = false;
	}

	int startNum = find(start);

	distance[startNum] = 0; //设置源点路径为0
	prev[startNum] = startNum;


	int u;
	for (int i = 1; i < this->Vers; ++i) {
		/*寻找具有最短路径的结点*/
		int min = noEdge;
		for (int j = 0; j < this->Vers; ++j) {
			if (!known[j] && distance[j] < min) {
				min = distance[j];
				u = j;
			}
			known[u] = true;
		}

		for (edgeNode* p = verList[u].head; p != NULL; p = p->next) {
			//更新u的临近结点
			if (!known[p->end] && distance[p->end] > min + p->weight) {
				distance[p->end] = min + p->weight;
				prev[p->end] = u;
			}
		}
	}

	for (int i = 0; i < this->Vers; ++i) {
		/*输出*/
		cout << "从" << start << "到" << verList[i].ver << "的路径为:" << endl;
		printPath(startNum, i, prev);
		/*如果没有路径，不用在输出长度*/
		if (distance[i] != noEdge)
			cout << "\t长度为:" << distance[i];
		cout << endl;
	}

	delete[]distance;
	delete[]prev;
	delete[]known;
}

/*
//采用邻接矩阵做比较好
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::floyd() const{
	TypeOfEdge** d = new TypeOfEdge*[Vers];
	int** prev = new int*[Vers];	//prev[i][j]表示从i到j的最短路径需要经过的前一个点

	//初始化
	for(int i = 0; i < Vers; ++i){
		d[i] = new TypeOfEdge[Vers];
		prev[i] = new int[Vers];
		for(int j = 0; j < Vers; ++j){
			d[i][j] = edges[i][j];
			prev[i][j] = (edges[i][j] == noEdge) ? -1 : i;
		}
	}

	//迭代过程
	for(int k = 0; k < Vers; ++k){
		for(int i = 0; i < Vers; ++i){
			for(int j = 0; j < Vers; ++j){
				if(d[j][k] + d[k][i] < d[i][j]){
					d[i][j] = d[j][k] + d[k][i];
					prev[i][j] = prev[k][j];
				}
			}
		}
	}

	//输出
	cout << "最短路径长度:" << endl;
	for(int i = 0; i < Vers; ++i){
		cout << endl;
		for(int j = 0; j < Vers; ++j)
			cout << d[i][j] << '\t';
	}

	cout << "最短路径:" << endl;
	for(int i = 0; i < Vers; ++i){
		cout << endl;
		for(int j = 0; j < Vers; ++j)
			cout << prev[i][j] << '\t';
	}
}
*/


template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vSize, const TypeOfVer d[]) {
	this->Vers = vSize; this->Edges = 0;  //抽象类中继承

	verList = new verNode[vSize];
	for (int i = 0; i < this->Vers; ++i) {
		verList[i].ver = d[i];
	}
}


template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph() {
	edgeNode* p;

	for (int i = 0; i < this->Vers; ++i) {
		while ((p = verList[i].head) != NULL) {
			/*释放第i个结点的单链表*/
			verList[i].head = p->next;
			delete p;
		}
	}

	delete[] verList;
}


template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) {
	int u = find(x), v = find(y);
	verList[u].head = new edgeNode(v, w, verList[u].head);
	++this->Edges;
}


template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::remove(TypeOfVer x, TypeOfVer y) {
	int u = find(x), v = find(y);
	edgeNode* p = verList[u].head, * q;

	if (p == NULL) return;

	if (p->end == v) {
		/*头结点就是被删除的边*/
		verList[u].head = p->next;
		delete p;
		--this->Edges;
		return;
	}

	while (p->next != NULL && p->next->end != v) p = p->next;
	if (p->next != NULL) {
		q = p->next;   //记录要删除的结点
		p->next = q->next;
		delete p;
		--this->Edges;
	}

}





template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x, TypeOfVer y) const {
	int u = find(x), v = find(y);
	edgeNode* p = verList[u].head;

	while (p != NULL && p->end != v) {
		p = p->next;
	}
	return p == NULL ? false : true;
}


template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs() const {
	bool* visited = new bool[this->Vers];
	int currentNode;

	queue<int> q;
	edgeNode* p;

	for (int i = 0; i < this->Vers; ++i) visited[i] = false;

	for (int i = 0; i < this->Vers; ++i) {
		if (visited[i]) continue;
		q.push(i);
		while (!q.empty()) {
			currentNode = q.front();
			q.pop();
			if (visited[currentNode]) continue;
			cout << verList[currentNode].ver << "->";
			visited[currentNode] = true;
			p = verList[currentNode].head;
			while (p != NULL) {
				if (!visited[p->end])q.push(p->end);
				p = p->next;
			}
		}
		cout << endl;
	}
}



template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const {
	bool* visited = new bool[this->Vers];

	for (int i = 0; i < this->Vers; ++i) {
		visited[i] = false;
	}

	for (int i = 0; i < this->Vers; ++i) {
		if (!visited[i]) {
			dfs(i, visited);
		}
	}
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int i, bool visited[]) const {
	edgeNode* p = verList[i].head;

	if (visited[i]) return;
	cout << verList[i].ver << "->";
	visited[i] = true;

	while (p != NULL) {
		if (visited[p->end] == false) dfs(p->end, visited);
		p = p->next;
	}
}

#endif