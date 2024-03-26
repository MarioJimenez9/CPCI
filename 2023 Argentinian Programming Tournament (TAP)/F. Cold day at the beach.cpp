#include <bits/stdc++.h>

using namespace std;

double d(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, w, l;
    double x, y;
    cin >> n >> w >> l >> x >> y;
    vector<double> da(n), dr(n);
    double ba = 1e18, br = 1e18;
    for(int i = 0; i < n; i++) {
        double xt, yt;
        cin >> xt >> yt;
        da[i] = d(x, y, xt, yt);
        ba = min(ba, da[i]);
    }
    for(int i = 0; i < n; i++) {
        double xt, yt;
        cin >> xt >> yt;
        dr[i] = d(x, y, xt, yt);
        br = min(br, dr[i]);
    }
    if(ba < br) {
        cout << "A ";
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (da[i] < br);
        }
        cout << ans << "\n";
    } else {
        cout << "R ";
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (dr[i] < ba);
        }
        cout << ans << "\n";
    }
    return 0;
}

