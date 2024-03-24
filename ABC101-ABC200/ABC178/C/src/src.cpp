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
ll MOD = 1e9+7;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N; cin >> N;
	mint ans = 1, m1 = 1, m2 = 1;
	rep(i,N) {
		ans *= 10;
		m1 *= 9;
		m2 *= 8;
	}
	ans -= ((m1 * 2) - m2);
	cout << ans.val() << endl;
	return 0;
}