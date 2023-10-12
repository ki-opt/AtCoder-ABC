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
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	vector<ll> B(M), C(M);
	vector<pair<ll,ll>> pairs(M);
	rep(i,M) {
		cin >> B[i] >> C[i];
		pairs[i] = {C[i],B[i]};
	}

	sort(A.begin(),A.end());
	sort(pairs.rbegin(), pairs.rend());
	ll index = 0;
	rep(i,M) {
		rep(j,pairs[i].second) {
			if (pairs[i].first > A[index]) {
				A[index] = pairs[i].first;
				index++;
			} else {
				break;
			}
		}
	}

	ll ans = 0;
	rep(i,N) ans += A[i];
	cout << ans << endl;
	/*
	rep(i,M) {
		if (B[i] > A[B[i]-1]) A[B[i]-1] = B[i];
	}
	ll ans = 0;
	rep(i,N) ans += A[i];
	cout << ans << endl;
	*/

	return 0;
}