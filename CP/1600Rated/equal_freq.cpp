#include <bits/stdc++.h>
using namespace std;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);

		int tc;
		cin >> tc;
		while (tc--) {
				int n;
				cin >> n;
				string s;
				cin >> s;

				// freq holds pairs of (count, character) for each lowercase letter
				vector<pair<int, char>> freq(26);
				for (int i = 0; i < 26; i++) freq[i].second = 'a' + i; // assign character labels
				for (char c : s) freq[c - 'a'].first++; // count occurrences of each letter in s
				sort(freq.rbegin(), freq.rend()); // sort by count descending (ties by char)

				// Choose k (number of distinct letters in target string) that divides n
				// and minimizes the number of changes required.
				int best_k = 1, changes = n;
				for (int k = 1; k <= 26; k++) {
						if (n % k) continue; // every used letter must appear exactly n/k times
						int unchanged = 0;
						for (int i = 0; i < k; i++) unchanged += min(freq[i].first, n / k);
						if (n - unchanged < changes) {
								best_k = k;
								changes = n - unchanged;
						}
				}

				// mp keeps remaining required counts for the chosen best_k letters
				map<char, int> mp;
				for (int i = 0; i < best_k; i++) mp[freq[i].second] = n / best_k;

				string ans(n, ' ');
				// First pass: keep as many original characters as possible if we still need them
				for (int i = 0; i < n; i++) {
						// Note: operator[] inserts a zero for non-chosen letters; these will be cleaned later.
						if (mp[s[i]] > 0) {
								ans[i] = s[i];
								mp[s[i]]--;
						}
				}

				// Second pass: fill remaining positions with any letter that still has quota
				for (int i = 0; i < n; i++) {
						if (ans[i] != ' ') continue; // already fixed in the first pass
						while (!mp.empty() && (*mp.begin()).second == 0) mp.erase(mp.begin()); // drop exhausted/accidentally inserted zeros
						char ch = (*mp.begin()).first; // take the lexicographically smallest available letter
						ans[i] = ch;
						mp[ch]--;
				}

				cout << changes << "\n" << ans << "\n";
		}

		return 0;
}

// Time Complexity (per test case): O(n) — counting + two passes over s + O(26 log 26) for sorting and constant-factor checks
// Space Complexity (per test case): O(n) for the answer string, plus O(26) auxiliary structures
