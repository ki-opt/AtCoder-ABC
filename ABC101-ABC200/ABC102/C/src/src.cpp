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
	ll N;
	cin >> N;
	vector<ll> A(N), A_rev(N);
	rep(i,N) {
		cin >> A[i];
		A_rev[i] = A[i] - (i + 1);
	}

	sort(A_rev.begin(), A_rev.end());
	ll tmp_p = A_rev[N/2], tmp_m = A_rev[N/2-1];
	ll ans_p = 0, ans_m = 0;
	rep(i,N) {
		ans_p += abs(A_rev[i] - tmp_p);
		ans_m += abs(A_rev[i] - tmp_m);
	}
	if (ans_p < ans_m) {
		cout << ans_p << endl;
	} else {
		cout << ans_m << endl;
	}
	//cout << ans_p << endl;
	//cerr << ans_m << endl;

	return 0;
}