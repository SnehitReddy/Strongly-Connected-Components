#ifndef _graph_h
#define _graph_h

#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
#include <queue>

/// Class to handle Graph related operations in the program.
class Graph{

    public:

        ///Function to add vertex into the Graph.
        void AddVertex();

        ///Function to add edges into the Graph.
        ///
        ///@param[in] u,v vertices containing a edge
        ///@see AddVertex()
        void AddEdge(int u, int v);

        ///Function to get children of a node from adjacency list representation of the Graph.
        ///
        ///@param[in] v vertex in the Graph
        ///@see GetBackAdjList()
        ///@see forward_adj_list
        std::vector<int> GetForwardAdjList(int &v);

        ///Function to get children of a node from adjacency list representation of the tranposed Graph.
        ///
        ///@param[in] v vertex in the Graph
        ///@see GetForwardAdjList()
        ///@see back_adj_list
        std::vector<int> GetBackAdjList(int &v);

        ///Function to get the number of vertices in the Graph.
        int GetVerticesCount();

        ///Function to get the number of edges in the Graph.
        int GetEdgesCount();

        ///Function to traverse Graph using Depth First Search (DFS) and store in the stack in the order they are visited.
        ///
        ///@param[in] node Vertex to begin traversal from.
        ///@param[in] visited Tracks the visited node while traversal of the Graph.
        ///@param[out] stack Stack to store the vertex in the order they are visited.
        /// #### Time Complexity
        ///@note Time Complexity is 2 * Big 'O' ( V + E ) i.e. Big 'O' ( V + E ), where V,E are vertices and edges in the Graph respectively.
        ///@see Graph::GetForwardAdjList()
        ///@see Graph
        void FinishOrderDFS(int node, std::vector<bool> &visited, std::stack<int> &stack);

        ///Function to traverse tranposed Graph using Breadth First Search (BFS).
        ///
        ///@param[in] node Vertex to begin traversal from.
        ///@param[in] visited Tracks the visited node while traversal of the Graph.
        ///@param[in] print Boolean value to control printing of the node while traversing.
        /// #### Time Complexity
        ///@note Time Complexity is 2 * Big 'O' ( V + E ) i.e. Big 'O' ( V + E ), where V,E are vertices and edges in the Graph respectively.
        ///@see Graph::GetBackAdjList()
        ///@see Graph
        void TransposeBFS(int node, std::vector<bool> &visited,bool print);

        ///Function to store the predecessor nodes for a node.
        ///
        ///@param[in] v Vertex to find predecessor vertices of.
        ///@param[out] nodes Set to store the predecessor vertices.
        /// #### Time Complexity
        ///@note Time Complexity is 2 * Big 'O' ( V + E ) i.e. Big 'O' ( V + E ), where V,E are vertices and edges in the Graph respectively.
        ///@see back_adj_list
        std::unordered_set<int> GetPredecessors(int &v, std::unordered_set<int> &nodes);

        ///Function to store the descendants nodes for a node.
        ///
        ///@param[in] v Vertex to find descendants vertices of.
        ///@param[out] nodes Set to store the descendants vertices.
        /// #### Time Complexity
        ///@note Time Complexity is 2 * Big 'O' ( V + E ) i.e. Big 'O' ( V + E ), where V,E are vertices and edges in the Graph respectively.
        ///@see forward_adj_list
        std::unordered_set<int> GetDescendants(int &v, std::unordered_set<int> &nodes);

        bool EdgeEmpty(std::unordered_set<int> &nodes);

        ///Function to get the mapped value of the vertex in the Graph.
        ///
        ///@param[in] v Original value of the vertex present in the Graph.
        ///@return Mapped value in range [0,V) of the given node.
        ///@see Graph::AddVertex(), Graph::AddEdge(), Graph::NodeMapStatus(), Graph::MapNode()
        int GetMappedNodeValue(std::string v);

        ///Function to get the original value of the vertex in the Graph.
        ///
        ///@param[in] v Mapped value of the vertex present in the Graph.
        ///@return Original value of the given node (in range [0,V)).
        ///@see Graph::AddVertex(), Graph::AddEdge(), Graph::NodeMapStatus(), Graph::MapNode()
        std::string GetOriginalNodeValue(int v);

        ///Function to map given node value to a value in range [0,V).
        ///
        ///@param[in] v Original value of the vertex to be added in the Graph.
        ///@see Graph::AddVertex(), Graph::AddEdge(), Graph::NodeMapStatus(), Graph::GetMappedNodeValue(), 
        void MapNode(std::string v);

        ///Function to check the whether a given node value is mapped to a value in range [0,V).
        ///
        ///@param[in] v Original value of the vertex to be added or present in the Graph.
        ///@return True/False after verifyging whether node already exists in the Graph or not.
        ///@see Graph::AddVertex(), Graph::AddEdge(), Graph::MapNode(), Graph::GetMappedNodeValue()
        bool NodeMapStatus(std::string v);

        void PrintSCCs(std::vector<int> &scc_nodes);
        void PrintSCCs(std::vector< std::unordered_map<int, std::unordered_map< std::string, std::unordered_set<int>>>> &pre_scc_DCSC_nodes);

    private:
        std::vector<std::vector<int>> back_adj_list;  /**< Tranposed Graph stored as an adjacency list. */
        std::vector<std::vector<int>> forward_adj_list;  /**< Input Graph stores as an adjancency list.  */
        std::queue<int> bfs_queue; /**< Queue to implement Breadth First Search (BFS). */
        std::unordered_map<std::string,int> node_mappings;  /**< Data structure to store the mappings of the input node value to a range [0,V)*/
        std::unordered_map<int,std::string> original_node_mappings;  /**< Data structure to store the mappings of the node value in range [0,V) to original node value.*/
        int V=0; /**< Stores the count of vertices in the Graph. */
        int E=0; /**< Stores the count of edges in the Graph. */
};

#include "graph.cpp"
#endif