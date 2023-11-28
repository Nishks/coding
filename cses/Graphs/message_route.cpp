// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

void bfs(vector<vector<int>> &graph, int node, int n){
	vector<pair<int,int>> direction(graph.size());
	vector<int> vis(graph.size(),0);
	queue<int> q;
	q.push(node);
	direction[node] = {node,-1};
	vis[node] = 1;

	bool flag = false;
	vector<int> level(n+1,0);
	level[node] = 1;

	while(!q.empty()){
		auto computer = q.front();
		q.pop();

		if(computer == n){
			flag = true;
			break;
		}

		for(auto child : graph[computer]){
			if(!vis[child]){
				q.push(child);
				vis[child] = 1;
				direction[child] = {child,computer};
				level[child] = level[computer]+1;
			}
		}
	}

	if(flag == false) cout << "IMPOSSIBLE" << endl;
	else{
		cout << level[n] << endl;
		vector<int> ans;

		int parent = direction[n].second;
		ans.push_back(n);

		while(true){
			auto newparent = direction[parent];
			if(newparent.second == -1){
				ans.push_back(newparent.first);
				break;
			}
			ans.push_back(direction[parent].first);
			parent = newparent.second;
		}

		reverse(ans.begin(), ans.end());
		for(auto it : ans)
			cout << it << " ";
		cout << endl;
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

	bfs(graph,1,n);
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