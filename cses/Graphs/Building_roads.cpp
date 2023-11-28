// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

void dfs(vector<vector<int>> &graphs, vector<int> &vis, int node){
	vis[node] = 1;

	for(auto neigh : graphs[node]){
		if(!vis[neigh]){
			dfs(graphs,vis,neigh);
		}
	}
}

void solve(){
	// cout << "let's get it done" << endl;
	int n,m;
	cin >> n >> m;

	vector<vector<int>> graph(n+1);
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// for(auto it = 1; it < graph.size(); it++){
	// 	cout << it << " -->> ";
	// 	for(auto edge : graph[it])
	// 		cout << edge << " ";
	// 	cout << endl;
	// }

	vector<int> ans;
	vector<int> vis(n+1,0);

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			ans.push_back(i);
			dfs(graph,vis,i);
		}
	}

	cout << ans.size()-1 << endl;
	int i = 0;
	int j = 1;
	while(i < j and j < ans.size()){
		cout << ans[i] << " " << ans[j] << endl;
		i++;
		j++;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	while(t--) solve();
}