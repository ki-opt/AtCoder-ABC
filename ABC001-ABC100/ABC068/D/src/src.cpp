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
#include <numeric>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

void test(vector<ll> ans, ll K) {
	ll cnt = 0;
	while (*max_element(ans.begin(),ans.end()) >= 50) { 
		auto itr = max_element(ans.begin(),ans.end());
		int index = distance(ans.begin(),itr);
		rep(i,ans.size()) {
			if (i == index) ans[i] -= 50;
			else ans[i]++;
		}
		cnt++;		 
	}
	cerr << cnt << endl;
}

int main() {
	ll N = 50;
	ll K; cin >> K;
	vector<ll> ans(N,0);
	if (K < N) {
		rep(i,K) ans[i] = N;
	} else {
		rep(i,N) ans[i] = N - 1 + K / N;
		rep(i,N) {
			if (i < K%N) ans[i]++;
			else ans[i] -= K%N;
		}
	}

	//test(ans,K);

	cout << ans.size() << endl;
	for (auto a : ans) cout << a << " ";

	return 0;
}