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
#include <numeric>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)


int main() {
	ll N, M, K; cin >> N >> M >> K;
	if (N > M) swap(N,M);

	ll lcm_val = lcm(N,M);
	
	ll l = 0, r = 2 * 1e18;
	ll mid = (l + r) / 2;
	while (r > l + 1) {
		ll v = mid / N + mid / M - 2 * (mid / lcm_val);
		if (v >= K) r = mid;
		else if (v < K) l = mid;
		mid = (l + r) / 2;
	}
	cout << r << endl;
	return 0;
}