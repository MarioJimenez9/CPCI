#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    b += d;
    a += c;
    if(a > b){
        cout<<"A\n";
    }
    else if(b > a){
        cout<<"P\n";
    }
    else cout<<"D\n";
    return 0;
}