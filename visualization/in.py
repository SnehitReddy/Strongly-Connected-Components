TYPE = 'type'
NODE = 'node'
SCC = 'scc'
PNS = 'pns'
DNS = 'dns'
REM = 'rem'
ALL = 'all'

_data = []
final_data = []

with open('dc1.txt') as infile:
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

first_node = _data[0]
_data = {val[ALL] : val for val in _data}

dfs(first_node)


