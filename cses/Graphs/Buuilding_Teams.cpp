// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

bool bipertite(vector<vector<int>> &graph, int ind, vector<int> &color){
	color[ind] = 0;
	queue<int> q;
	q.push(ind);

	while(!q.empty()){
		auto node = q.front();
		q.pop();

		for(auto child : graph[node]){
			if(color[child] == -1){
				color[child] = !color[node];
				q.push(child);
			}

			else if(color[child] == color[node]) return false;
		}
	}

	return true;
}

void solve(){
	// cout << "let's get it done" << endl;
	int n,m;
	cin >> n >> m;

	vector<int> color(n+1,-1);
	vector<vector<int>> graph(n+1);
	for(int i = 1; i <= m; i++){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i = 1; i <= n; i++){
		if(color[i] == -1){
			bool isbipertite = bipertite(graph,i,color);
			if(!isbipertite){
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}

	for(auto it : color){
		if(it == 0) cout << 1 << " ";	
		else if(it == 1) cout << 2 << " ";
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