#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int


void solve() {
	int n;
	cin >> n;

	vector<int> a;
	vector<int> b;
	vector<int> c;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a.push_back(x);
		b.push_back(y);
		c.push_back(z);
	}

	vector<int> dpa(n);
	vector<int> dpb(n);
	vector<int> dpc(n);

	dpa[0] = a[0];
	dpb[0] = b[0];
	dpc[0] = c[0];

	for (auto i = 1; i < n; i++) {
		dpa[i] = a[i] + max(dpb[i - 1], dpc[i - 1]);
		dpb[i] = b[i] + max(dpa[i - 1], dpc[i - 1]);
		dpc[i] = c[i] + max(dpb[i - 1], dpa[i - 1]);
	}

	int ans = max(dpa[n - 1], max(dpb[n - 1], dpc[n - 1]));
	cout << ans << endl;
}

void tabulation() {
	int n;
	cin >> n;

	vector<int> a;
	vector<int> b;
	vector<int> c;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a.push_back(x);
		b.push_back(y);
		c.push_back(z);
	}

	int dp[n][3];
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0];

	for(int i = 1; i < n; i++){
		dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
	}

	int ans = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
	// cout << dp[n-1][0] << " " << dp[n-1][1] << " " << dp[n-1][2] << endl;
	cout << ans << endl;
}

int32_t main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	while (t--) {
		// solve();
		tabulation();
	}
}