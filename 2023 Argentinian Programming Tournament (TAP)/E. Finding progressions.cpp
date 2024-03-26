#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i = a, to = b; i < to; i++)
#define ll long long


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll A, S, L, R;
    cin>>A>>S>>L>>R;
    ll ans = 0;
    fore(d, 1, R - L + 100){
        ll tmp = A, sum = A;
        while(tmp - d >= L){
            tmp -= d;
            sum += tmp;
        }
        ll tmp2 = A;
        while(tmp2 <= R && tmp <= A){
            while(sum > S){
                sum -= tmp;
                tmp += d;
            }
            if(sum == S && && tmp <= A && tmp != tmp2)ans++;
            tmp2 += d;
            sum += tmp2;
        }
    }
    if(S == A)ans++;
    cout<<ans<<"\n";
    return 0;
}