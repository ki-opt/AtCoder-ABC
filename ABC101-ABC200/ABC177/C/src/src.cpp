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
	vector<ll> A(N);
	vector<mint> val(N,0);
	rep(i,N) {
		cin >> A[i];
		val[0] += A[i];
	}
	repp(i,1,N) val[i] = val[i-1] - A[i-1];
	
	mint ans = 0;
	rep(i,N-1) {
		ans += A[i] * val[i+1];
	}
	cout << ans.val() << endl;

	return 0;
}