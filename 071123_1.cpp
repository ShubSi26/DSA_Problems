#include <iostream>
using namespace std;

int n, i, j, visited[10], queue[10], front = -1, rear = -1;
int adj[10][10];

void bfs(int v)
{
for (i = 1; i <= n; i++)
if (adj[v][i] && !visited[i])
queue[++rear] = i;
if (front <= rear)
{
visited[queue[front]] = 1;
bfs(queue[front++]);
}
}

int main()
{
int v;
cout<<"Enter the number of vertices: ";
cin>>n;
for (i = 1; i <= n; i++)
{
queue[i] = 0;
visited[i] = 0;
}
cout<<"Enter graph data in matrix form: \n" ;
for (i = 1; i <= n; i++)
{
for (j = 1; j <= n; j++)
{
cin>>adj[i][j];
}

}

cout<<"Enter the starting vertex: ";
cin>>v;
bfs(v);
cout<<"The node which are reachable are: \n";
for (i = 1; i <= n; i++)
if (visited[i])
cout<<i<<" ";
else
cout<<"BFS is not possible. Not all nodes are reachable";
return 0;
}