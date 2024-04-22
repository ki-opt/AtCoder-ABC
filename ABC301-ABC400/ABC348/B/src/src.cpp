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
	ll N; cin >> N;
	vector<ll> X(N), Y(N);
	rep(i,N) cin >> X[i] >> Y[i];

	vector<ll> ans;
	rep(i,N) {
		ll tmp = 0, index = -1;
		rep(j,N) {
			if (i == j) continue;
			ll val = (X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
			if (val > tmp) {
				tmp = val, index = j;
			}
		}
		ans.push_back(index);
	}

	for (auto a: ans) cout << a+1 << endl;

	return 0;
}