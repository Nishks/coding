#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int mod = 1e9 + 7;

void solve() {
	// cout << "Let's do it" << endl;
	int n;
	cin >> n;

	vector<int> dp(n+1, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for(int i = 3; i <= n; i++){
		for(int dice = 1; dice <= 6; dice++)
			if(i-dice >= 0)
				dp[i] = (dp[i]%mod +  dp[i-dice]%mod) %mod;
	}

	cout << dp[n] << endl;
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
