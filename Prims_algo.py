import numpy as np

INFINITY = 99999

N = int(input("Enter the no of vertices"))
print("Enter the elemnts of the matrix")
elems = list(map(int, input().split()))
G = np.array(elems).reshape(N, N)
print(G)
visited = [0, 0, 0, 0, 0, 0, 0]
no_edges = 0
visited[0] = True
mincost = 0
while no_edges < N - 1:
    min = INFINITY
    u = 0
    v = 0
    for i in range(N):
        if visited[i]:
            for j in range(N):
                if (not visited[j] and G[i][j]):
                    if min > G[i][j]:
                        min = G[i][j]
                        u = i
                        v = j
    print(str(u + 1) + "->" + str(v + 1) + ":" + str(G[u][v]))
    visited[v] = True
    mincost = mincost + G[u][v]
    no_edges = no_edges + 1
print("Minimum cost is:", mincost)
