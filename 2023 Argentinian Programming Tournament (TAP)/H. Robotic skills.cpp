#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pii> mp(n * n + 1);
    vector<vector<int>> g(n, vector<int>(n));
    fore(i, 0, n){
        fore(j, 0, n){
            cin>>g[i][j];
            mp[g[i][j]] = {i, j};
        }
    }
    vector<int> row(n, 0), col(n, 0);
    int mx = 0;
    for(int i = n * n; i > 0; i--){
        int r = mp[i].fst, c = mp[i].snd;
        int pc = col[c], pr = row[r];
        row[r] = max(row[r], pc + 1);
        col[c] = max(col[c], pr + 1);
        mx= max({mx, row[r], col[c]});
    }
    cout<<mx<<"\n";
	return 0;
}