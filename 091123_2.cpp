#include <iostream>
using namespace std;

#define nV 4

#define INF 999

void printMatrix(int matrix[][nV]);


void floydWarshall(int graph[][nV]) {
int matrix[nV][nV], i, j, k;

for (i = 0; i < nV; i++)
for (j = 0; j < nV; j++)
matrix[i][j] = graph[i][j];

// Adding vertices individually
for (k = 0; k < nV; k++) {
for (i = 0; i < nV; i++) {
for (j = 0; j < nV; j++) {
if (matrix[i][k] + matrix[k][j] < matrix[i][j])
matrix[i][j] = matrix[i][k] + matrix[k][j];
}
}
}
printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
for (int i = 0; i < nV; i++) {
for (int j = 0; j < nV; j++) {
if (matrix[i][j] == INF)
cout<<"INF";
else
cout<<matrix[i][j]<<" ";
}
cout<<endl;
}
}

int main() {
int graph[nV][nV] =
{{0, INF, 3, INF},
{2, 0, INF, INF},
{INF, 7, 0, 1},
{6, INF, INF, 0}};
floydWarshall(graph);
}