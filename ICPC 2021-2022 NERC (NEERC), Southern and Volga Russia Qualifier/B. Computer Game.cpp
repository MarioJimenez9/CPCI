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

// O(n)

int main(){
    int n;
    cin>>n;
    string a;
    string b;
    cin>>a>>b;
    
    bool no = false;
    fore(i, 1, n - 1){
        if(a[i] == '1' && b[i] == '1')no = true; // Can't go ahead
    }
    
    cout << (no ? "NO" : "YES") << "\n";
}