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

pair<int, string> getLIS(string s, int n){
    vector<int> prevIdx(n, -1);
    vector<int> tailIdx(1, 0);
    fore(i, 1, n){
        if(s[ tailIdx.back() ] <= s[i]){
            prevIdx[i] = tailIdx.back();
            tailIdx.pb(i);
            continue;
        }
        if(s[i] < s[ tailIdx[0] ]){
            tailIdx[0] = i;
            continue;
        }
        int lo = 1, hi = tailIdx.size() - 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(s[ tailIdx[mid] ] <= s[i])lo = mid + 1;
            else hi = mid - 1; 
        }
        prevIdx[i] = tailIdx[lo - 1];
        tailIdx[lo] = i;
    }
    vector<int> lis;
    for(int i = tailIdx.back(); i >= 0; i = prevIdx[i]){
        lis.pb(i);
    }
    reverse(lis.begin(), lis.end());
    pair<int, string> ans = {n - lis.size(), s.substr(lis[0], 1)};
    fore(j, 0, lis[0]){
        ans.snd += s[ lis[0] ];
    }
    fore(i, 1, lis.size()){
        fore(j, 0, lis[i] - lis[i - 1]){
            ans.snd += s[ lis[i] ];
        }
    }
    fore(j, 0, n - lis.back() - 1){
        ans.snd += s[ lis.back() ];
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    pair<int, string> lis = getLIS(s, n);

    cout << lis.fst << "\n";
    cout << lis.snd << "\n";
    return 0;
}