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

void chmin(ll &a, ll &b) {
	if (a < b) {
		ll tmp = a;
		a = b;
		b = tmp;
	}
}

int main() {
	ll A, B;
	cin >> A >> B;
	chmin(A,B);
	ll ans = 0;
	while (A != B) {
		if (A % B == 0) {
			ans += A / B;
			break;
		}
		ll tmp = A / B;
		A -= B * tmp;
		ans += tmp;
		chmin(A,B);
		if (A == 1 && B == 0) break;

	}
	/*
	while (A != B) {
		if (A > B) A -= B;
		else B -= A;
		ans++;
	}
	*/
	if (ans == 0) cout << 0 << endl;
	else cout << ans - 1 << endl;
	return 0;
}