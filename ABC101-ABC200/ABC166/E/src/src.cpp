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
	vector<vector<ll>> vec(200000);
	rep(i,N) {
		cin >> A[i];
	}
	ll ans = 0;
	unordered_map<ll,ll> umap;
	rep(i,N) {
		ans += umap[i-A[i]];
		umap[i+A[i]]++;
	}
	cout << ans << endl;
	/*
	// 2*10^5以下になることを使用する？ペアになり得るのは
	rep(i,200001) {
		if (vec[i].size() == 0) continue;
		for (auto v : vec[i]) {
			
		}
	}
	*/

	return 0;
}