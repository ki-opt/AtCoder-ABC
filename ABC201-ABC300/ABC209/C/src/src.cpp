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
using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N; cin >> N;
	vector<ll> C(N); rep(i,N) cin >> C[i];
	sort(C.begin(),C.end());
	if (C[0] == 1 && C[1] == 1) {
		cout << 0 << endl;
		return 0;
	}

	ll max_val = C[0];
	mint ans = C[0];
	repp(i,1,N) {
		ans *= (C[i] - i);
		max_val = max(max_val,C[i]);
	}
	cout << ans.val() << endl;

	return 0;
}