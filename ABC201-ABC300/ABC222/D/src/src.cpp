#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N; cin >> N;
	vector<int> a(N), b(N);
	rep(i,N) cin >> a[i];
	rep(i,N) cin >> b[i];
	
	vector<mint> dp(3001,0);
	repp(i,a[0],b[0]+1) {
		if (i == a[0]) dp[i] = 1;
		else dp[i] += dp[i-1] + 1;
	}
	repp(i,b[0]+1,3001) dp[i] = dp[i-1];

	mint ans = 1;
	repp(i,1,N) {
		repp(c,a[i],b[i]+1) {
			//ans += dp[c];
			if (c != a[i]) dp[c] = dp[c] + dp[c-1];
		}
		repp(c,b[i]+1,3001) dp[c] = dp[c-1];
	}
	cout << dp[3000].val() << endl;

	/*
	mint bottom = 0;
	repp(i,1,N) {
		if (a[i] != a[i-1]) bottom += bottom
	}
	*/


	return 0;
}