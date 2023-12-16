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

// O(nlog(n))
int main(){
    double n;
    cin>>n;
    vi v(n);
    map<ll, ll> mp;
    double sum = 0;
    fore(i, 0, n){
        cin>>v[i];
        mp[ v[i] ]++;
        sum += v[i];
    }
    double mean = sum / n;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        double target = 2 * mean - v[i];
        if(target < 0)continue;
        int combinations = mp[target];
        if(target == v[i])combinations--;
        mp[ v[i] ]--;
        ans += combinations;
    }
    cout << ans << "\n";
    return 0;
}