#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        ll a, b;
        cin >> n >> a >> b;

        vector<ll> x(n+1), pref(n+1);
        x[0] = 0;

        for(int i = 1; i <= n; i++)
            cin >> x[i];

        partial_sum(x.begin(), x.end(), pref.begin());

        ll ans = (ll)4e18;

        for(int i = 0; i <= n; i++) {
            ll cost =(a+b) * x[i] + b * (pref[n] - pref[i] - (n-i)*x[i]);

            ans = min(ans, cost);
        }

        cout << ans << "\n";
    }
}
