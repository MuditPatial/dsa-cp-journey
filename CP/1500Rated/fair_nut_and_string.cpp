#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 +7;
int main(){
    string s;
    cin>>s;

    int n;
    n= s.size();

    long long prod =1;
    int cnt=0;

    for(int i=0;i<n;i++){
        if(s[i]=='a') cnt++;

        if(s[i]=='b'){
            prod= (prod*(1+cnt))%MOD;
            cnt=0;
        }
    }
    prod= (prod*(1+cnt))%MOD;
    prod--;

    cout<<prod<<'\n';
    





    return 0;
}