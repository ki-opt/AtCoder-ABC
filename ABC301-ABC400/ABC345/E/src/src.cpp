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
	ll N, K; cin >> N >> K;
	vector<ll> C(N), V(N);
	vector<vector<pair<ll,ll>>> cv(N);
	rep(i,N) {
		cin >> C[i] >> V[i]; C[i]--;
		cv[C[i]].push_back({i,V[i]});
	}

	vector<int> remove;
	rep(i,N) {
		rep(j,cv[i].size()-1) {
			map<pair<int,int>,int> dup;
			while (j < N-1 && cv[i][j].first+1 == cv[i][j+1].first) {
				dup[{cv[i][j].second,cv[i][j].first}]++;
				dup[{cv[i][j+1].second,cv[i][j+1].first}]++;
				j++;
			}
			for (auto s : dup) {
				remove.push_back(s.second);
			}
		}
	}

	return 0;
}