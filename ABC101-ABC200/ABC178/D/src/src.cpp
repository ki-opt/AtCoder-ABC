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
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int S;

int main() {
	cin >> S;
	vector<mint> dp(S+1, 0);
	dp[0] = 1;
	for (int v = 1; v <= S; ++v) {
		for (int d = 0; d <= v - 3; ++d) dp[v] += dp[d];
	}

	cout << dp[S].val() << endl;
	return 0;
}