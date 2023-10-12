#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N;
	cin >> N;
	vector<ll> A(N);
	ll cnt = 0;
	ll ans = 0;
	ll min_val = LLONG_MAX;
	rep(i,N) {
		cin >> A[i];
		ans += abs(A[i]);
		min_val = min(min_val,abs(A[i]));
		if (A[i] < 0) cnt++;
	}

	if (cnt % 2 == 0) cout << ans << endl;
	else cout << ans - 2 * min_val << endl;


	return 0;
}