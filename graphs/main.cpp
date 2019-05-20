#include <iostream>
using namespace std;
#include "graphsAdjList.h"


int main() {
	graphsAdjList<int> g;
	/*
	g.addNode(node<int>(1));
	g.addNode(node<int>(2));
	g.addNode(node<int>(3));
	g.addNode(node<int>(4));
	g.addNode(node<int>(5));
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.addEdge(1,5);
	g.dfs(1);
	*/
	/*
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		g.addNode(node<int>(i));

	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g.connectTwoNodes(x, y);
	}
	//int u, v;
	//cin >> u >> v;
	//cout << "result " << g.areReachable(u, v) << endl;
	*/
	g.addNode(node<int>(1));
	g.addNode(node<int>(2));
	g.addNode(node<int>(3));
	g.addNode(node<int>(4));
	g.addNode(node<int>(5));
	g.connectTwoNodes(2,1);
	g.connectTwoNodes(3,4);
	g.connectTwoNodes(4,5);
	cout << "connected components " << g.countConnectedComponents() << endl;
	int x;
	cin >> x;
	return  0;
}



