#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<pair<pair<int,int>,int>>range(n);
    vector<int>right(n);

    for(int i=0;i<n;i++){
        cin>>range[i].first.first>>range[i].first.second;
        range[i].second=i+1;
    }

    sort(range.begin(),range.end(),[](auto &x , auto &y){
        if(x.first.first != y.first.first){
            return x.first.first < y.first.first;
        }
        else if (x.first.second != y.first.second){
            return x.first.second > y.first.second;
        }
        else{
            return x.second<y.second;
        }
    });

    int maxEnd=0;
    int leftIdx=-1,rightIdx=-1;

    for(int i=0;i<n;i++){
        if(maxEnd>=range[i].first.second){
            leftIdx=range[i].second;
            break;
        }
        else{
            maxEnd=range[i].first.second;
            rightIdx=range[i].second;
        }
    }
    if(leftIdx==-1) cout<<"-1 -1 \n";
    else cout<<leftIdx<<" "<<rightIdx<<"\n";
}

