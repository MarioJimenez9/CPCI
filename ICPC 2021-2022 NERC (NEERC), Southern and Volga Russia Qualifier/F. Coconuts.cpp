#include <bits/stdc++.h>

using namespace std;

using T = long long;

#define ll long long
#define pii pair<T, T>
#define snd second
#define fst first
#define vi vector<T>
#define pb push_back
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)

int main(){
    int n;
    cin>>n;
    map<ll, ll> mp;
    vi v(n);
    ll mx = 0;
    fore(i, 0, n){
        cin>>v[i];
        mp[ v[i] ]++;
        mx = max(mx, v[i]);
    }
    ll ans = max(mp[1], mx);
    fore(i, 2, sqrt(mx) + 1){
        ll ex = i;
        ll tmp = 0;
        while(ex <= mx){
            tmp += (mp[ex] * ex);
            ex *= i;
        }
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
    return 0;
}