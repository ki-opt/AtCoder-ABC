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
using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)


int main() {
	ll N; cin >> N;
	vector<ll> x(N), y(N);
	vector<ll> z(N), w(N);
	rep(i,N) {
		cin >> x[i] >> y[i];
		z[i] = x[i] + y[i];
		w[i] = x[i] - y[i];
	}

	ll max_z = *max_element(z.begin(),z.end());
	ll min_z = *min_element(z.begin(),z.end());
	ll max_w = *max_element(w.begin(),w.end());
	ll min_w = *min_element(w.begin(),w.end());
	
	cout << max({max_z - min_z, min_z - max_z, max_w - min_w, min_w - max_w}) << endl;
	

	return 0;
}