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

        int mid = (k)/2;

        long long ans=0;

        for(int i=0;i<k;i++){
            ans+= abs(1LL*pos[mid]-pos[i])-abs(mid-i);
        }

        cout<<ans<<'\n';


        
    }

    return 0;
}
