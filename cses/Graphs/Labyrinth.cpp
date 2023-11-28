// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

// int roadSize = INT_MAX;
// string direction = "";

// void dfs(vector<vector<char>> &map, int row, int col, int count, string path) {
// 	// cout << "came from " << row << " " << col << " path "<< path << endl;
// 	if (row < 0 || col < 0 || row >= map.size() || col >= map[row].size() || map[row][col] == 'V' || map[row][col] == '#') return;
// 	if (map[row][col] == 'B') {
// 		if(count < roadSize){
// 			roadSize = count;
// 			direction = path;
// 			return;
// 		}
// 	}

// 	char original_value = map[row][col];

// 	// move
// 	// bool ans = false;
// 	++count;
// 	map[row][col] = 'V';

// 	// cout << path << endl;
// 	dfs(map,row-1,col,count, path+'U'); // top
// 	// map[row][col] = original_value;

//     dfs(map,row+1,col,count, path+'D'); // down

//     dfs(map,row,col-1,count, path+'L'); // left

//     // cout << "right " << row << " " << col+1 << endl;
//     dfs(map,row,col+1,count, path+'R'); // right
//     // --count;
//     map[row][col] = '.';
//     // cout << "coming back from " << row << " " << col << " " << path << endl;
// 	// return ans;
// }

vector<char> direction = {'U', 'D', 'L', 'R'};
vector<pair<int,int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isvalid(vector<vector<char>> &map, int row, int col, vector<vector<int>> &vis) {
	if (row < 0 || col < 0 || row >= map.size() || col >= map[row].size()) return false;
	if (vis[row][col] == 1 || map[row][col] == '#') return false;
	return true;
}

void bfs(vector<vector<char>> &map, int row, int col, vector<vector<int>> &vis) {
	queue<pair<int, int>> q;
	vis[row][col] = 1;
	// cout << row << " " << col << endl;
	q.push({row, col});
	int lrow = -1 , lcol = -1;
	while (!q.empty()) {
		auto cell = q.front();
		q.pop();

		for (auto i = 0; i < 4; i++) {
			int r = cell.first + moves[i].first;
			int c = cell.second + moves[i].second;
			// cout << r << " " << c << endl;
			if (!isvalid(map, r, c,vis)) continue;
			// cout << r << " " << c << " is valid "  << endl;
			q.push({r, c});
			vis[r][c] = 1;
			if (map[r][c] == 'B'){
				// cout << "found B" << endl;
				lrow = r;
				lcol = c;
				map[r][c] = direction[i];
				break;
			}
			map[r][c] = direction[i];
		}
	}

	// cout << lrow << " " << lcol << endl;
	if(lrow == -1) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		string ans;
		while(map[lrow][lcol] != 'A'){
			for(int i = 0; i < 4; i++){
				if(map[lrow][lcol] == direction[i]){
					ans += direction[i];
					lrow -= moves[i].first;
					lcol -= moves[i].second;
					break;
				}
			}
		}
		cout << ans.size() << endl;
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}

	// for(auto it : map){
	// 	for(auto val : it)
	// 		cout << val << " ";
	// 	cout << endl;
	// }

}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> map(n, vector<char>(m));
	int sr = 0, sc = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'A') {
				sr = i, sc = j;
			}
		}
	}

	// dfs(map,sr,sc,count,"");
	// if(roadSize != INT_MAX){
	// 	cout << "YES" << endl;
	// 	cout << roadSize << endl;
	// 	cout << direction << endl;
	// }
	// else cout << "NO" << endl;

	vector<vector<int>> vis(n, vector<int> (m, 0));
	bfs(map, sr, sc, vis);

}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	while (t--) solve();
}