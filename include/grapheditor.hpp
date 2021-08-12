#pragma once
#include <memory>
#include <string>
struct grapheditor
{
    std::unique_ptr<FILE,int (*)(FILE *) >fp;
    
    grapheditor():fp(NULL,fclose)
    {
    }

    void makeFilepointer(const char* str)
    {
        FILE* file = fopen(str, "w");
        fp.reset(file);

        fprintf(fp.get(),"graph G{\n\tlayout=fdp\n\toverlay = \"compress\" \n\toverlap = \"scalexy\"\n\t");
    }

    void addVertex(const char* vertex)
    {
        fprintf(fp.get(),"%s\n\t",vertex);
    }

    void addEdge(const char* vertex1, const char* vertex2, int weight)
    {
        std::string wt = std::to_string(weight);
        fprintf(fp.get(),"%s -- %s [label = \"%s\"]\n\t",vertex1,vertex2,wt.c_str());
    }

    void close()
    {
        fprintf(fp.get(),"}");
    }

    
};
