#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vll a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll l = 0, r = 1e9 + 5;
    while(l < r) {
        ll m = (l + r + 1) >> 1;
        ll k = 0;
        bool flag = 1;
        for(int i = 0; i < n; i++) {
            ll c = a[i] * m;
            ll q = k + b[i];
            if(c > q) {
                flag = 0;
                break;
            }
            q -= c;
            k = q;
        }
        if(flag) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << l << "\n";
    return 0;
}

