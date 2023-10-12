#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, M;
	cin >> N >> M;

	ll ans = 0;
	if (2 * N > M) {
		cout << M / 2 << endl;
		return 0;
	} else {
		ans += N;
		M -= 2 * N;
		ans += M / 4;
		cout << ans << endl;
		return 0;
	}

	return 0;
}