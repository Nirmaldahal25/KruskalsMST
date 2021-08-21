// CMAKENEW generated file: Sample header file
#ifndef GRAPHS_CLASS 
#define GRAPHS_CLASS

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include <grapheditor.hpp>

namespace quicksort
{
    template<typename T>
    int partition(std::vector<T>& arr, int low, int high)
    {
        auto pivot = arr[high]; 
        int i = (low - 1); 
    
        for (int j = low; j <= high- 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;  
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    template<typename T>
    void sort(std::vector<T>& arr, int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(arr, low, high);
            sort(arr, low, pivot - 1);
            sort(arr, pivot + 1, high);
        }
    }
};

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

    friend bool operator==(const Edges<T>& edge1, const Edges<T>& edge2)
    {
        return edge1.src == edge2.src && edge1.dest == edge2.dest;
    }

    friend bool operator<(const Edges<T>& edge1, const Edges<T>& edge2)
    {
        return edge1.weight < edge2.weight;
    }

    friend bool operator<=(const Edges<T>& edge1, const Edges<T>& edge2)
    {
        return edge1.weight <= edge2.weight;
    }
    
    friend bool operator>=(const Edges<T>& edge1, const Edges<T>& edge2)
    {
        return edge1.weight >= edge2.weight;
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