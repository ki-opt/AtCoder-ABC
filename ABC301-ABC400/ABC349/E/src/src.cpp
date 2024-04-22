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

bool isReach(vector<vector<int>> &seen) {
	rep(i,3) {
		bool isFound = true;
		rep(j,3) if 
	}
}

int main() {
	vector<vector<ll>> A(3,vector<ll>(3));
	rep(i,3) rep(j,3) cin >> A[i][j];

	vector<vector<int>> seen(3,vector<int>(3,-1));
	int isReach = 0;
	rep(i,4) {
		ll val = LLONG_MIN;
		pair<ll,ll> index;
		rep(i,3) {
			rep(j,3) {
				if (A[i][j] > val && seen[i][j] == -1) {
					val = A[i][j];
					index = {i,j};
				}
			}
		}
		if (isReach == 0) {
			seen[index.first][index.second] = 1;
			isReach = checkReach(seen);
		}
	}

	return 0;
}