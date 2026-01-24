#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int bal = 0;
        bool bad=false;
        for(char c : s){
            bal += (c == '(' ? 1 : -1);
            if(bal<0) bad=true;

        }

        if(bal != 0){
            cout << -1 << '\n';
            continue;
        }

        bal=0;

        if(bad){
            bad=false;
            for(int i=0;i<n;i++){
                if(s[i]=='(')bal++;
                else bal--;

                if(bal>0){
                    bad=true;
                    break;
                }
            }
        }
    
        bal=0;
        if(!bad){
            cout<<"1 \n";
            for(int i=0;i<n;i++){
                cout<<"1 ";
            }
            cout<<'\n';
        }
        else{
            bal=0;
            cout<<"2 \n";
            for(int i=0;i<n;i++){
                bal += (s[i]=='(')? 1 : -1;

                if(bal>0) cout<<"1 ";
                else if(bal <0) cout<<"2 ";
                else{
                    if(s[i]==')')cout<<"1 ";
                    else cout<<"2 ";
                }
            }
            cout<<'\n';
        }



        
    }
}
