// CMAKENEW generated file: Sample header file
#ifndef GRAPHS_CLASS 
#define GRAPHS_CLASS

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include <grapheditor.hpp>

template <typename T>
struct Edges{
    T src;  
    T dest;
    int weight;

    /* vert1 = source 
    vert2 = destination */
    Edges(T vert1, T vert2, int wt):src(vert1), dest(vert2), weight(wt)
    {

    }

    friend bool operator==(const Edges& edge1, const Edges& edge2)
    {
        return edge1.src == edge2.src && edge1.dest == edge2.dest;
    }
};

template <typename T>
class Graph
{
    public:
        /* add edge from vertex1 to vertex2 with with weight(int)*/
        void addEdge(T vertex, T vertex2, int);

        /* show the spanning tree formed*/ 
        void display();

        /* make a dot text */
        void makeGraph(std::string str);

        /* returns the edges of the minium spanning tree */
        const auto& minimumSpanningTree();

    private:
        std::vector<Edges<T>> graph;
        std::set<T> vertices;
        std::vector<Edges<T>> result;

        //returns the parent of the node
        auto findParent(const T&, std::unordered_map<T,T>& );

        //set parent of parameter 2 to parent of paramter 1 
        void makeUnion(const T&, const T&, std::unordered_map<T,T>&);
};
#include "graphs.tpl"

#endif