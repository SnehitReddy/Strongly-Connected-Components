#include "../header_files/_graph_h/graph.h"
#include "../header_files/_scc_DFS_h/scc_DFS.h"
#include "../header_files/_scc_DCSC_h/scc_DCSC.h"
#include "../header_files/_timer_h/timer.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>

#define PATH "../visualization/saved_data/"

// void SaveToFile(std::vector<int> &data,std::string filename="SCCs_node_DFS.txt"){

//     std::ofstream fout;
//     fout.open(PATH+filename);
//     for(auto x: data)
//         fout<<x<<" ";
//     fout<<"\n";
//     fout.close();

// }

int main()
{

    Graph g;
    ExecutionTime t;
    SCCDC sccdc;
    SCCDFS sccdfs;

    std::string filename;
    printf("\nDAA(CS F364) Assignment-1\n\nEnter the filename with graph : ");
    getline(std::cin, filename);

    std::ifstream fin;
    fin.open(filename);

    if (fin.is_open())
    {
        printf("\nConstructing the graph...........\n\n");

        std::string S, T, u, v;
        int num_nodes, num_edges;
        fin>>num_nodes>>num_edges;
        getline(fin,S);
        while (getline(fin, S))
        {
            std::stringstream X(S);
            X >> u >> v;
            if (!g.NodeMapStatus(u))
            {
                g.MapNode(u);
            }
            if (!g.NodeMapStatus(v))
            {
                g.MapNode(v);
            }
            g.AddEdge(g.GetMappedNodeValue(u), g.GetMappedNodeValue(v));
        }

        fin.close();
        int num_nodes_connected = g.GetVerticesCount();
        for(int num = num_nodes_connected; num < num_nodes; num ++){
            g.AddVertex();
        }
        
        std::cout << "Graph constructed successfully !! :)\n\nGraph information :\n\n";
        printf("\tNumber of vertices = %d\n", g.GetVerticesCount());
        printf("\tNumber of edges = %d\n\n", g.GetEdgesCount());

        char save = 'n';
        printf("Do you want to save data for visualization (it will effect the running time of the program). Default value is 'n'? (y/n) : ");
        scanf("%c",save);
        printf("\n\n");
        if(save == 'y' || save == 'Y')
            sccdc.kSaveResult = true;
        else if(save == 'n' || save == 'N')
            sccdc.kSaveResult = false;
        else
            printf("Considering the default value.\n\n");

        // printf("\tWriting to File\n\n");
        if(sccdc.kSaveResult){
            std::ofstream outfile;
            std::string outname = "../visualization/out_test_graphs/visgraph.txt";
            outfile.open(outname);
            outfile << g.GetVerticesCount() << "\n";
            outfile << g.GetEdgesCount() << "\n";
            for (int i=0; i< g.GetVerticesCount(); i++){
                auto vec = g.GetForwardAdjList(i);
                for(auto& e : vec){
                    outfile << i<<" "<<e<<"\n";
                }
            }
        }
        // printf("\tDone Writing\n\n");
        
        printf(">>> Applying DFS to find strongly connected components in the graph...............\n\n");

        t.StartTimer();
            auto scc_DFS_nodes = sccdfs.GetSCC_DFS(g);
        t.StopTimer();

        printf("\tExecution Time using DFS (microsec) : %lld\n",t.CalculateExecutionTime());
        printf("\tTotal number of strongly connected components found = %llu\n\n\n",scc_DFS_nodes.size());
        // g.PrintSCCs(scc_DFS_nodes);
        // SaveToFile(scc_DFS_nodes);

        printf(">>> Applying DCSC to find strongly connected components in the graph...............\n\n");

        t.StartTimer();
            auto scc_DCSC_nodes = sccdc.GetSCCDC(g);
        t.StopTimer();

        printf("\tExecution Time using DCSC (microsec) : %lld\n",t.CalculateExecutionTime());
        printf("\tTotal number of strongly connected components found = %llu\n\n\n",scc_DCSC_nodes.size());
        // g.PrintSCCs(scc_DCSC_nodes);
    }
    else
    {
        std::cout << "Unable to open the file\n\n";
    }

    return 0;
}