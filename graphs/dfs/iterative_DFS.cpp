#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void iterative_DFS(vector<vector<int>> &graph, int src){
	vector<int> vis(graph.size(), 0);
	stack<pair<int,string>> s;
	s.push({src, to_string(src)});
	vis[src] = 1;

	while(!s.empty()){
		auto node = s.top();
		s.pop();
		// cout << node.first << " " << node.second << endl;
		// if(!vis[node.first]){
		cout << node.first << "@" << node.second << endl;
		// cout << node << endl;

		for(auto neigh : graph[node.first]){
			if(vis[neigh]) continue;
			vis[neigh] = 1;
			string path = node.second + to_string(neigh);
			s.push({neigh, path});
		}
		
		// }
	}
}

void solve(){
	int n,m;
	cin >> n >> m;

	vector<vector<int>> graph(n,vector<int>());
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}	

	for(int i = 0; i < n; i++){
		cout << i << " --> ";
		for(auto node : graph[i]){
			cout << node << " ";
		}
		cout << endl;
	}

	iterative_DFS(graph, 2);
}

int32_t main(){

// #ifndef ONLINE_JUDGE
// 	freopen('input.txt', 'r', stdin);
// 	freopen('output.txt', 'w', stdout);
// #endif
	
	int t = 1;
	while(t--){
		solve();
	}
}