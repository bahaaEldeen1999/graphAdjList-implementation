#pragma once
#include <iostream>
#include "graphsAdjList.h"
using namespace std;
#include  <vector>

template<class t>
class node
{
	template<class t>
	friend class graphsAdjList;
	struct nodeAndWeights;
	vector<nodeAndWeights> neighbours;
	t val;
	int noOfNeighbours;
public:
	node(t val);
	node();
	void addNeighbour(node<t> &n,int w,int ind);
	void printNeighbours();
	vector<node<t>::nodeAndWeights> getNeighbours();
	int getNoOfNeighbours();
	t getVal();
};

template<class t>

node<t>::node(t val) {
	
	this->val = val;

	this->noOfNeighbours = 0;
}
template<class t>

node<t>::node() {
	
	this->val = 0;
	this->noOfNeighbours = 0;
}
template<class t>
 struct node<t>::nodeAndWeights {
	node<t>* n;
	int w;
	int ind;
	nodeAndWeights(node<t>* n, int w,int i) {
		this->w = w;
		this->n = n;
		ind = i;
	}
	nodeAndWeights() {
		this->w = 0;
		this->n = 0;
		ind = 0;
	}
};

template<class t>
 void node<t>::addNeighbour(node<t> &n,int w,int ind)
{

	nodeAndWeights pair(&n,w,ind);
	neighbours.push_back(pair);
	noOfNeighbours++;
}

template<class t>
 void node<t>::printNeighbours()
{
	for (int i = 0; i < noOfNeighbours; i++) {
		cout << "index of node : "<< neighbours[i].ind+1 << " has a value :  " << (neighbours[i].n)->val << " and the weight connected them is "  << neighbours[i].w << endl;
	}
}

 template<class t>
 vector<typename node<t>::nodeAndWeights> node<t>::getNeighbours()
 {
	 return neighbours;
 }

 template<class t>
 inline int node<t>::getNoOfNeighbours()
 {
	 return noOfNeighbours;
 }

 template<class t>
  t node<t>::getVal()
 {
	 return val;
 }
