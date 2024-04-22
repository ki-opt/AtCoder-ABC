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

int main() {
	ll N, M; cin >> N >> M;
	vector<vector<ll>> B(N,vector<ll>(M));
	rep(i,N) rep(j,M) cin >> B[i][j];

	ll ii = (B[0][0]-1) / 7 + 1, jj = B[0][0] % 7;
	rep(i,N) {
		ll tmp_jj = jj;
		rep(j,M) {
			if ((tmp_jj % 7 == 0 && j + 1 != M) || 
				(ii - 1) * 7 + (tmp_jj % 7 == 0 ? 7 : tmp_jj) != B[i][j]) {
				cout << "No" << endl;
				return 0;
			}
			tmp_jj++;
		}
		ii++;
	}

	/*
	rep(i,N) {
		rep(j,M-1) {
			if (!(B[i][j] % 7 + 1 == B[i][j+1] % 7 && 
					B[i][j] + 1 == B[i][j+1])) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	rep(i,N-1) {
		rep(j,M) {
			if (!(B[i][j] + 7 == B[i+1][j])) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	*/
	cout << "Yes" << endl;


	return 0;
}