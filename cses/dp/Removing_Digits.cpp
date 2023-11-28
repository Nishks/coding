#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
	// Let's do it
	int n;
	cin >> n;

	vector<int> dp(n+1, INT_MAX);
	dp[0] = 0;

	for(int i = 1; i <= n; i++){
		int temp = i;
		while(temp != 0){
			int rem = temp%10;
			temp /= 10;
			if(rem == 0) continue;
			dp[i] = min(dp[i], 1+dp[i-rem]);
		}
	}

	// for(auto it : dp) cout << it << " ";
	// cout << endl;

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
