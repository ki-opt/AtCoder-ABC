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
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Node{
	ll i, j;
};

int main() {
	ll H, W, C; cin >> H >> W >> C;
	vector<vector<ll>> A(H,vector<ll>(W));
	rep(i,H) rep(j,W) cin >> A[i][j];

	ll ans = LLONG_MAX;

	return 0;
}