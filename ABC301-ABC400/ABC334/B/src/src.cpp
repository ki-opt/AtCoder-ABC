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
	ll A, M, L, R;
	cin >> A >> M >> L >> R;

	//A += (ll)pow(10,18);
	if (A < 0) {
		L += (-A);
		R += (-A);
	} else if (A > 0) {
		L -= A;
		R -= A;
	}

	ll ans;
	if (L < 0 && R <= 0) {
		ll l = abs(L), r = abs(R);
		ans = l / M;
		if (r % M == 0) ans = ans - (r / M) + 1;
		else ans -= r / M;
	} else if (L <= 0 && R >= 0) {
		ans = R / M;
		ans += (-L) / M;
		ans++;
	} else {
		ans = R / M;
		if (L % M == 0) ans = ans - (L / M) + 1;
		else ans -= L / M;
	}
	/*
	if (A >= L) {
		if (A >= R) {
			ans = (A - R) / M;
			ans += ()
		} else if (A < R) {
			ans = (R - A) / M;
			ans += (A - L) / M;
		}
	} else if (A <= L) {
		ans = (L - A) / M;
		ans = (R - A) / M - ans;
	}*/
	cout << ans << endl;

	return 0;
}