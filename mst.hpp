//
//  mst.hpp
//  mst
//
//  Created by Iris Xu on 11/29/17.
//  Copyright © 2017 Iris Xu. All rights reserved.
//

#ifndef mst_hpp
#define mst_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
using namespace std;

// AN EDGE OBJECT:
struct Edge{
    int frm, to, cost; // from vertex, to vertex, cost of edge between 
    Edge(int f = 0, int t = 0, int = 0);
};

// DISJOINT SETS:
struct DSet{
    map<int, int> vertex; // stores all vertexes, 1st int: vertex, 2nd int: set it belongs to
    bool addnew(int v); // returns false if vertex was already in set
    int find(int x); // return the set the vertex "x" is in
    bool merge(int x, int y); // place vertices in same set, returns true if union occurs
    int numsets(); // gives the # of distinct sets in the disjoint set
};

// TREE OBJECT:
struct Tree{
    int cost = 0;
    int comp = 0;
    bool cycle = false; // cycle in the tree
    bool newedges = false; // tells us there are new edges passed in from user
    map<int, Edge> graphedges; // <cost, edge>, edges actually in the tree
    map<int, Edge> rmnedges; // <cost, edge>, new edges passed in, needs to be processed
    void printedges(); // lists the edges in the tree graph
};

void buildmst(Tree &tr, DSet &d); // this runs Kruskal's algorithm to build mst using the rmnedges


#endif /* mst_hpp */
