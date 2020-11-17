#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <vector>
#include <iostream>
using namespace std;

struct Pos{
    int x, y;
    Pos(int x, int y){
        this -> x = x;
        this -> y = y;
    }
	Pos(){
        this -> x = 0;
        this -> y = 0;
    }
};

class MyGraph{
    private:
        int size;
        vector<vector<int> > matriz;
        void DFS( int current, bool* visited );
    public:
        void loadGraph( vector<vector<int> >& matriz );
        void BFS( int starting );
        void DFS( int starting );
        void topologicalSort();
        bool isTree();
        bool bipartiteGraph();
};

#endif