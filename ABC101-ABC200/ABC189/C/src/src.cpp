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
	ll N; cin >> N;
	vector<pair<ll,ll>> pairs(N);
	vector<ll> A(N); 
	rep(i,N) {
		cin >> A[i];
		pairs[i] = {A[i],i};
	}

	ll ans = 0;
	rep(i,N) {
		ll tmp = 0;
		ll j = i + 1;
		while (j < N && A[i] <= A[j]) j++;
		tmp += (j-1 - i) * A[i];
		j = i - 1;
		while (j >= 0 && A[i] <= A[j]) j--;
		tmp += (i-(j+1)) * A[i];
		ans = max(ans,tmp+A[i]);
	}
	cout << ans << endl;

	/*
	sort(pairs.begin(),pairs.end());

	ll ans = pairs[0].first * N;
	repp(i,1,N) {
		if (pairs[i].second > pairs[i-1].second) {
			ans = max(ans,pairs[i].first * (N - (pairs[i-1].second + 1)));
		} else {
			ans = max(ans,pairs[i].first * (pairs[i-1].second - 1));
		}
	}
	cout << ans << endl;
	
	/*
	sort(A.begin(),A.end());
	ll ans = 0;
	rep(i,N) {
		ans = max(ans,A[i] * (N-i));
	}
	cout << ans << endl;
	*/

	return 0;
}