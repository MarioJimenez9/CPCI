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

int subA[200005], parent[200005], color[200005];
vector<int> g[200005];

void dfs(int u, int p = -1){
    subA[u] = 1;
    parent[u] = p;
    for(int v : g[u]){
        if(v == p)continue;
        dfs(v, u);
        subA[u] += subA[v];
    }
}

void colorSubTree(int u, int p){
    color[u] = 1;
    for(int v : g[u]){
        if(v == p)continue;
        colorSubTree(v, u);
    }
}

int main(){
    int n, u, v;
    cin>>n;
    fore(i, 0, n - 1){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1);

    fore(i, 1, n + 1){
        if(subA[i] == n / 2){
            colorSubTree(i, parent[i]);
            cout<<"YES\n";
            fore(k, 1, n + 1){
                cout << color[k] << " ";
            }
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}