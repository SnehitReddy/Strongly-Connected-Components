#include <unordered_set>
#include <stack>
#include <iostream>

void Graph::AddEdge(int u, int v){
    E++;
    (forward_adj_list[u]).push_back(v);
    (back_adj_list[v]).push_back(u);
}

void Graph::AddVertex(){
    V++;
    forward_adj_list.push_back({});
    back_adj_list.push_back({});
}

std::vector<int> Graph::GetForwardAdjList(int &v){
    return forward_adj_list[v];
}

std::vector<int> Graph::GetBackAdjList(int &v){
    return back_adj_list[v];
}

int Graph::GetVerticesCount(){
    return V;
}

int Graph::GetEdgesCount(){
    return E;
}

void Graph::FinishOrderDFS(int node, std::vector<bool> &visited, std::stack<int> &stack){

    visited[node] = true;

    for(auto next_node : forward_adj_list[node]){
        if(visited[next_node] == false)
            FinishOrderDFS(next_node,visited,stack);
    }

    stack.push(node);
}

void Graph::TransposeBFS(int v, std::vector<bool> &visited,bool print){

    bfs_queue.push(v);
    visited[v]=true;

    while(bfs_queue.empty() == false){

        int node = bfs_queue.front();
        bfs_queue.pop();

        if(print){
            std::cout<<node<<" ";
        }

        for(auto next_node : back_adj_list[node]){
            if(visited[next_node] == false){
                visited[next_node]=true;
                bfs_queue.push(next_node);
            }
        }
    }
}

void Graph::PrintSCCs(std::vector<int> &scc_nodes){

        std::vector<bool> visited(V,false);

        for(int i=0;i<(int)scc_nodes.size();i++){

            std::cout<<"**************** Strongly Connected Component "<<i+1<<" ********************\n\n";
            TransposeBFS(scc_nodes[i],visited,true);
            std::cout<<"\n\n";
        }
}

std::unordered_set<int> Graph::GetPredecessors(int &v,std::unordered_set<int> &nodes){
    
    std::unordered_set<int> predecessors;
    std::vector<bool> visited(V,false);

    bfs_queue.push(v);
    visited[v]=true;

    while(bfs_queue.empty() == false){

        int node = bfs_queue.front();
        bfs_queue.pop();

        for(auto next_node : back_adj_list[node]){
            if(visited[next_node] == false && nodes.find(next_node)!=nodes.end()){
                visited[next_node]=true;
                bfs_queue.push(next_node);
            }
        }

    }

    for(int i=0;i<V;i++)
        if(visited[i] == true)
            predecessors.insert(i);
        
    return predecessors;        
}

std::unordered_set<int> Graph::GetDescendants(int &v,std::unordered_set<int> &nodes){

    std::unordered_set<int> descendants;
    std::vector<bool> visited(V,false);

    bfs_queue.push(v);
    visited[v]=true;

    while(bfs_queue.empty() == false){

        int node = bfs_queue.front();
        bfs_queue.pop();

        for(auto next_node : forward_adj_list[node]){
            if(visited[next_node] == false && nodes.find(next_node)!=nodes.end()){
                visited[next_node]=true;
                bfs_queue.push(next_node);
            }
        }

    }

    for(int i=0;i<V;i++)
        if(visited[i] == true)
            descendants.insert(i);
        
    return descendants;         
}

void Graph::PrintSCCs(std::vector< std::unordered_map<int, std::unordered_map< std::string, std::unordered_set<int>>>> &pre_scc_DCSC_nodes){

    std::vector<std::vector<int>> scc_DCSC_nodes;
    for(auto& elem : pre_scc_DCSC_nodes){
        std::vector<int> abc;
        abc.insert(abc.end(), elem.begin()->second["SSC"].begin(), elem.begin()->second["SSC"].end());
        scc_DCSC_nodes.push_back(abc);
    }

    for(int i=0;i<(int)scc_DCSC_nodes.size();i++){

            std::cout<<"**************** Strongly Connected Component "<<i+1<<" ********************\n\n";
            
            for(auto node : scc_DCSC_nodes[i]){
                std::cout<<node<<" "; 
            }

            std::cout<<"\n\n";
        }
}

bool Graph::EdgeEmpty(std::unordered_set<int> &nodes){

    bool noEdge = true;
    for(auto& e: nodes){
        for(auto& n : forward_adj_list[e]){
            if(nodes.find(n) != nodes.end()){
                noEdge = false;
                return noEdge;
            }
        }
    }
    return noEdge;
}

int Graph::GetMappedNodeValue(std::string v){
    return node_mappings[v];
}

std::string Graph::GetOriginalNodeValue(int v){
    return original_node_mappings[v];
}

bool Graph::NodeMapStatus(std::string v){

    if(node_mappings.find(v) != node_mappings.end())
        return true;
    return false;

}

void Graph::MapNode(std::string v){
    V++;
    forward_adj_list.push_back({});
    back_adj_list.push_back({});
    node_mappings[v]=V-1;
    original_node_mappings[V-1]=v;
}