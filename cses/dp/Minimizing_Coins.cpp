#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int dp[1000004][102];

int minCoins(vector<int> &coins, int target, int ind){
	if(ind == (int)coins.size()){
		if(target == 0) return 0;
		return INT_MAX;
	}
	if(target == 0) return 0;
	if(target < 0) return INT_MAX;

	// if already calculated then return the answer
	if(dp[target][ind] != -1){ 
		// if(dp[target][ind] == INT_MAX) return -1;
		return dp[target][ind];
	}

	int take = INT_MAX;
	// take the same coin again
	if(target - coins[ind] >= 0){
		take = 1 + minCoins(coins, target-coins[ind], ind);
	}

	// not take the coin
	int not_take = minCoins(coins, target, ind+1);

	return dp[target][ind] = min(take,not_take);
}

void solve() {
	// cout << "Let's do it" << endl;
	int n, x;
	cin >> n >> x;

	memset(dp, -1, sizeof(dp));

	vector<int> coins;
	for (int i = 0; i < n; i++) {
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}

	// cout << minCoins(coins, x, 0) << endl;
	int ans = minCoins(coins,x,0);
	if(ans == INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	while (t--) {
		solve();
	}
}
