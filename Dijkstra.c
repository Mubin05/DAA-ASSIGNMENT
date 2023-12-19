#include <stdio.h>
void dijkstra(int G[100][100], int n, int source);
void relax(int u, int v, int w[100][100], int dist[]);
int extract_min(int p[], int dist[], int n);
int main() {
  int G[100][100];
  int n, source,i,j;
  printf("Enter the number of vertices:");
  scanf("%d", &n);
  printf("Enter the adjacence matrix (%d x %d):\n", n, n);
  for ( i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &G[i][j]);
    }
  }
  printf("Enter the source vertex:");
  scanf("%d", &source);
  dijkstra(G, n, source);
  return 0;
}
void dijkstra(int G[100][100], int n, int source) {
  int distance[100];
  int visited[100];
  int i,v;
  for (i = 0; i < n; i++) {
    distance[i] = 9999;
    visited[i] = 0;
  }
  distance[source] = 0;
  for (i = 0; i < n; i++) {
    int u = extract_min(distance, visited, n);
    visited[u] = 1;
    for (v = 0; v < n; v++) {
      if (!visited[v] && G[u][v] != -1)
        relax(u, v, G, distance);
    }
  }
  printf("Vertex \t Distance from Source \n");
  for (i = 0; i < n; i++) {
    printf("%d \t\t %d \n", i, distance[i]);
  }
}
void relax(int u, int v, int w[100][100], int dist[]) {
  if (w[u][v] + dist[u] < dist[v]) {
    dist[v] = w[u][v] + dist[u];
  }
}
int extract_min(int visited[], int dist[], int n) {
  int min = 99999;
  int min_index = -1;
  int i;
  for (i = 0; i < n; i++) {
    if (visited[i] == 0 && dist[i] < min) {
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}
