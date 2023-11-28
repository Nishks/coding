// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

bool dfs(int node ,vector<vector<int>> &graph, vector<int> &vis, vector<int> &par, int &start, int &end){
	vis[node] = 1;

	for(auto neigh : graph[node]){
		if(vis[neigh] and neigh != par[node]){
			start = neigh;
			end = node;
			return true;
		}
		if(!vis[neigh]){
			par[neigh] = node;
			if(dfs(neigh, graph,vis,par,start,end)) return true;
		}
	}

	return false;
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

	vector<int> vis(n+1);
	vector<int> par(n+1);
	par[1] = -1;
	int start = INT_MIN;
	int end = INT_MIN;

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i,graph,vis,par,start,end);
			if(start != INT_MIN) break;
		}

	}

	if(start == INT_MIN) cout << "IMPOSSIBLE" << endl;
	else{
		vector<int> ans;
		ans.push_back(start);

		int temp = end;
		while(temp != start){
			ans.push_back(temp);
			temp = par[temp];
		}
		ans.push_back(temp);

		cout << ans.size() << endl;
		for(auto it : ans) cout << it << " ";
		cout << endl;
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