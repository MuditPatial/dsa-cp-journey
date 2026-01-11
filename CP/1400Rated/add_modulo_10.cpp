#include <bits/stdc++.h>
using namespace std;

bool valid(int n1,int n2){
    if(n1==n2) return true;
    int diff = n2-n1;
    int st=n1%10;

    diff%=20;
    vector<int>vec={2,4,8,6};

    int i=0;
    while(i<4){
        if(vec[i]==st) break;
        i++;
    }

    while(diff>0){
        diff-=vec[i%4];
        i++;
    }
    return diff==0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i=0;i<n;i++) cin>>a[i];

        
        for (auto &x:a) {
            if (x%10 == 5) x+=5;
        }

        bool hasZero=false;
        for (auto &x:a) {
            if (x%10 ==0) hasZero =true;
            if(x%2==1) x+= x%10;
        }

        bool ok =true;

        sort(a.begin(),a.end());

        if(hasZero){
            
            for (int i=1;i<n;i++) {
                if (a[i] != a[0]) {
                    ok = false;
                    break;
                }
            }
        } 
        else {
            for(int i=1;i<n;i++){
                if(!valid(a[i-1],a[i])){
                    ok=false;
                    break;
                }
            }
            
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
