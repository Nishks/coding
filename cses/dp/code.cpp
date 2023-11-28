#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
	// cout << "Let's do it" << endl;
	int n;
	cin >> n;

	if (n == 2 or n == 3) cout << -1 << endl;
	else if(n == 4) cout << 3 << " " << 4 << " " << 1 << " " << 2 << endl;
	else {
		vector<int> ans;
		if (n & 1) {
			int first =  n;
			int second = n - 1;
			ans.push_back(second);
			ans.push_back(first);
		}
		else {
			int first =  n;
			int second = n - 1;
			ans.push_back(first);
			ans.push_back(second);
		}

		for (int i = 1; i < n - 1; i++) {
			ans.push_back(i);
		}

		for (auto it : ans)
			cout << it << " ";
		cout << endl;
	}

}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
