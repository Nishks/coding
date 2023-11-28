#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int solve() {
	// cout << "Let's do it" << endl;
	int n;
	cin >> n;

	vector<int> a;
	for(auto i = 0; i < n; ++i){
		int x;
		cin >> x;
		a.push_back(x);
	}

	// dp[i][0] means max sum from i to n-1 if current element is not changed
	// dp[i][1] means max sum from i to n-1 if current element is changed
	int dp[n][2];
	dp[n-2][0] = a[n-2] + a[n-1];
	dp[n-2][1] = -a[n-2] - a[n-1];

	for(int i = n-3; i >= 0; i--){
		dp[i][0] = a[i] + max(dp[i+1][0], dp[i+1][1]);
		dp[i][1] = -a[i] + max(dp[i+1][1] + 2*a[i+1], dp[i+1][0] - 2*a[i+1]);
	}

	return max(dp[0][0], dp[0][1]);
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		cout << solve() << endl;
	}
}
