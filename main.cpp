//
//  prog2.cpp
//  mst
//
//  Created by Iris Xu on 11/29/17.
//  Copyright © 2017 Iris Xu. All rights reserved.
//

#include <stdio.h>
#include <sstream>
#include "mst.hpp"

int main(int argc, char* argv[]) {
    Tree mst; // holds the edge elements and other info about the tree
    DSet ds; // this disjoint set allows us to "connect" vertices and detect cycles
    string line;
    string command;
    int f, t, c;
    string sf, st, sc;
    do {
        getline(cin, line);
        istringstream iss(line);
        iss >> command;
        // TAKING IN NEW EDGES:
        if (command == "BID") {
                // take in values from input, convert to int and store
                iss >> sf >> st >> sc;
                f = stoi(sf);
                t = stoi(st);
                c = stoi(sc);
                // create edge object
                Edge e(f, t, c);
                // alter the tree
                mst.rmnedges[c] = e; // add to rmnedges in mst
                mst.newedges = true; // so we know we must rerun kruskals if queried
                // add vertexes to disj set:
                ds.addnew(f);
                ds.addnew(t);
                if (ds.find(f) != ds.find(t)) {
                    mst.comp++; // only increase if adding an edge that wouldn't be creating cycle
                }
        }
        if (command == "MANDATORY") {
                iss >> sf >> st >> sc;
                f = stoi(sf);
                t = stoi(st);
                c = stoi(sc);
                Edge e(f, t, c);
                ds.addnew(f);
                ds.addnew(t);
                if (!(ds.merge(f,t))) { // tells us we created a cycle
                    ds.merge(f,t);
                    mst.cycle = true;
                }
                else {
                    mst.comp++;
                }
                mst.cost += c; // add edge cost
                mst.graphedges[c] = e; // to keep track of what is in mst
                mst.newedges = true; // so we know we must rerun kruskals if queried
        }
        if (command == "COST?") {
                if (mst.newedges == true) {
                    buildmst(mst, ds);
                }
                cout <<  mst.cost << endl;
        }
        if (command == "COMPONENTS?") {
                if (mst.newedges == true) {
                    buildmst(mst, ds);
                }
                cout <<  mst.comp << endl;
        }
        if (command == "CYCLE?") {
                if (mst.newedges == true) {
                    buildmst(mst, ds);
                }
                switch(mst.cycle) {
                    case 0:
                        cout << "NO" << endl;
                        break;
                    case 1: 
                        cout << "YES" << endl;
                        break;
                }
        }
        if (command == "LIST?") {
                if (mst.newedges == true) {
                    buildmst(mst, ds);
                }
                mst.printedges();
        }
    } while(command != "END");
    return 0;
}
    
