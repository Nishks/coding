#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

// int dp[4003];

// int recursion(vector<int> &cuts, int len){
// 	// base case
// 	if(len < 0) return INT_MIN;
// 	if(len == 0) return 0;
// 	if(dp[len] != -1) return dp[len];

// 	int ans = INT_MIN;
// 	// pick a lenth from cuts and make that cuts on len
// 	for(auto cut : cuts){
// 		ans = max(ans, 1 + recursion(cuts, len-cut));
// 	}

// 	return dp[len] = ans;
// }

int solve(){
	int n,a,b,c;
	cin >> n >> a >> b >> c;

	if(n < min({a,b,c})) return 0;

	// memset(dp, -1, sizeof(dp));
	vector<int> v = {a,b,c};
	// return recursion(v,n);

	int dp[n+1] = {0};
	sort(v.begin(), v.end());

	for(auto cut : v){
		// cout << "cut " << cut << " ";
		for(int i = cut; i <= n; i++){
			int rem = i-cut;
			// cout << "cut " << cut << " i " << i << " rem " << rem << endl;
			if(rem == 0 or dp[rem] != 0)
				dp[i] = max(dp[i], dp[rem]+1);
		}

		// cout << "for this size cut " << cut << " dp will look like ";
		// for(auto it : dp) cout << it << " ";
		// cout << endl;
	}

	return dp[n];
}

int32_t main(){

// #ifndef ONLINE_JUDGE
// 	freopen('input.txt', 'r', stdin);
// 	freopen('output.txt', 'w', stdout);
// #endif
	
	int t = 1;
	while(t--){
		cout << solve() << endl;
	}
}