// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

vector<int> move1 = {-1,1,0,0};
vector<int> move2 = {0,0,-1,1};

void dfs(vector<vector<char>> &matrix, int row, int col){
	matrix[row][col] = '#';

	for(auto i = 0; i < 4; i++){
		int r = row + move1[i];
		int c = col + move2[i];

		if(!(r < 0 || c < 0 || r >= matrix.size() || c >= matrix[r].size() || matrix[r][c] == '#'))
			dfs(matrix,r,c);
	}
}

void solve(){
	// cout << "let's get it done" << endl;
	int n,m;
	cin >> n >> m;

	vector<vector<char>> matrix(n,vector<char>(m));
	for(auto i = 0; i < n; i++)
		for(auto j = 0; j < m; j++){
			// cout << "taking input " << endl;
			cin >> matrix[i][j];
		}		

	int rooms = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == '.'){
				rooms++;
				dfs(matrix,i,j);
			}
		}
	}

	cout << rooms << endl;
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