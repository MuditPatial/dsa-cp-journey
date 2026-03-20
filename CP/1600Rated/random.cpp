#include <bits/stdc++.h>
using namespace std;



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n,k,x;
        cin>>n>>k>>x;

        vector<int>a(n);

        for(int &i : a) cin>>i;
        a.push_back(1e-9);
        a.push_back(1e9);

        sort(a.begin(),a.end());
        n+=2;
        int l=0,r=x;
        int ans=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            int f=0;

            a[0]=-mid,a[n-1]=x+mid;

            for(int i=1;i<n;i++){
                f+= max(0,(a[i]-mid)-(a[i-1]+mid)+1);
            }

            if(f>=k){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }



        }
        a[0] = - ans, a[n - 1] = x + ans;
        int j = 0;
        for (int i = 1; i < n; i++)
    		for (j = max(j, a[i - 1] + ans); j <= min((a[i] - ans), x) && k; j++)
    			cout << j << ' ', k--;
    	cout << '\n';
    }
}