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

unordered_map<ll,ll> umap;

ll dfs(ll n) {
	if (n < 2) return 0;
	if (umap.count(n) > 0) return umap[n];
	if (n % 2 == 0) {
		umap[n] = dfs(n/2) + dfs(n/2) + n;
	} else {
		umap[n] = dfs(n/2) + dfs(n/2+1) + n;
	}
	return umap[n];
}

int main() {
	ll N; cin >> N;
	cout << dfs(N) << endl;
	return 0;
}