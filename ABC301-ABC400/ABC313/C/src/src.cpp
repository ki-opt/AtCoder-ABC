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
	vector<ll> A(N);
	ll sum = 0;
	rep(i,N) {
		cin >> A[i];
		sum += A[i];
	}

	sort(A.begin(),A.end());
	ll ans = 0;
	ll ave = sum / N, res = sum % N;
	vector<ll> B(N,ave);

	for (ll i = N - res; i < N; i++) {
		B[i]++;
		cerr << B[i] << endl;
	}
	for (ll i = 0; i < N; i++) {
		ans += abs(A[i] - B[i]);
	}
	cout << ans / 2 << endl;
	return 0;
}