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
	ll N, K; cin >> N >> K;
	vector<ll> A(N); rep(i,N) cin >> A[i];

	ll left = 0, right = 1e9+1;
	ll mid = (left + right) / 2;
	while (left + 1 < right) {
		ll cnt = 0;
		rep(i,N) {
			cnt += A[i] / mid;
			if (A[i] % mid == 0) cnt--;
		}
		if (cnt <= K) {
			right = mid;
		} else {
			left = mid;
		}
		mid = (left + right) / 2;
	}
	cout << right << endl;

	return 0;
}