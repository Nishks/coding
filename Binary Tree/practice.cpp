#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

bool solve() {
	string str1 = "abc";
	string str2 = "ad";

	// if (str2.size() < str1.size()) return false;

	int i = 0, j = 0;
	while (i < str1.size()) {
		cout << "enterd " << endl;
		char move = str1[i] + 1 % 26;
		cout << "move " << move << endl;
		if (str1[i] == str2[j] || move == str2[j]) {
			i++;
			j++;
		};
		i++;
	}

	if (j == str2.size()) return true;
	return false;
}

int32_t main() {

// #ifndef ONLINE_JUDGE
// 	freopen('input.txt', 'r', stdin);
// 	freopen('output.txt', 'w', stdout);
// #endif

	int t = 1;
	while (t--) {
		cout << solve();
	}
}