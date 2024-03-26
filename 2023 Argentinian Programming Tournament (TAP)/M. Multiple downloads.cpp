#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define fst first
#define snd second
#define fore(i,a,b) for(int i = a, to = b; i < to; i++)
#define ll long long


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    double n, d;
    cin>>n>>d;
    char c;
    double s;
    priority_queue<double, vector<double>, greater<double>> nn, pp;
    fore(i, 0, n){
        cin>>c>>s;
        if(c == 'P')pp.push(s);
        else nn.push(s);
    }
    double v1 = 0.0;
    double v2 = 0.0;
    if(pp.size() && nn.size()){
        v1 = d * .75 / pp.size();
        v2 = d * .25 / nn.size();
    }
    if(pp.empty())v2 = d / nn.size();
    if(nn.empty())v1 = d / pp.size();

    double acu1 = 0.0, acu2 = 0.0;
    double time = 0.0;
    while(!pp.empty() && !nn.empty()){
        double c1 = pp.top() - acu1;
        double c2 = nn.top() - acu2;
        if(c1 / v1 > c2 / v2){
            double t = c2 / v2;
            time += t;
            acu2 += c2;
            acu1 += (t * v1);
            nn.pop();
            if(!nn.empty())v2 = d * .25 / nn.size();
            else v1 = d / pp.size();
        }
        else{
            double t = c1 / v1;
            time += t;
            acu1 += c1;
            acu2 += (t * v2);
            pp.pop();
            if(!pp.empty())v1 = d * .75 / pp.size();
            else v2 = d / nn.size();
        }
    }

    while(!pp.empty()){
        double cc = pp.top() - acu1;
        pp.pop();
        acu1 += cc;
        time += (cc / v1);
        if(!pp.empty())v1 = d / pp.size();
    }
    while(!nn.empty()){
        double cc = nn.top() - acu2;
        nn.pop();
        acu2 += cc;
        time += (cc / v2);
        if(pp.empty())v2 = d / nn.size();
    }
    cout<<fixed<<setprecision(10)<<time<<"\n";
    return 0;
}