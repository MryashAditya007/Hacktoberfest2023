
/* Problem link: https://www.codechef.com/problems/MAXMINK  */

#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		int a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int j = 0; j < n; j++)
			cin >> b[j];

		int dp[k + 1][1601] ;
		for (int j = 0; j <= k; j++) {
			for (int s = 0; s <= 1600; s++) {
				dp[j][s] = -1;
			}
		}

		dp[0][0] = 0;

		for (int i = 0; i < n; i++) {
			int val = a[i];
			for (int j = k - 1; j >= 0; j--) {
				for (int s = 0; s <= 1600; s++) {
					if (dp[j][s] != -1) {
						dp[j + 1][s + val] = max(dp[j + 1][s + val], dp[j][s] + b[i]);
					}
				}
			}
		}

		int ans = 0;
		for (int s = 0; s <= 1600; s++) {
			ans = max(ans, min(s, dp[k][s]));
		}

		cout << ans << "\n";
	}
	return 0;
}