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
	string S; cin >> S;
	vector<vector<ll>> v(26);
	rep(i,S.size()) v[S[i]-'a'].push_back(i);

	vector<int> index(26,0);
	ll ans = 0, total = S.size()-1;
	rep(i,26) if (v[i].size() > 1) {
		ans++;
		break;
	}
	rep(i,S.size()-1) {
		ll tmp = index[S[i]-'a'];
		ans += total - ((ll)v[S[i]-'a'].size() - (tmp + 1));
		total--;
		index[S[i]-'a']++;
	}
	cout << ans << endl;


	return 0;
}