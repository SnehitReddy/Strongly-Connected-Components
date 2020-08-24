import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from matplotlib import animation

TYPE = 'type'
NODE = 'node'
SCC = 'scc'
PRD = 'prd'
DES = 'des'
PNS = 'pns'
DNS = 'dns'
REM = 'rem'
ALL = 'all'

FILE = 'visgraph.txt'
_data = []
final_data = []

with open('../visualization/vis_test_graphs/'+FILE) as infile:
    state = 1
    rtype = 1
    for line in infile:
        ls = list(map(int, line.split()))
        ls = [v for v in ls if v != -1]
        if state == 1 :
            _data.append({})
            if ls[0] != -2:
                _data[-1][TYPE] = 1
                _data[-1][NODE] = ls[0]
            else:
                _data[-1][TYPE] = 2
            rtype = _data[-1][TYPE]
        elif state == 2 :
            if(rtype == 1):
                _data[-1][SCC] = frozenset(ls)
            else :
                _data[-1][ALL] = frozenset(ls)
        elif state == 3 :
            _data[-1][DNS] = frozenset(ls)
        elif state == 4 :
            _data[-1][PNS] = frozenset(ls)
        elif state == 5 :
            _data[-1][REM] = frozenset(ls)
            _data[-1][ALL] = frozenset(_data[-1][REM] | _data[-1][PNS] | _data[-1][DNS] | _data[-1][SCC])
        elif state == 6 :
            _data[-1][PNS] = frozenset(ls)
        elif state == 7 :
            _data[-1][DES] = frozenset(ls)
        state = state + 1
        if state > 5 and rtype == 1:
            state = 1
        elif state > 2 and rtype == 2:
            state = 1



def dfs(val):
    if val:
        final_data.append(val)
        if val[TYPE] == 1 :
            if val[PNS]:
                dfs(_data[val[PNS]])
            if val[DNS]:
                dfs(_data[val[DNS]])
            if val[REM]:
                dfs(_data[val[REM]])



# if DFS
first_node = _data[0]
_data = {val[ALL] : val for val in _data}
dfs(first_node)
# if BFS
# final_data = _data

n = 0 # Number of nodes
m = 0 # Number of edges
edge_list = list()
NODE_SIZE = 150
EDGE_WIDTH = 0.25

with open('../visualization/out_test_graphs/'+FILE) as f:
    content = f.readlines()
    content = [list(map(int, x.strip().split())) for x in content]
    n = content[0][0]
    m = content[1][0]
    edge_list = content[2:]
    for i, e in enumerate(edge_list):
        if len(e) != 2:
            print(i, ')',e)

colors = ["#C0C0C0"]*n


legend_colors = []
legend_colors.append(mpatches.Patch(color='blue', label='Current Node'))
legend_colors.append(mpatches.Patch(color='green', label='SCC'))
legend_colors.append(mpatches.Patch(color='yellow', label='Predecessors not in SCC'))
legend_colors.append(mpatches.Patch(color='orange', label='Descendents not in SCC'))
legend_colors.append(mpatches.Patch(color='red', label='Remaining'))
legend_colors.append(mpatches.Patch(color='brown', label='Disconnected SCCs'))


def simple_update(num, n, layout, G, ax):
    ax.clear()
    # print(num)
    # print(colors)
    if num == 0:
        colors1 = ["#C0C0C0"]*n
        nx.draw(G, pos=layout, node_color=colors1, ax=ax, node_size = NODE_SIZE, width = EDGE_WIDTH)
        return
    num = num - 1
    for i, ele in enumerate(colors):
        if ele == "g" or ele == "brown":
            colors[i] = "black"
        # elif ele == "black":
        #     pass
        # else:
        #     ele = "#C0C0C0"
    nx.draw(G, pos=layout, node_color=colors, ax=ax, node_size = NODE_SIZE, width = EDGE_WIDTH)
    if final_data[num][TYPE] == 1:
        nx.draw_networkx_nodes(G, pos=layout, nodelist=final_data[num][PNS], node_color='y', node_size=NODE_SIZE)
        nx.draw_networkx_nodes(G, pos=layout, nodelist=final_data[num][DNS], node_color='orange', node_size=NODE_SIZE)
        nx.draw_networkx_nodes(G, pos=layout, nodelist=final_data[num][SCC], node_color='g', node_size=NODE_SIZE)
        for e in final_data[num][SCC]:
            colors[e] = "g"
        nx.draw_networkx_nodes(G, pos=layout, nodelist=final_data[num][REM], node_color='r', node_size=NODE_SIZE)
        nx.draw_networkx_nodes(G, pos=layout, nodelist=[final_data[num][NODE]], node_color='blue', node_size=NODE_SIZE)
    
    if final_data[num][TYPE] == 2:
        nx.draw_networkx_nodes(G, pos=layout, nodelist=final_data[num][ALL], node_color='brown', node_size=NODE_SIZE)
        for e in final_data[num][ALL]:
            colors[e] = "brown"
    nx.draw_networkx_labels(G, pos = layout, font_color = "white", font_size = NODE_SIZE/15)

    legend = plt.legend(handles = legend_colors)
    return [legend]


def simple_animation():

    # Build plot
    fig, ax = plt.subplots(figsize=(12,10))

    # Create a graph and layout
    G = nx.DiGraph()
    G.add_nodes_from(list(range(n)))
    G.add_edges_from(edge_list)

    layout = nx.random_layout(G)

    ani = animation.FuncAnimation(fig, simple_update, frames=len(final_data)+1, interval = 2000, fargs=(n, layout, G, ax),cache_frame_data=False)
    ani.save('animation_1.gif',writer="imagemagick",fps=.25)

    plt.show()

simple_animation()