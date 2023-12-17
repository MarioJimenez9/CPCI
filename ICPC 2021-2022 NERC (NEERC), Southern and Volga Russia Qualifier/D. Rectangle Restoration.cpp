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
    double a, b;
    cin>>a>>b;
    if(a / 2 >= b){
        cout << -1 << "\n";
        return 0;
    }
    double ans = 1e18;
    //adyacents sides of b
    if(2 * a > b)ans = min(ans, a * 2);
    //b shares both sides of a
    if(a < b)ans = min(ans, 2 * b - a);
    //b shares only one side of a
    ans = min(ans, b + (a / 2));

    cout << fixed << setprecision(8) << ans << "\n";
}