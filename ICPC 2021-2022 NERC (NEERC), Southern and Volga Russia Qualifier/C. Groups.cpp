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

// O(25 * n)
int main(){
    int n;
    cin>>n;
    vector<vi> d(n, vi(5));
    vi mp(5);
    int szGroup = n / 2;
    fore(i, 0, n){
        fore(k, 0, 5){
            cin>>d[i][k];
            mp[ k ] += d[i][k];
        }
    }
    bool yes = false;
    fore(i, 0, 5){ //iterate over the class on first day
        fore(j, i + 1, 5){ //Iterate over the class on second day 
            if(mp[i] >= szGroup && mp[j] >= szGroup){
                bool tmp = true;
                for(int k = 0; k < n; k++){//Check if the k-th student can attend at least one of the days
                    if(d[k][i] == 0 && d[k][j] == 0) tmp = false;
                }
                yes |= tmp;
            }
        }
    }
    cout << (yes ? "YES" : "NO") << "\n";

    return 0;
}