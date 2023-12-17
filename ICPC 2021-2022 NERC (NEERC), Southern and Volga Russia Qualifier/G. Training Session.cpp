#include <bits/stdc++.h>

using namespace std;

using T = int;

#define ll long long
#define pii pair<T, T>
#define snd second
#define fst first
#define vi vector<T>
#define pb push_back
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)

// O(nlog(n))

int main(){
    ll n;
    cin>>n;
    vector<pii> v(n);
    map<int, int> top, dif;
    fore(i, 0, n){
        cin>>v[i].fst>>v[i].snd;
        top[v[i].fst]++;
        dif[v[i].snd]++;
    }
    ll non = 0;
    for(auto p : v){
        ll top_x = top[p.fst] - 1;
        ll dif_x = dif[p.snd] - 1;
        non += (top_x * dif_x); 
    }
    //nCr
    ll total = (n) * (n - 1) * (n - 2) / 6;
    ll ans = total - non;
    cout << ans << "\n";
    return 0;
}