#pragma once
#include "node.h"

template<typename t>
class graphsAdjList
{
	vector<node<t>> nodes;
	int noOfNodes;
	int currIndex;
public:
	graphsAdjList();
	void depthFirstTraverseUtil(node<t> n, vector<bool> &visited);
	void depthFirstTraverse();
	void connectNodes(int n1,int n2,int w);
	void addNode(node<t> n);
	void print();
	
};

template<typename t>
 graphsAdjList<t>::graphsAdjList()
{
	//nodes = new node<t>[n];
	//for (int i = 0; i < n; i++) {
	//	nodes[i] = NULL;
	//}
	noOfNodes = 0;
	//currIndex = 0;
}

template<typename t>
 void graphsAdjList<t>::connectNodes(int n1, int n2, int w)
{
	 n1--;
	 n2--;
	
	 nodes[n1].addNeighbour(nodes[n2], w,n2);
	 nodes[n2].addNeighbour(nodes[n1], w,n1);
}

 template<typename t>
 void graphsAdjList<t>::addNode(node<t> n)
 {
	 nodes.push_back(n);
	 noOfNodes++;
	// currIndex++;
	// if (currIndex == noOfNodes) currIndex--;
 }

 template<typename t>
  void graphsAdjList<t>::print()
 {
	 for (int i = 0; i < noOfNodes; i++) {
		 cout << "at node " << i + 1 << " it has neighbours " << endl;
			 nodes[i].printNeighbours();
			 
	 }
 }

 template<typename t>
 void graphsAdjList<t>::depthFirstTraverseUtil(node<t> n, vector<bool> &visited)
 {
	 if (n.getNoOfNeighbours() == 0) {
		 return;
	 }
	 
	 for (int i = 0; i < n.getNoOfNeighbours(); i++) {
		 if (!visited[n.getNeighbours()[i].ind]) {
			 cout << n.getNeighbours()[i].n->val << endl;
			 visited[visited[n.getNeighbours()[i].ind]] = 1;
		 }
	 }
	 return;
	// if (x == n.getNoOfNeighbours()) return;
	 vector< node<t>::nodeAndWeights > ne = n.getNeighbours();
	 for (int i = 0; i < n.getNoOfNeighbours(); i++) {
		 int curr = ne[i].ind;
		 if (!visited[curr]) {
			 cout << ne[i].n->val << endl;
			 visited[curr] = 1;
		 }
		 depthFirstTraverseUtil(*(ne[i].n),visited);
	 }
	

 }

 template<typename t>
 inline void graphsAdjList<t>::depthFirstTraverse()
 {
	
	 vector<bool> visited(noOfNodes);
	 depthFirstTraverseUtil(nodes[0],visited);
 }
