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

	vector<ll> ans;
	for (ll i = 1; i * i * i <= N; i++) {
		ll tmp = i * i * i;
		vector<ll> a;
		while (tmp != 0) {
			a.push_back(tmp % 10);
			tmp /= 10;
		}
		bool isFound = true;
		rep(j,a.size()) if (a[j] != a[a.size()-1-j]) isFound = false;
		if (isFound) ans.push_back(i*i*i);
	}
	cout << ans.back() << endl;

	return 0;
}