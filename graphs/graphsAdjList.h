#pragma once
#include "node.h"
#include <set>
template<typename t>
class graphsAdjList
{
	vector<node<t>> nodes;
	int noOfNodes;
	int currIndex;
public:
	graphsAdjList();
	void addEdge(int n1,int n2,int w = 0); // directed 
	void connectTwoNodes(int n1,int n2,int w = 0); // undirected
	void addNode(node<t> n);
	void print();
	// topology sort
	vector<int> topSort();
	void topSortUtil(int at,vector<bool> &V,vector<int> &visitedNodes);
	// depth first search
	void dfsUtil(int n,vector<bool> &visited);
	void dfs(int node);
	// are the 2 nodes reachable 
	bool areReachable(int n1, int n2);
	bool areReachableUtil(int n1,int n2, vector<bool> &visited,int &x);
	// count number of connected component
	int countConnectedComponents();
	void countConnectedComponents(set<int> &s,int node, vector<bool> &visited);



	
};

template<typename t>
 graphsAdjList<t>::graphsAdjList()
{

	noOfNodes = 0;
	
}

template<typename t>
 void graphsAdjList<t>::addEdge(int n1, int n2, int w)
{
	 n1--;
	 n2--;
	 nodes[n1].addNeighbour(nodes[n2], w,n2);
	
}
 template<typename t>
 void graphsAdjList<t>::connectTwoNodes(int n1, int n2, int w )
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
 }

 template<typename t>
  void graphsAdjList<t>::print()
 {
	 for (int i = 0; i < noOfNodes; i++) {
		 cout << "at node " << i+1 << " it has neighbours " << endl;
			 nodes[i].printNeighbours();
			 
	 }
 }

  template<typename t>
   vector<int> graphsAdjList<t>::topSort()
  {
	   int N = this->noOfNodes;
	   vector<bool> V(N, false);
	   vector<int> ordering(N,0);
	   int i = N - 1;
	   for (int at = 0; at < N; at++) {
		   if (!V[at]) {
			   vector<int> visitedNodes;
			   topSortUtil(at, V, visitedNodes);
			   for (int j = 0; j < visitedNodes.size(); j++) {
				   ordering[i] = visitedNodes[j];
				   i = i - 1;
			   }
		   }
	   }
	   return ordering;
  }

   template<typename t>
   inline void graphsAdjList<t>::topSortUtil(int at,vector<bool> &V, vector<int>& visitedNodes)
   {
	   V[at] = true;
	   vector<node<t>::nodeAndWeights> edges = nodes[at].getNeighbours();
	   for (int j = 0; j < edges.size(); j++) {
		   if (!V[edges[j].ind]) {
			   topSortUtil(edges[j].ind, V, visitedNodes);
		   }
	   }
	   visitedNodes.push_back(at);
   }
   template<typename t>
   void graphsAdjList<t>::dfsUtil(int n, vector<bool>& visited)
   {

	   visited[n] = true;
	   cout << "node with index " << n + 1 << " with value " << nodes[n].getVal() << endl;
	  
	  
	   vector<node<t>::nodeAndWeights> edges = nodes[n].getNeighbours();

	   for (int i = 0; i < edges.size(); i++) {
		  if (!visited[edges[i].ind]) {
			   dfsUtil(edges[i].ind, visited);
		   }
	 }
   }

	template<typename t>
	 void graphsAdjList<t>::dfs(int node)
	{
		 vector<bool> visited(noOfNodes,0);
		 node--;
		 dfsUtil(node, visited);
	}

	 template<typename t>
	 bool graphsAdjList<t>::areReachable(int n1, int n2)
	 {
		 vector<bool> visited(noOfNodes, 0);
		 n1--;
		 n2--;
		 int x = 0;
		 return areReachableUtil(n1, n2, visited, x);

		  
	 }

	 template<typename t>
	 bool graphsAdjList<t>::areReachableUtil(int n1, int n2, vector<bool>& visited,int &x)
	 {
		 visited[n1] = true;
		
		 if ( n1 == n2 ) {
			 
			 x = 1;
		 }


		 vector<node<t>::nodeAndWeights> edges = nodes[n1].getNeighbours();

		 for (int i = 0; i < edges.size(); i++) {
			 if (!visited[edges[i].ind] && !x) {
				 areReachableUtil(edges[i].ind,n2, visited,x);
			 }
		 }
		 return x;

	 }

	 template<typename t>
	  int graphsAdjList<t>::countConnectedComponents()
	 {
		  int x = 0;
		  set<int> s;
		  vector<bool> v(noOfNodes, false);
		  for (int i = 0; i < nodes.size(); i++) {
			  if (s.insert(i).second) {
				  x++;
				  countConnectedComponents(s,i,v);
			  }
		  }
		 return x;
	 }

	 template<typename t>
	  void graphsAdjList<t>::countConnectedComponents(set<int> &s,int n, vector<bool> &visited)
	 {
		  visited[n] = true;
		  vector<node<t>::nodeAndWeights> edges = nodes[n].getNeighbours();
		  for (int i = 0; i < edges.size(); i++) {
			  if (!visited[edges[i].ind]) {
				  s.insert(edges[i].ind);
				  countConnectedComponents(s,edges[i].ind, visited);
			  }
		  }
	 }


	
