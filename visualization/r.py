import random 
# n = 100
# m = 100
count = 1
rm = True
mx = 0
start = 0

print('Enter req num of graphs')
count = int(input())
print('Enter req num of nodes')
n = int(input())
m = n
print('Enter req num of edges')
mx = int(input())

for i in range(start, count+start):
    with open("F:\\GitHub\\Repositories\\daa1\\test_graphs\\RandomGraph"+str(i)+".txt","w") as file1:
        if rm :
            m = random.randrange(0, mx, 1)
        file1.write(str(n))
        file1.write("\n")
        file1.write(str(m))
        file1.write("\n")
        edges = set()
        while len(edges) < m:
            n1 = random.randrange(0, n, 1)
            n2 = random.randrange(0, n, 1)
            if n1 == n2:
                continue
            edge = str(random.randrange(0, n, 1)) + " " + str(random.randrange(0, n, 1)) + "\n"
            edges.add(edge)
        for edge in edges:
            file1.write(edge)