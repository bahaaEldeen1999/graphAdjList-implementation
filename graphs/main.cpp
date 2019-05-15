#include <iostream>
using namespace std;
#include "graphsAdjList.h"


int main() {
	graphsAdjList<int> g;
	g.addNode(node<int>(1));
	g.addNode(node<int>(2));
	g.addNode(node<int>(3));
	g.addNode(node<int>(4));
	g.addNode(node<int>(5));
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.addEdge(1,5);
	//g.addEdge(1,2);
	vector<int> ord;
	ord = g.topSort();
	for (int i = 0; i < ord.size(); i++) {
		cout << ord[i]+1 << endl;
	}
	int x;
	cin >> x;
	return  0;
}



