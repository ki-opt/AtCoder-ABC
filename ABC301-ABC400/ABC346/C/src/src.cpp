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
	rep(i,N) {
		cin >> A[i];
	}
	
	sort(A.begin(),A.end());
	ll ans = 0;
	ll val = 0;
	for (auto a : A) {
		if (val + 1 != a && val != a) {
			if (a > K) {
				ans += (K-val) * (2*(val+1)+(K-val-1)) / 2;
			} else {
				ans += (a-(val+1)) * (2*(val+1)+(a-(val+1)-1)) / 2;
			}
		}
		val = a;
		if (val > K) break;
	}
	if (val < K - 1) {
		ans += (K-val) * (2*(val+1)+(K-val-1)) / 2;
	}

	cout << ans << endl;
	/*
	ll ans = 0;
	repp(i,1,K+1) {
		if (mp.count(i) == 0) ans += i;
	}
	*/


	return 0;
}