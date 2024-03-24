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
	int H, W; cin >> H >> W;
	vector<string> S(H);
	rep(i,H) cin >> S[i];

	map<pair<ll,ll>,ll> mp;
	rep(i,H) rep(j,W) {
		if (S[i][j] == '.') mp[{i,j}]++;
	}

	ll ans = 0;
	rep(i,H-1) {
		rep(j,W-1) {
			if (mp.count({i,j}) && mp.count({i,j+1}) && mp.count({i+1,j}) && !mp.count({i+1,j+1})) ans++;
			else if (mp.count({i,j}) && mp.count({i,j+1}) && !mp.count({i+1,j}) && mp.count({i+1,j+1})) ans++;
			else if (mp.count({i,j}) && !mp.count({i,j+1}) && mp.count({i+1,j}) && mp.count({i+1,j+1})) ans++;
			else if (!mp.count({i,j}) && mp.count({i,j+1}) && mp.count({i+1,j}) && mp.count({i+1,j+1})) ans++;

			if (!mp.count({i,j}) && !mp.count({i,j+1}) && !mp.count({i+1,j}) && mp.count({i+1,j+1})) ans++;
			else if (!mp.count({i,j}) && !mp.count({i,j+1}) && mp.count({i+1,j}) && !mp.count({i+1,j+1})) ans++;
			else if (!mp.count({i,j}) && mp.count({i,j+1}) && !mp.count({i+1,j}) && !mp.count({i+1,j+1})) ans++;
			else if (mp.count({i,j}) && !mp.count({i,j+1}) && !mp.count({i+1,j}) && !mp.count({i+1,j+1})) ans++;
		}
	}
	cout << ans << endl;


	return 0;
}