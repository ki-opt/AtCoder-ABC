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
	ll H, W, N; cin >> H >> W >> N;
	vector<ll> A(N), B(N);
	vector<pair<ll,ll>> pairs_a(N), pairs_b(N);
	rep(i,N) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		pairs_a[i] = {A[i],i};
		pairs_b[i] = {B[i],i};
	}

	sort(pairs_a.begin(),pairs_a.end());
	sort(pairs_b.begin(),pairs_b.end());

	vector<ll> row_num(N), col_num(N);
	row_num[0] = pairs_a[0].first;
	col_num[0] = pairs_b[0].first;
	repp(i,1,N) {
		if (pairs_a[i].first == pairs_a[i-1].first) row_num[i] = row_num[i-1];
		else row_num[i] = row_num[i-1] + (pairs_a[i].first - pairs_a[i-1].first) - 1;

		if (pairs_b[i].first == pairs_b[i-1].first) col_num[i] = col_num[i-1];
		else col_num[i] = col_num[i-1] + (pairs_b[i].first - pairs_b[i-1].first) - 1;
	}

	rep(i,N) {
		A[pairs_a[i].second] -= row_num[i];
		B[pairs_b[i].second] -= col_num[i];
	}

	rep(i,N) {
		cout << A[i]+1 << " " << B[i]+1 << endl;
	}


	return 0;
}