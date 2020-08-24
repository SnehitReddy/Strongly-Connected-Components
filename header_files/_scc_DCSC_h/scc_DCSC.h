#ifndef _scc_DCSC_h
#define _scc_DCSC_h

#include "../_graph_h/graph.h"
#include "../_random_value_creator_h/random_value_creator.h"
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <random>

using dict_type = std::vector<std::vector<std::vector<int>>>;
using q_type = std::queue<std::vector<std::vector<int>>>;

/** @brief Class representing <a href ="https://www.osti.gov/servlets/purl/889876"> Divide and Conquer algorithm to find Strongly Connected Component(s)</a> in a digraph.
 * 
 */
class SCCDC
{
    private:
        // dict_type steps2;
        q_type qu;                          /**<  Stores subgraphs to be processed*/
        std::vector<int> steps;             /**<  Stores representative nodes for each SCC  */ 
        Graph graph;                        /**<  Stores the digraph which is used in the algorithm */
        RandomValueCreator rd;              /**<  Used to get uniform random value in given range*/
        std::vector<int> initial_nodes;     /**<  Store set of all nodes in the given digraph*/

        const int kPredNotInSSC = 0;        /**<  Index to determine order of writing in file, for use in visualization*/
        const int kDescNotInSSC = 1;        /**<  Index to determine order of writing in file, for use in visualization*/
        const int kRemainder = 2;           /**<  Index to determine order of writing in file, for use in visualization*/
        const int kNode = 3;                /**<  Index to determine order of writing in file, for use in visualization*/
        const int kSSC = 4;                 /**<  Index to determine order of writing in file, for use in visualization*/
        const int kPredecessors = 5;        /**<  Index to determine order of writing in file, for use in visualization*/
        const int kDescendants = 6;         /**<  Index to determine order of writing in file, for use in visualization*/

        const std::string kOutFile =  "../visualization/vis_test_graphs/visgraph.txt";  /**<  Filename to use when writing to file, for use in visualization */

        /** @brief <a href ="https://www.osti.gov/servlets/purl/889876"> Divide and Conquer algorithm to find Strongly Connected Components</a> of a digraph.
         *
         * Checks if there exists any edges in the subgraph under consideration (O(n)). If there are no edges, all nodes in the subgraph are
         * SCCs on their own, otherwise select a node at random and find its SCC (O(n)). Add disjoint subgraphs <Predecessors/SCC>, 
         * <Descendants/SCC> and <Remainder> to the qu to be processed. Add a representative node of the discovered SCC to steps
         * @param[in] nodes a vector of nodes which represent the subgraph under consideration
         * @return Size of the discovered <a href = "https://www.geeksforgeeks.org/strongly-connected-components/">SCC</a> 
         * #### Time Complexity
         * @note Time Complexity is Big 'O' ( n * log(n) ) for average case, where n are number of nodes in the Graph.
         * @see Graph::GetPredecessors(),Graph::GetDescendants(), SCCDC::GetSCCDC(), GetIntersection(), GetDifference(), GetUnion()
         * @see Graph, RandomValueCreator, set_operations.h
         */
        int DCSCC(std::vector<int> &nodes);

    public:

        bool kSaveResult = false;     /**<  Determine to write to file or not, for use in visualization */
        /** @brief <a href ="https://www.osti.gov/servlets/purl/889876"> Divide and Conquer algorithm to find Strongly Connected Components</a> of a digraph.
         *
         * Add a vector of all nodes of the Graph to qu. Call DCSCC on each vector in the qu until it is empty. This is equivalent to running
         * BFS on the problem space instead of <a href= "https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/">Depth First Search</a>(DFS) as in the paper.
         * @param[in] g Graph containing connected components
         * @param[out] steps A list contatining representative nodes of <a href = "https://www.geeksforgeeks.org/strongly-connected-components/"> Strongly Connected Components</a> in the Graph
         * @return  A list of representative nodes for each <a href = "https://www.geeksforgeeks.org/strongly-connected-components/">SCC</a> in the Graph.
         * #### Time Complexity
         * @note Time Complexity is Big 'O' ( n * log(n) ) for average case, where n are number of nodes in the Graph.
         * @see Graph::GetPredecessors(), Graph::GetDescendants(), SCCDC::DCSCC(), GetIntersection(), GetDifference(), GetUnion() 
         * @see Graph, RandomValueCreator, set_operations.h
         */
        std::vector<int> GetSCCDC(Graph &g);
        // std::vector<int> GetSCCDC(Graph &g);
        // std::unordered_set<int> done;
};

#include "scc_DCSC.cpp"
#endif