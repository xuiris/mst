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
using namespace std;

// AN EDGE OBJECT:
struct Edge{
    int frm, to, cost;
    Edge(int f, int t, int c) { frm = f; to = t; cost = c;}
}

// DISJOINT SETS:
struct DSet{
    map<int, int> vertex; // stores all vertexes
    bool addnew(int v); // returns false if vertex was already in set
    int find(int x);
    bool union(int x, int y); // returns true if union occurs
}

// TREE OBJECT:
class Tree{
    public:
        int cost = 0;
        int comp = 0;
        bool cycle = false;
        bool newedges = false;
        map<int, Edge> graphedges;
        map<int, Edge> rmnedges;
        void printedges();
}

void buildmst(Tree tr, DSet d);


#endif /* mst_hpp */
