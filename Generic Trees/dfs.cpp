#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void dfs(int node, vector<vector<int>> &edges, int parent){
	cout << node << " ";

	for(auto neigh : edges[node]){
		if(neigh == parent) continue;
		dfs(neigh, edges, node);
	}
}

void solve(){
	int n; // no. of nodes
	cin >> n;

	vector<vector<int>> edges(n, vector<int>());
	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(0,edges,-1);
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int t = 1;
	while(t--){
		solve();
	}
}