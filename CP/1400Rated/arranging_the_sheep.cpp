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

        vector<int> pos;
        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                pos.push_back(i);
            }
        }

        int k = pos.size();
        if(k == 0){
            cout << 0 << '\n';
            continue;
        }


        
        
    }

    return 0;
}
