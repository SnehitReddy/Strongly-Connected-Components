@page kosaraju Strongly Connected Components using DFS

@tableofcontents

This algorithm just does twice ***DFS***, and has a lot better complexity ***O(V + E)*** , than the brute force approach. First define a **Condensed Component Graph** as a graph with ***<= V*** nodes and ***<= E*** edges, in which every node is a Strongly Connected Component and there is an edge from ***C*** to ***C'*** , where ***C*** and ***C'*** are Strongly Connected Components, if there is an edge from any node of ***C*** to any node of ***C'***.

It can be proved that the Condensed Component Graph will be a ***Directed Acyclic Graph(DAG)***. To prove it, assume the contradictory that is it is not a ***DAG***, and there is a cycle. Now observe that on the cycle, every strongly connected component can reach every other strongly connected component via a directed path, which in turn means that every node on the cycle can reach every other node in the cycle, because in a strongly connected component every node can be reached from any other node of the component. So if there is a cycle, the cycle can be replaced with a single node because all the Strongly Connected Components on that cycle will form one Strongly Connected Component.

Therefore, the Condensed Component Graph will be a ***DAG***. Now, a ***DAG*** has the property that there is at least one node with no incoming edges and at least one node with no outgoing edges. Call the **2** above nodes as **Source** and **Sink** nodes. Now observe that if a ***DFS*** is done from any node in the Sink (which is a collection of nodes as it is a Strongly Connected Component), only nodes in the Strongly Connected Component of Sink are visited. Now, removing the sink also results in a ***DAG***, with maybe another sink. So the above process can be repeated until all Strongly Connected Component's are discovered. So at each step any node of Sink should be known. This should be done efficiently.

Now a property can be proven for any two nodes ***C*** and ***C'*** of the Condensed Component Graph that share an edge, that is let ***C -> C'*** be an edge. The property is that the **finish time** of ***DFS*** of some node in ***C*** will be always higher than the finish time of all nodes of ***C'***.

**Proof:** There are cases, when ***DFS*** first discovers either a node in ***C*** or a node in ***C'***.

***Case 2: When DFS first discovers a node in C*** : Now at some time during the ***DFS***, nodes of ***C'*** will start getting discovered ( because there is an edge from ***C*** to ***C'***), then all nodes of ***C'*** will be discovered and their ***DFS*** will be finished in sometime ( Why? Because it is a Strongly Connected Component and will visit everything it can, before it backtracks to the node in ***C***, from where the first visited node of ***C'*** was called ). Therefore for this case, the finish time of some node of ***C*** will always be higher than finish time of all nodes of ***C'***.

***Case 2: When DFS first discovers a node in C'*** : Now, no node of ***C*** has been discovered yet. ***DFS*** of ***C'*** will visit every node of ***C'*** and maybe more of other Strongly Connected Component's if there is an edge from ***C'*** to that Strongly Connected Component. Observe that now any node of ***C*** will never be discovered because there is no edge from ***C'*** to ***C***. Therefore ***DFS*** of every node of ***C'*** is already finished and ***DFS*** of any node of ***C*** has not even started yet. So clearly finish time of some node ( in this case all ) of ***C***, will be higher than the finish time of all nodes of ***C'***.

So, if there is an edge from ***C*** to ***C'*** in the condensed component graph, the finish time of some node of ***C*** will be higher than finish time of all nodes of ***C'***. In other words, **topological sorting** ( a linear arrangement of nodes in which edges go from left to right ) of the condensed component graph can be done, and then some node in the leftmost Strongly Connected Component will have higher finishing time than all nodes in the Strongly Connected Component's to the right in the topological sorting.

Now the only problem left is how to find some node in the sink Strongly Connected Component of the condensed component graph. The **condensed component graph** can be reversed, then all the **sources will become sinks** and all the **sinks will become sources**. Note that the Strongly Connected Component's of the reversed graph will be same as the Strongly Connected Components of the original graph.

Now a ***DFS*** can be done on the new sinks, which will again lead to finding Strongly Connected Components. And now the order in which ***DFS*** on the new sinks needs to be done, is known. The order is that of decreasing finishing times in the ***DFS*** of the original graph. This is because it was already proved that an edge from ***C*** to ***C'*** in the original condensed component graph means that finish time of some node of ***C*** is always higher than finish time of all nodes of ***C'***. So when the graph is reversed, sink will be that Strongly Connected Component in which there is a node with the highest finishing time. Since edges are reversed, ***DFS*** from the node with highest finishing time, will visit only its own Strongly Connected Component.

Now a ***DFS*** can be done from the next valid node ( valid means which is not visited yet, in previous ***DFS(s)*** ) which has the next highest finishing time. In this way all Strongly Connected Component's will be found. The complexity of the above algorithm is ***O(V + E)***, and it only requires ***2 DFS(s)***.

![](kosaraju.png)

<center><strong>Condensed Component Graph</strong></center>

##### Sources : **https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/**