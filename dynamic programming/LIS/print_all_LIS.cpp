#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
	// cout << "Let's do it" << endl;
	int n;
	cin >> n;

	vector<int> v(n);
	for(auto i = 0; i < n; i++) cin >> v[i];

	print_LIS(v);
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
