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
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N; cin >> N;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];

	ll ans = 0;
	ll kyaku = 0;
	rep(i,N) {
		kyaku += A[i];
		if (kyaku < 0) {
			ans += abs(kyaku);
			kyaku = 0;
		}
	}
	/*if (ans > kyaku) cout << ans << endl;
	else */cout << kyaku << endl;


	return 0;
}