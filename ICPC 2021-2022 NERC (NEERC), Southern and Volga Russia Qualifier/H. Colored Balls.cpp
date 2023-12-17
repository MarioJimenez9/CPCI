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


// O(1)
int main(){
    vi v(3);
    cin>>v[0]>>v[1]>>v[2];

    sort(v.begin(), v.end());
    if(!v[0] && !v[1]){
        cout << "-1\n";
        return 0;
    }
    if((v[1] - v[0]) % 2 || (v[2] - v[1]) % 2){
        cout << "-1\n";
        return 0;
    }

    int ans = (v[2] - v[1]) + (v[1] - v[0]) / 2;
    cout << ans << "\n";
    
    return 0;
}