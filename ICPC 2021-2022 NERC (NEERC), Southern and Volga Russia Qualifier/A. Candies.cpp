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

// O(n ^ 2)

int main(){
    int n, a, b;
    cin>>n>>a>>b;
    int ans = n;
    fore(i, 1, n){
        if(i * a + (i + 1) * b > n)break; // Return earlier doesn't need it
        fore(j, i + 1, n){
            int gift = i * a + j * b;
            if(gift > n)break;
            ans = min(ans, n - gift);
        }
    }
    cout<<ans<<"\n";
    return 0;
}