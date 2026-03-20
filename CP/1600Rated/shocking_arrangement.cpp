#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<long long> pos, neg;

        long long maxx=INT_MIN,minn=INT_MAX;

        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            if(x >= 0) pos.push_back(x);
            else neg.push_back(x);
            
            maxx=max(maxx,x);
            minn=min(minn,x);

        }

        bool cond = true;

        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end(), greater<long long>());

        long long sum = 0;
        vector<long long> ans;

        int i = 0, j = 0;

        while(i < pos.size() || j < neg.size()){
            if(abs(sum) >= (maxx-minn)){
                cond=false;
                break;
            }
            if(sum <= 0){
                if(i < pos.size()){
                    sum += pos[i];
                    ans.push_back(pos[i]);
                    i++;
                }else{
                    sum += neg[j];
                    ans.push_back(neg[j]);
                    j++;
                }
            }else{
                if(j < neg.size()){
                    sum += neg[j];
                    ans.push_back(neg[j]);
                    j++;
                }else{
                    sum += pos[i];
                    ans.push_back(pos[i]);
                    i++;
                }
            }
        }
        if(!cond){
            cout<<"NO\n";
            continue;
        }
        
        cout << "YES\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
