#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define fst first
#define snd second
#define fore(i,a,b) for(int i = a, to = b; i < to; i++)
#define ll long long


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, x;
    cin>>n>>m;
    priority_queue<pii> pq;
    fore(i, 0, n){
        cin>>x;
        pq.push({x, i});
    }
    int e;
    fore(i, 0, m){
        cin>>e;
        pii curr = pq.top();

        while(curr.fst >= e){
            pq.pop();
            curr.fst %= e;
            pq.push(curr);
            curr = pq.top();
        }
    }
    vector<int> ans(n);
    while(!pq.empty()){
        pii curr = pq.top();
        pq.pop();
        ans[curr.snd] = curr.fst;
    }
    fore(i, 0, n){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}