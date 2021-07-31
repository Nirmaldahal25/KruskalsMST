#include "graphs.hpp"

/* spanning tree for undirected graph" */
/* supports char and integer values as Nodes */
int main()
{
    Graph<int> graph;
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);
    auto tree = graph.minimumSpanningTree();
    graph.display();
    for(const auto & i: tree)
    {
        std::cout<<i.src<<' '<<i.dest<<'\n';
    }
}