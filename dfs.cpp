#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int> > &adj, int node, vector<int> &vis) {
	vis[node] = 1;
	for(auto u:adj[node]) {
		if(vis[u] == 0) {
			if(isCycle(adj, u, vis)) return true;
		} else if (vis[u] == 1) return true;
	}
	vis[node] = 2;
	return false;
}

void iterative_dfs(int start, int n, vector<vector<int> > &adj) {
	vector<int> vis(n, 0);
	stack<int> s;
	s.push(start);
	while(!s.empty()) {
		int top = s.top();
		s.pop();
		vis[top] = 1;
		cout << top << ' ';
		for(auto u:adj[top]) {
			if(!vis[u]) s.push(u);
		}
	}
}

void recursion_dfs(int node ,vector<vector<int> > &adj, vector<int> &vis) {
	vis[node] = 1;
	cout << node << ' ';
	for(auto u:adj[node]) {
		if(!vis[u]) recursion_dfs(u, adj, vis);
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
	cout << "recusrsive output: ";
	recursion_dfs(start, adj, vis);
	cout << endl << "iterative output: ";
	iterative_dfs(start, n, adj);

	int ele = 3; // is ele reachable from start
	cout << endl << "Is " << ele << " reachable: " << vis[ele] << endl;

	for(int j = 0; j < vis.size() ;j++) vis[j] = 0;
	int flag = 0;
	for (int i = 0; i < n; ++i) {
		if(isCycle(adj, i, vis)) flag = 1;
	}
	if(flag) cout << "It is cyclic"; else cout << "It is not cyclic";
}