#include <iostream>
using namespace std;
#include "graphsAdjList.h"
int main() {
	graphsAdjList<int> g;
	g.addNode(node<int>(10));
	g.addNode(node<int>(100));
	g.addNode(node<int>(1000));
	g.addNode(node<int>(10000));
	g.addNode(node<int>(100000));
	g.addNode(node<int>(53));
	g.addNode(node<int>(14));
	g.connectNodes(1,2,0);
	g.connectNodes(1,3,0);
	g.connectNodes(1,4,9);
	g.connectNodes(1,5,8);
	g.connectNodes(3,2,7);
	g.connectNodes(6,2,6);
	g.connectNodes(7,4,4);
	g.print();
	int x;
	cin >> x;
	return  0;
}