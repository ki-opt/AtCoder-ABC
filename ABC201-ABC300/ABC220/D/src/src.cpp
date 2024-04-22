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
	ll N; cin >> N;
	queue<int> que;
	rep(i,N) {
		int a;
		cin >> a;
		que.push(a);
	}

	vector<vector<mint>> dp(N-1,vector<mint>(10,0));
	int x = que.front(); que.pop();
	int y = que.front(); que.pop();
	dp[0][(x+y)%10] += 1;
	dp[0][(x*y)%10] += 1;
	repp(i,1,N-1) {
		y = que.front(); que.pop();
		rep(j,10) {
			if (dp[i-1][j] == 0) continue;
			dp[i][(y+j)%10] += dp[i-1][j];
			dp[i][(y*j)%10] += dp[i-1][j];
		}
	}

	rep(j,10) {
		cout << dp[N-2][j].val() << endl;
	}

	return 0;
}