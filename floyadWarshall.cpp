#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define MAX 9999
int print(int graph[50][50], int z, int u) {
	for (int i = 1; i <= z; i++) {
		for (int j = 1; j <= u; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
int floydWarshall(int graph[50][50], int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (i == k || i == j) {
					graph[j][k] = graph[j][k];
				}
				else {
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
				}
			}
		}
	}
	cout << "\nAll Pair Shortest Path:\n\n";
	print(graph, n, m);
	return 0;
}
int main()
{
	int graph[50][50], n, x, y, z = 0, u = 0, w;
	memset(graph, MAX, sizeof(graph));
	cout << "Enter number of paths: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		graph[i][i] = 0;
		cout << "Path , destination and weigth: ";
		cin >> x >> y >> w;
		graph[x][y] = w;
		z = max(z, x);
		u = max(u, y);
	}
	cout << "Adjacency matrix:\n\n";
	print(graph, z, u);
	floydWarshall(graph, z, u);
	return 0;
}

 
	return 0;
}


