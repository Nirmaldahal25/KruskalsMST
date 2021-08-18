template <typename T>
void Graph<T>::addEdge(T vertex1, T vertex2, int weight)
{
    this->vertices.insert(vertex1);
    this->vertices.insert(vertex2);
    this->graph.emplace_back(Edges<T>(vertex1,vertex2, weight));
}

template <typename T>
void Graph<T>::display()
{
    for(const auto& i: graph)
    {
        std::cout<<"\t({"<<i.src<<' '<<i.dest<<"},  "<<i.weight<<")\n";
    }
    std::cout<<std::endl;
}

template <typename T>
const auto& Graph<T>::minimumSpanningTree()
{
    std::sort(this->graph.begin(),this->graph.end(),[](auto edge1, auto edge2)->bool{
        return edge1.weight < edge2.weight;
    });
    result.reserve(vertices.size()-1);
    std::unordered_map<T,T> parent;
    for(auto i : vertices)
    {
        parent.insert(std::make_pair<T,T>(std::move(i),std::move(i)));
    }
    for(const auto& i: this->graph)
    {   
        auto a = findParent(i.src,parent);
        auto b = findParent(i.dest,parent);
        if(a != b)  // if the parent of a and b is same(is a cycle) discard
        {
            result.push_back(i);
            this->makeUnion(a,b,parent);
        }
    }
    return result;
}

template <typename T>
auto Graph<T>::findParent(const T& a, std::unordered_map<T,T>& parent)
{
    if(a == parent[a])
    {
        return a;
    }
    else{
        parent[a] = findParent(parent[a], parent);
    }
    return parent[a];
}


template <typename T>
void Graph<T>::makeUnion(const T& a, const T& b, std::unordered_map<T,T>& parent)
{
    parent[a] = parent[b];
}

template <typename T>
void Graph<T>::makeGraph()
{
    grapheditor edit;
    edit.makeFilepointer("graphvisual.dot");
    for(auto&i : result)
    {
        edit.addEdge(std::to_string(i.src).c_str(),std::to_string(i.dest).c_str(),i.weight);
    }
    for(auto& i : vertices)
    {
        edit.addVertex(std::to_string(i).c_str());
    }
    edit.close();
}
