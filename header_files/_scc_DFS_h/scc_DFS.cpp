#include "../_graph_h/graph.h"
#include <vector>
#include <unordered_map>
#include <stack>

std::vector<int> SCCDFS::GetSCC_DFS(Graph &g){
    
    int vertex_count = g.GetVerticesCount();
 
    std::stack<int> stack;  ///< Stores the nodes in the order they are visited while <a href="https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/">Depth First Search</a>
    std::vector<bool> visited(vertex_count,false);
    std::vector<int> scc_nodes; ///< Stores the representative node of <a href="https://www.geeksforgeeks.org/strongly-connected-components/">Strongly Connected Components</a>
    
    for(int node = 0; node < vertex_count; node++ )
        if(visited[node]==false)
            g.FinishOrderDFS(node,visited,stack);

    std::fill(visited.begin(), visited.end(), false);

    while(!stack.empty()){

        int v = stack.top();
        stack.pop();

        if(visited[v] == false){
            scc_nodes.push_back(v);
            g.TransposeBFS(v,visited,false);
        }
    }

    return scc_nodes;
}