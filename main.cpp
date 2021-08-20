#include "graphs.hpp"
#include "grapheditor.hpp"

template <typename T>
void print(Graph<T>& graph)
{
      std::cout<<"node of spanning tree"<<std::endl;
    for(const auto& i: graph.minimumSpanningTree())
    {
        std::cout<<"\t({"<<i.src<<' '<<i.dest<<"},  "<<i.weight<<")\n";
    }
    std::cout<<std::endl;
    std::cout<<"All the Edges of Graph"<<std::endl;
    graph.display();

    std::cout<<"Edges of Spanning Tree Can be Viewed using graphvisual.dot file"<<std::endl;
}

void graph1()
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
    print(graph);
    graph.makeGraph("graph1.dot");
}


void graph2()
{
    Graph<int> graph;
    graph.addEdge(0, 5, 10);
    graph.addEdge(0, 1, 28);
    graph.addEdge(1, 6, 14);
    graph.addEdge(4, 6, 24);
    graph.addEdge(4, 5, 25);
    graph.addEdge(3, 4, 22);
    graph.addEdge(2, 3, 12);
    graph.addEdge(1, 2, 16);
    graph.addEdge(3, 6, 18);
    print(graph);
    graph.makeGraph("graph2.dot");
}


void graph3()
{
    Graph<char> graph;
    graph.addEdge('A', 'F', 10);
    graph.addEdge('A', 'B', 28);
    graph.addEdge('B', 'G', 14);
    graph.addEdge('E', 'G', 24);
    graph.addEdge('E', 'F', 25);
    graph.addEdge('D', 'E', 22);
    graph.addEdge('C', 'D', 12);
    graph.addEdge('B', 'C', 16);
    graph.addEdge('D', 'G', 18);
    print(graph);
    graph.makeGraph("graph3.dot");
}
int main()
{
    graph1();
    // graph2();
    // graph3();
    
   
}