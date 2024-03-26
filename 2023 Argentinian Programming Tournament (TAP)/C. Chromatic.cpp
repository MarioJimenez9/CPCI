#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define fst first
#define snd second
#define fore(i,a,b) for(int i = a, to = b; i < to; i++)
#define ll long long


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    fore(i, 0, n)cin>>a[i];
    fore(i, 0, n)cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int mx = 0, mn = 2e9;
    fore(i, 0, n){
        mx = max(mx, a[i] + b[i]);
        mn = min(mn, a[i] + b[i]);
    }
    cout<<mx - mn<<"\n";
    return 0;
}



