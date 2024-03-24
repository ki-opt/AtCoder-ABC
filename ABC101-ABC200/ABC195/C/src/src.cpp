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
	if (N < 1000) {
		cout << 0 << endl;
		return 0;
	}
	ll m_val = 9999, val = 1000, keta = 3;
	ll ans = 0;
	while (N - val * 10 >= 0) {
		ans += (m_val - val + 1) * (keta / 3);
		val *= 10;
		m_val = m_val * 10 + 9;
		keta++;
	}
	cout << ans + (N - val + 1) * (keta / 3) << endl;

	return 0;
}