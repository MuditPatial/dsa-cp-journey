#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    string s;

    cin>>s;
    int pos=0,neg=0;

    for(int i=0;i<n;i++){
        s[i]=='-'?neg++:pos++;
    }

    int q;
    cin>>q;


    while(q--){
        int a,b;
        cin>>a>>b;

        long long num = 1LL*b*(neg-pos);

        long long den = a-b;

        if(neg==pos){
            cout<<"YES \n";
            continue;
        }
        
        if(den==0 || num%den != 0 || (num/den > pos) || (num/den < -neg) ){
            cout<<"NO \n";
        }
        else{
            cout<<"YES \n";
        }

    }

    

    return 0;

}