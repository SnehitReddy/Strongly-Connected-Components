#ifndef _set_operations_h
#define _set_operations_h

#include<unordered_set>

///Function (optimized using appropiate data structure) to find set <a href = "https://www.geeksforgeeks.org/std-set_intersection-in-cpp/">Intersection of two vectors</a> containing items.
///
/// #### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// std::vector<int> a;
/// std::unordered_set<int> b;
/// std::unordered_set<int> intersection = GetIntersection(a,b);
/// ~~~~~~~~~~~~~~~~~~~~~~~~
///@param[in] a,b Lists to find intersection of
///@param[out] intersection Set containing common items in vector::std<int> a and std::unordered_set<int> b
///@return An unordered set containing common nodes in the two list
/// #### Time Complexity
///@note Time Complexity is Big 'O' (n), where n are number of items in vector::std<int> a
/// #### Link
///@attention STL set_intersection() is not directly used but rather implemented using appropriate data structure
///@see GetDifference(), GetUnion()
inline std::unordered_set<int> GetIntersection(std::vector<int> &a, std::unordered_set<int> &b);

///Function (optimized using appropiate data structure) to find set <a href = "https://www.geeksforgeeks.org/std-set_union-in-cpp/">Union of two lists</a> containing items.
///
/// #### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// std::vector<int> a, b;
/// std::unordered_set<int> union = GetUnion(a,b);
/// ~~~~~~~~~~~~~~~~~~~~~~~~
///@param[in] a,b Lists to find union of
///@param[out] unionset Set containing items present in std::vector<int> a and std::vector<int> b
///@return An unordered set containing items present in the both lists combined
/// #### Time Complexity
///@note Time Complexity is Big 'O' (n + m), where n,m are number of items in std::vector<int> a and std::vector<int> b respectively
///@attention STL set_union() is not directly used but rather implemented using appropriate data structure
///@see GetDifference(), GetIntesection()
inline std::unordered_set<int> GetUnion(std::vector<int> &a, std::vector<int> &b);

///Function (optimized using appropiate data structure) to find set <a href = "https://www.geeksforgeeks.org/std-set_difference-in-cpp/">Difference of two lists</a> containing items.
///
/// #### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// std::vector<int> a;
/// std::unordered_set<int> b;
/// std::vector<int> difference = GetDifference(a,b);
/// ~~~~~~~~~~~~~~~~~~~~~~~~
///@param[in] a,b Lists on which set difference operation is to be applied
///@param[out] rem Vector containing items present in std::unordered_set<int> b but not in vector::std<int> a 
///@return  A vector containing items in the two list
/// #### Time Complexity
///@note Time Complexity is Big 'O' (n), where n are number of items in vector::std<int> a
///@attention STL set_difference() is not directly used but rather implemented using appropriate data structure
///@see GetIntersection(), GetUnion()
inline std::vector<int> GetDifference(std::vector<int> &a, std::unordered_set<int> &b);

#include "set_operations.cpp"
#endif