#include<iostream>
using namespace std;
int n,i,j,visited[10],queue[10],front = -1,rear = -1;
int adj[10][10];
void bfs(int v){
    for(int i=i;i<=n;i++)
        if(adj[v][i] && !visited[i]) queue[++rear] = i;
        if(front <= rear){
            visited[queue[front]] = 1;
            bfs(queue[front++]);
        }
    }
int main(){
    int v;
    cout << "Enter the number of vertices: ";
    cin >> n;
    for(int i=1;i<=n;i++){
        queue[i] = 0;
        visited[i] = 0;
    }
    cout << "Enter the data in the matrix: \n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> adj[i][j];
        }
    }
    cin >> v;
    bfs(n);
    cout << "The node which are reachable are : \n";
    for(i=1;i<=n;i++)
    if(visited[i]) cout << i << " ";
    else cout << "All node is not reachible";
}