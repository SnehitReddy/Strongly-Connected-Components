#include <unordered_set>
#include <algorithm>

inline std::unordered_set<int> GetIntersection(std::vector<int> &a, std::unordered_set<int> &b)
{
    std::unordered_set<int> intersection; //Set containing nodes common in both the lists */
    intersection.reserve(std::min((int)a.size(), (int)b.size()));
    for (auto &node : a)
    {
        if (b.find(node) != b.end())
        {
            intersection.insert(node);
        }
    }
    return intersection;   
}

inline std::unordered_set<int> GetUnion(std::vector<int> &a, std::vector<int> &b)
{
    std::unordered_set<int> unionset; //Set containing nodes present in both the lists combined 
    unionset.reserve((int)a.size() + (int)b.size());
    for (auto &node : a)
    {
        unionset.insert(node);
    }
    for (auto &node : b)
    {
        unionset.insert(node);
    }
    return unionset; 
}

inline std::vector<int> GetDifference(std::vector<int> &a, std::unordered_set<int> &b)
{
    std::vector<int> rem;  //Vector containing nodes present in std::unordered_set<int> &b but not in std::vector<int> &a 
    rem.reserve(std::max((int)a.size(), (int)b.size()));
    for (auto &node : a)
    {
        if (b.find(node) == b.end())
            rem.push_back(node);
    }
    return rem;
}