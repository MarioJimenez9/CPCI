#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d;
    int cont = 0, n, m;

    cin >> n;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int x = 0;
        for(int j = 0; j < n; j++){
            if(s[j] == 'B'){
                x = 0;
            }else{
                x++;
                if(x == 2) {
                    cont++;
                    x = 0;
                }
            }
        }
    }

    cout << cont << "\n";

    return 0;
}