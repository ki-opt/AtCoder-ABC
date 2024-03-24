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
	ll ans = 0, i = 1;
	while (1) {
		ll tmp = i * (i + 1) / 2;
		if ((N - tmp) % i == 0) ans++; 
		i++;
		if (i * i >= 2 * N) break;
	}
	cout << ans * 2 << endl;

	return 0;
}