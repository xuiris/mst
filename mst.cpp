//
//  mst.cpp
//  mst
//
//  Created by Iris Xu on 11/29/17.
//  Copyright © 2017 Iris Xu. All rights reserved.
//

#include "mst.hpp"

Edge::Edge(int f, int t, int c) {
    frm = f;
    to = t;
    cost = c;
}

bool DSet::addnew(int v) {
    if (vertex.count(v) == 0) {
        vertex[v] = v;
        return true;
    }
    else return false;
}

int DSet::find(int x) {
    return vertex[x]; // gives back the "name" of set
}

bool DSet::merge(int x, int y) {
    int n = find(x);
    int p = find(y);
    if (n != p) { // not in same set, can union by putting in same set
        std::map<int, int>::iterator it;
        for(it = vertex.begin(); it != vertex.end(); ++it) {
            if (it->second == n) {
                it->second = p;
            }
        }
        return true;
    }
    else return false; // already in same set, cannot perform union again
}

void Tree::printedges() {
    std::map<int, Edge>::iterator it;
    for(it = graphedges.begin(); it != graphedges.end(); ++it) {
        cout << "(" << it->second.frm << "," << it->second.to << ") ";
    }
    cout << endl;
}

void buildmst(Tree &tr, DSet &ds) {
    // run the rmnedges, union the nodes if possible, add to graphedges
    // delete everything in rmnedges
    // set newedges = false
    std::map<int, Edge>::iterator it;
    for(it = tr.rmnedges.begin(); it != tr.rmnedges.end(); ++it) { // for all rmnedges
        if (ds.merge(it->second.frm, it->second.to)) { // if union is a success
            tr.comp--; // 1 less component bc have connected some edge
            tr.cost += it->first; // increase cost of mst
        }
        tr.graphedges[it->first] = it->second; // to keep track of whats in graph
    }
    tr.rmnedges.clear(); // delete everything, theres nothing else to process
    tr.newedges = false;
}
