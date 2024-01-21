#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, A;
	cin >> N >> A;
	vector<int> x(N);
	rep(i,N) { cin >> x[i]; }

	vector<vector<vector<ll>>> dp(N,vector<vector<ll>>(N,vector<ll>(51*51,0)));
	dp[0][0][x[0]] = 1;
	repp(i,0,N-1) {
		dp[i+1][0][x[i+1]] = 1;
		rep(j,i+1) {
			rep(k,51*51) {
				if (dp[i][j][k] == 0) continue;
				dp[i+1][j][k] += dp[i][j][k];
				dp[i+1][j+1][k+x[i+1]] += dp[i][j][k];
			}
		}
		/*rep(k,51*51) dp[i][0][k] = dp[i-1][0][k];
		dp[i][0][x[i]] += 1;
		repp(j,1,i+1) {
			repp(k,0,51*51) {
				配るDPに直したい
				if (k < x[i]) {
					if (j > 1) dp[i][j-1][k] = dp[i-1][j-1][k];
				} else {
					if (dp[i-1][j-1][k-x[i]] != 0) {
						if (j > 1) dp[i][j-1][k-x[i]] = dp[i-1][j-1][k-x[i]];
						dp[i][j][k] += dp[i-1][j-1][k-x[i]];
					}
				}
			}
		}*/
	}
	//getchar();
	
	ll ans = 0;
	rep(j,N) {
		rep(k,51*51) {
			if (dp[N-1][j][k] != 0 && k == A * (j+1)) {
				ans += dp[N-1][j][k];
			}
			//if (dp[N-1][j][k] != 0) printf("%d %d %d\n",j,k,dp[N-1][j][k]);
		}
	}
	cout << ans << endl;
	
	//vector<vector<ll>> dp(N,vector<ll>(51*51,0));
	//dp[0][x[0]] = 1;
	/*repp(i,1,N) {
		repp(j,1,51*51-x[i]) {
			if (dp[i-1][j] != 0) {
				dp[i][x[i]+j] = 1;
				dp[i][j] += dp[i-1][j];
			} else if (j == x[i]) {
				dp[i][x[i]] = 1;
			}
		}
	}
	getchar();
	*/
	return 0;
}