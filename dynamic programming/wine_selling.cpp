#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int wines(vector<vector<int>> &dp, vector<int> &prices, int s, int e, int y) {
	// base case
	if (s > e) return 0;
	// use memoization
	if (dp[s][e] != -1) return dp[s][e];
	// profit if we sell the first wine
	int pick_first = prices[s] * y +  wines(dp, prices, s + 1, e, y + 1);
	// profit if we sell the last wine
	int pick_last = prices[e] * y + wines(dp, prices, s, e - 1, y + 1);
	return dp[s][e] = max(pick_first, pick_last);
}

void solve() {
	// cout << "Let's do it" << endl;
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	
	vector<vector<int>> dp(n, vector<int>(n,0));

	// cout << wines(dp, a, 0, n - 1, 1) << endl;
	// cout << "---------------------------" << endl;


	for(int len = 1; len <= n; len++){
		for(int i = 0; i < n; i++){
			int j = i+len-1;
			// when i is last or second last
			// and you calculate j then if length is large then it can go out 
			// of bound hence check i < j and j should be valid.
			// like if len = 2. and you are at i = n-1 then j will be n which
			// is out of bound.
			if(i == j) dp[i][j] = n*a[i];
			else if(i < j and j < n){
				// what is the first year that you can use
				// so that you can sold the first and last wine
				// for this range. That year would be the length of this
				// i,j subtracted from the total length n.
				int year = n-len+1;
				// cout << "year " << year << " start " << i << " end " << j << endl;
				dp[i][j] = max(a[i]*year + dp[i+1][j], dp[i][j-1] + a[j]*year);
			}
		}
	}

	cout << dp[0][n-1] << endl;

	// for(auto it : dp){
	// 	for(auto i : it)
	// 		cout << i << " ";
	// 	cout << endl;
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
