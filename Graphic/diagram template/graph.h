#pragma once
#ifndef GRAPH
#define GRAPH
#include <iostream>
using namespace std;

/*图的抽象类*/
template <class TypeOfVer, class TypeOfEdge>
class graph {
protected:
	int Vers;
	int Edges;

public:
	virtual void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) = 0;
	virtual void remove(TypeOfVer x, TypeOfVer y) = 0;
	virtual bool exist(TypeOfVer x, TypeOfVer y) const = 0; //判断两个顶点是否存在边
	int numOfVer() const { return this->Vers; }
	int numOfEdge() const { return this->Edges; }
};

#endif