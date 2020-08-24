///@file
///Header file containing function to find <a href = "https://www.geeksforgeeks.org/strongly-connected-components/"> Strongly Connected Components</a> in the Graph using <a href= "https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/">Depth First Search</a>(DFS)
# ifndef _scc_DFS_h
# define _scc_DFS_h

#include "../_graph_h/graph.h"
#include <vector>

/// Class representing <a href="https://www.geeksforgeeks.org/strongly-connected-components/">Depth First Search algorithm to find Strongly Connected Component(s)</a> in a digraph.
class SCCDFS {

    public :
        ///Function to find <a href = "https://www.geeksforgeeks.org/strongly-connected-components/"> Strongly Connected Components</a>(SCC) in a Graph using <a href= "https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/">Depth First Search</a>(DFS)
        ///
        ///Visits all the nodes in the Graph and push them into stack in the order they are visited. Then for each node on the top of the stack applies <a href="https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/">Breadth First Search</a>(BFS) on the transpose of the given Graph to find the <a href = "https://www.geeksforgeeks.org/strongly-connected-components/"> Strongly Connected Components</a>.
        ///@param[in] g Graph containing connected components
        ///@param[out] scc_nodes A list contatining representative nodes of <a href = "https://www.geeksforgeeks.org/strongly-connected-components/"> Strongly Connected Components</a> in the Graph
        ///@return A list of vector containing a node of the <a href = "https://www.geeksforgeeks.org/strongly-connected-components/"> Strongly Connected Components</a>(SCC)
        /// #### Time Complexity
        ///@note Time Complexity is 2 * Big 'O' ( V + E ) i.e. Big 'O' ( V + E ), where V,E are vertices and edges in the Graph respectively.
        ///@see Graph::FinishOrderDFS()
        ///@see Graph::TransposeBFS()
        ///@see Graph
        std::vector<int> GetSCC_DFS(Graph &g);
};

# include "scc_DFS.cpp"
# endif

