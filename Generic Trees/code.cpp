#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int solve(){
	int n;
	cin >> n;

	map<int,int> m;
	int maxTrapRoom = 1;
	for(auto i  = 0; i < n; i++){
		int d,s;
		cin >> d >> s;
		if(m[d] != 0 and m[d] > s) {;
			m[d] = s;
		}
		else if(m[d] == 0) m[d] = s;
		maxTrapRoom = max(maxTrapRoom, d);
	}

	int maxK = INT_MAX;
	for(int i = 1; i <= maxTrapRoom; i++){
		if(m[i]){
			int distance = i + m[i]/2;
			if(m[i] % 2 == 0) distance = i + m[i]/2 - 1;
			maxK = min(maxK, distance);
		}
	}
	return maxK;

}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while(t--){
		cout << solve() << endl;
	}
}