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
#include <set>
#include <math.h>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, K; cin >> N >> K;
	vector<ll> A(N);
	ll total = 0;
	rep(i,N) {
		cin >> A[i];
		total += A[i];
	}
	if (total <= K) {
		ll ans = 0;
		for (auto a: A) ans += (a+1) * a / 2;
		cout << ans << endl;
		return 0;
	}

	sort(A.begin(),A.end(),greater<ll>());
	ll left = -1, right = 2*1e9+1;
	ll mid = (right + left) / 2;
	while (left + 1 < right) {
		ll k = 0;
		rep(i,N) {
			if (mid <= A[i]) {
				k += (A[i] - mid);
			} else {
				break;
			}
		}
		if (k > K) left = mid;
		else right = mid;
		mid = (left + right) / 2;
	}
	
	/*
	ll ans = 0, k = 0;
	rep(i,N) {
		if (A[i] <= left) continue;
		ll n = A[i]-left;
		if (k + n >= K) {
			n = K - k;
			ans += n * (2*A[i] - (n-1)) / 2;
		} else {
			ans += n * (2*A[i] - (n-1)) / 2;
		}
		k += n;
		if (k >= K) break;
	}
	*/
	ll ans = 0, rem = K;
	for (auto i : A) {
		if (i > right) {
			ans += (right+1+i) * (i - right) / 2;
			rem -= i - right;
		} 
	}
	cout << ans + rem * right << endl;
	

	return 0;
}