#include <bits/stdc++.h>
using namespace std;

void bfs(int node ,vector<vector<int> > &adj, vector<int> &vis) {
	vis[node] = 1;
	queue<int> q;
	q.push(node);
	while(!q.empty()) {
		int front = q.front();
		cout << front << " ";
		vis[front] = 1;
		q.pop();
		for(auto v:adj[front]) {
			if(!vis[v]) q.push(v);
		}
	}
}
//DFS on a directed cyclic/acyclic graph
/*
Input
6 6
0 1
1 3
1 4
2 0
3 5
4 2
*/
int main() {
	int n, e;
	cin >> n >> e;
	vector<int> vis(n, 0);
	vector<vector<int> > adj(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	int start = 0;
	cout << "BFS output: ";
	bfs(start, adj, vis);

	int ele = 3; // is ele reachable from start
	cout << endl << "Is " << ele << " reachable: " << vis[ele] << endl;

}