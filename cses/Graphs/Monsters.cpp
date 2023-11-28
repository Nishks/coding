// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

void print_matrix(vector<vector<int>> &matrix) {
	for (auto it : matrix) {
		for (auto val : it)
			cout << val << " ";
		cout << endl;
	}
}

void print_matrix(vector<vector<char>> &matrix) {
	for (auto it : matrix) {
		for (auto val : it)
			cout << val << " ";
		cout << endl;
	}
}

bool isValid(vector<vector<char>> &grid, int x, int y, vector<vector<int>> &reach) {
	int n = grid.size();
	int m = grid[x].size();

	if (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] != '#' and reach[x][y] == INT_MAX) {
		return true;
	}
	return false;
}

void shortestPath(vector<vector<char>> &grid, vector<vector<int>> &reach, char ch) {
	// cout << "shortest path for " << ch << endl;
	int n = grid.size();
	int m = grid[0].size();

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == ch) {
				q.push({i, j});
				reach[i][j] = 0;
			}
		}
	}

	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	int level = 0;

	while (!q.empty()) {

		auto size = q.size();
		level++;

		while (size--) {
			auto monster = q.front();
			q.pop();
			int curr_Row = monster.first;
			int curr_Col = monster.second;

			for (int i = 0; i < 4; i++) {
				int x = curr_Row + dx[i];
				int y = curr_Col + dy[i];

				if (isValid(grid, x, y, reach)) {
					reach[x][y] = level;
					q.push({x, y});
				}
			}
		}
	}
}

vector<char> direction = {'U', 'D', 'L', 'R'};
vector<pair<int, int>> moves = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
 
string can_Escape(vector<vector<int>> &monsters, vector<vector<int>> &player, vector<vector<int>> &vis, vector<vector<char>> &parent) {
	int n = monsters.size();
	int m = monsters[0].size();
 
	pair<int, int> start = {0, 0};
	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j < m; j++) {
			if (player[i][j] == 0) {
				start.first = i;
				start.second = j;
				break;
			}
		}
	}
 
	queue<pair<int, int>> q;
	q.push(start);
	vis[start.first][start.second] = 1;
	parent[start.first][start.second] = 's';
 
	int ex = -1;
	int ey = -1;

	while (!q.empty()) {
		auto cell = q.front();
		q.pop();
 
		int curr_Row = cell.first;
		int curr_Col = cell.second;

		if(curr_Row == 0 || curr_Col == 0 || curr_Row == n-1 || curr_Col == m-1){
			ex = curr_Row;
			ey = curr_Col;
			break;
		}
 
		for (int i = 0; i < 4; i++) {
			int x = curr_Row + moves[i].first;
			int y = curr_Col + moves[i].second;
 
			// if player can reach x,y before monster
			if (x >= 0 and y >= 0 and x < n and y < m and player[x][y] < monsters[x][y] and vis[x][y] == -1) {
				vis[x][y] = 1;
				q.push({x, y});
				parent[x][y] = direction[i];
			}
		}
	}

	if(ex == -1) return "NO";
	// cout << "End row " << ex << " EndCol " << ey << endl;
	// cout << "Start.first " << start.first << " " << "start.second " << start.second << endl;

	string path = "";
	while(ex != start.first || ey != start.second){
		path.push_back(parent[ex][ey]);
		for(int i = 0; i < 4; i++){
			if(path.back() == direction[i]){
				ex -= moves[i].first;
				ey -= moves[i].second;
			}
		}
	}

	reverse(path.begin(), path.end());
	return path;
}


void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> grid(n, vector<char>(m));
	pair<int,int> start = {0,0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			if(ch == 'A') start = {i,j};
			grid[i][j] = ch;
		}
	}

	vector<vector<int>> monsters(n, vector<int>(m, INT_MAX));
	vector<vector<int>> player(n, vector<int>(m, INT_MAX));

	shortestPath(grid, monsters, 'M');
	shortestPath(grid, player, 'A');

	// print_matrix(monsters);
	// cout << "----------------------" << endl;
	// print_matrix(player);

	vector<vector<int>> vis(n, vector<int> (m, -1));
	vector<vector<char>> parent(n, vector<char> (m, '#'));
	string ans = can_Escape(monsters,player,vis,parent);
	// print_matrix(parent);

	if(ans == "NO") cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		cout << ans.size() << endl;
		cout << ans << endl;
	}
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