// don't think just do
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

// void solve() {
//     // cout << "Let's do it" << endl;
//     int n;
//     cin >> n;

//     int xor_till_last = 0;
//     int xor_till_second_last = 0;

//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//         if(i != n-1) xor_till_second_last ^= a[i];
//         xor_till_last ^= a[i];
//     }

//     int sum = accumulate(a.begin(), a.end(), 0);
//     if(sum == 0){
//         cout << 0 << endl;
//         return;
//     }

//     if(!(n&1)){
//         if(xor_till_last == 0){
//             cout << 1 << endl;
//             cout << 1 << " " << n << endl;
//             return;
//         }
//         // cout << xor_till_last << " " << xor_till_second_last << endl;
//         cout << 2 << endl;
//         cout << 1 << " " << n << endl;
//         cout << 1 << " " << n << endl;
//         return;
//     }
//     else{
//         if(xor_till_last == 0 || xor_till_second_last == a[n-1]){
//             cout << 1 << endl;
//             cout << 1 << " " << n << endl;
//             return;
//         }
//         if(a[n-1] == 0 and xor_till_second_last != 0){
//             cout << 1 << endl;
//             cout << 1 << " " << n << endl;
//             cout << 1 << " " << n << endl;
//             return;
//         }
//         if(xor_till_second_last != 0 and a[n-1] != 0){
//             cout << 4 << endl;
//             cout << 1 << " " << n-1 << endl;
//             cout << 1 << " " << n-1 << endl;
//             cout << n-1 << " " << n << endl;
//             cout << n-1 << " " << n << endl;
//             return;
//         }
//         if(xor_till_second_last == 0 and a[n-1] != 0){
//             cout << 3 << endl;
//             cout << 1 << " " << n-1 << endl;
//             cout << n-1 << " " << n << endl;
//             cout << n-1 << " " << n << endl;
//             return;
//         }
//     }

// }

void solve(){
//     // cout << "Let's do it" << endl;
    int n;
    cin >> n;

    int xor_till_last = 0;
    int xor_till_second_last = 0;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(!(n&1)){
        cout << 2 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
    }
    else{
        cout << 4 << endl;
        cout << 1 << " " << n-1 << endl;
        cout << 1 << " " << n-1 << endl;
        cout << n-1 << " " << n << endl;
        cout << n-1 << " " << n << endl;
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
