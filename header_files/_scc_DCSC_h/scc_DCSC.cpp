/** @file */ 
#include "../_graph_h/graph.h"
#include "../_random_value_creator_h/random_value_creator.h"
#include "../_set_operation_h/set_operations.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <random>
#include <iostream>
#include <numeric>
#include <fstream>

/** @brief Utility function to prepare the file which is used to save discovered <a href = "https://www.geeksforgeeks.org/strongly-connected-components/">SCCs</a> in the algorithm, for use in visualization.
 *
 * @param filename Path of the file to save data in.
 */
void SetupFile(std::string filename)
{
    std::ofstream outfile;
    outfile.open(filename, std::ofstream::out | std::ofstream::trunc);
    outfile.close();
}

/** @brief Utility function to save discovered SCCs in the algorithm for use in visualization.
 *
 * @param[in] filename Path of the file to save data in.
 * @param[in] data Data to save
 */
void SaveToFile(std::string filename, std::vector<int> data)
{
    std::ofstream outfile;
    outfile.open(filename, std::ios_base::app);
    for (auto &e : data)
    {
        outfile << e << " ";
    }
    if (data.empty())
    {
        outfile << "-1";
    }
    outfile << "\n";
}

/** @brief Utility function to convert unordered_set to vector.
 *
 * @param[in] uset std::set to be convert into std::vector
 * @param[out] vec Converted std::set into std::vector
 * @return A vector containing values of the given set
 */
inline std::vector<int> ToVector(std::unordered_set<int> &uset)
{
    std::vector<int> vec;
    vec.insert(vec.end(), uset.begin(), uset.end());
    return vec;
}

int SCCDC::DCSCC(std::vector<int> &nodes)
{
    int nsize = nodes.size();
    if (nodes.empty())
        return nsize;

    std::unordered_set<int> nset(nodes.begin(), nodes.end());

    if (graph.EdgeEmpty(nset))
    {
        steps.insert(steps.end(), nodes.begin(), nodes.end());
        if(kSaveResult){
            SaveToFile(kOutFile, {-2});
            SaveToFile(kOutFile, nodes);
        }
        return nsize;
    }

    int v = rd.GetRandomValue(0, (int)nodes.size() - 1);
    steps.push_back(nodes[v]);
    std::vector<std::vector<int>> nxt(3, std::vector<int>());

    std::unordered_set<int> predecessors = graph.GetPredecessors(nodes[v], nset);   // Set to store the predecessor nodes for a node
    std::vector<int> pvec = ToVector(predecessors);

    std::unordered_set<int> descendants = graph.GetDescendants(nodes[v], nset);   // Set to store the descendant nodes for a node
    std::vector<int> dvec = ToVector(descendants);

    std::unordered_set<int> scc = GetIntersection(pvec, descendants);    // Set to store the nodes common in both descendant and predecessor nodes for a node

    std::vector<int> pred_not_in_scc = GetDifference(pvec, scc);   // Vector to store the predecessor nodes of a node not present in the Strongly Connected Component containing it
    nxt[kPredNotInSSC] = pred_not_in_scc;

    std::vector<int> desc_not_in_scc = GetDifference(dvec, scc);    // Vector to store the descendant nodes of a node not present in the Strongly Connected Component containing it
    nxt[kDescNotInSSC] = desc_not_in_scc;

    std::unordered_set<int> un = GetUnion(pvec, dvec);
    std::vector<int> remainder = GetDifference(nodes, un);   // Vector to store the remaining nodes which are not either descendants or predecessors 

    nxt[kRemainder] = remainder;
    qu.push(nxt);

    if (kSaveResult)
    {
        std::vector<int> sccvec = ToVector(scc);
        SaveToFile(kOutFile, {nodes[v]});
        // SaveToFile(kOutFile, pvec);
        // SaveToFile(kOutFile, dvec);
        SaveToFile(kOutFile, sccvec);
        SaveToFile(kOutFile, desc_not_in_scc);
        SaveToFile(kOutFile, pred_not_in_scc);
        SaveToFile(kOutFile, remainder);
    }

    return 1;
}

std::vector<int> SCCDC::GetSCCDC(Graph &g)
{
    steps.clear();

    if(kSaveResult){
        SetupFile(kOutFile);
    }
    graph = g;
    int vertex_count = graph.GetVerticesCount();
    initial_nodes = std::vector<int>(vertex_count, 0);
    std::iota(initial_nodes.begin(), initial_nodes.end(), 0);
    steps.reserve((int)initial_nodes.size());
    DCSCC(initial_nodes);
    int ans = 1;
    while (!qu.empty())
    {
        auto nxt = qu.front();
        qu.pop();
        ans += DCSCC(nxt[kPredNotInSSC]);
        ans += DCSCC(nxt[kDescNotInSSC]);
        ans += DCSCC(nxt[kRemainder]);
    }
    return steps;
}