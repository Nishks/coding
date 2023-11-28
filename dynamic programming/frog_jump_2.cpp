#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int solve() {
	int n,k;
	cin >> n >> k;
	vector<int> arr;
	for (auto i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	// dp array
	vector<int> dp(n);
	dp[n-1] = 0;

	for (auto i = n-2; i >= 0; i--) {
		int jump = INT_MAX;
		for(int j = 1; j <= k and i+j < n; j++){
			jump = min(jump, dp[i+j] + abs(arr[i]-arr[i+j]));
		}
		dp[i] = jump;
	}

	// cout << dp[n - 1] << endl;
	// for(auto it : dp) cout << it << " ";
	cout << endl;
	return dp[0];
}

int32_t main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int T = 1;
	while (T--) {
		cout << solve() << endl;
	}
}