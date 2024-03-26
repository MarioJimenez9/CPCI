#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define fst first
#define snd second
#define fore(i,a,b) for(int i = a, to = b; i < to; i++)
#define ll long long

int main(){
    int n;
    cin>>n;
    vector<ll> m(5, 0);
    fore(i, 0, n){
        int x;
        cin>>x;
        m[x % 5]++;
    }
    ll ans = m[0];
    ll tmp = 0;
    /// 4 + 1
    tmp = min(m[4], m[1]);
    ans += tmp;
    m[4] -= tmp;
    m[1] -= tmp;
    /// 3 + 2
    tmp = min(m[3], m[2]);
    ans += tmp;
    m[3] -= tmp;
    m[2] -= tmp;
    /// 1 + 1 + 3
    tmp = min(m[1], m[3] * 2) / 2;
    ans += tmp;
    m[1] -= (tmp * 2);
    m[3] -= tmp;
    /// 1 + 2 + 2
    tmp = min(m[2], m[1] * 2) / 2;
    ans += tmp;
    m[1] -= tmp;
    m[2] -= (tmp * 2);
    /// 1 + 1 + 1 + 2
    tmp = min(m[1], m[2] * 3) / 3;
    ans += tmp;
    m[1] -= (tmp * 3);
    m[2] -= tmp;
    /// 2 + 4 + 4
    tmp = min(m[4], m[2] * 2) / 2;
    ans += tmp;
    m[2] -= tmp;
    m[4] -= (tmp * 2);
    /// 3 + 3 + 4
    tmp = min(m[3], m[4] * 2) / 2;
    ans += tmp;
    m[3] -= (tmp * 2);
    m[4] -= tmp;
    /// 1 + 3 + 3 + 3
    tmp = min(m[3], m[1] * 3) / 3;
    ans += tmp;
    m[1] -= tmp;
    m[3] -= (tmp * 3);
    /// 3 + 4 + 4 + 4
    tmp = min(m[4], m[3] * 3) / 3;
    ans += tmp;
    m[3] -= tmp;
    m[4] -= (tmp * 3);
    /// 2 + 2 + 2 + 4
    tmp = min(m[2], m[4] * 3) / 3;
    ans += tmp;
    m[2] -= (tmp * 3);
    m[4] -= tmp;

    fore(i, 1, 5){
        ans += (m[i] / 5);
    }
    cout<<ans<<"\n";

    return 0;
}