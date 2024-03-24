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
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N; cin >> N;
	vector<ll> A(N); 
	rep(i,N) cin >> A[i];

	sort(A.begin(),A.end(),greater<ll>());
	ll total = 0;
	rep(i,N) total += A[i];

	ll ans = 0, minus = 0;
	rep(i,N) {
		ans += A[i] * (N - i) - total;
		ans += minus - A[i] * i;
		total -= A[i];
		minus += A[i];
	}
	cout << ans / 2 << endl;

	return 0;
}