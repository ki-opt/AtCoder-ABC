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
#include <bitset>
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
	ll N, Q; cin >> N >> Q;	
	set<ll> S;
	vector<ll> A(N+1,0), ruiseki;
	vector<vector<ll>> hist(N+1);
	ruiseki.push_back(0);
	repp(q,0,Q) {
		ll x; cin >> x;
		if (S.find(x) != S.end()) S.erase(x);
		else S.insert(x);

		if (q == 0) ruiseki.push_back(1);
		else ruiseki.push_back(ruiseki[q] + S.size());
		hist[x].push_back(q+1);
	}

	repp(i,1,N+1) {
		if (hist[i].size() == 0) continue;
		if (hist[i].size() % 2 == 0) {
			for (int j=0; j < hist[i].size(); j+=2) {
				A[i] += ruiseki[hist[i][j+1]-1] - ruiseki[hist[i][j]-1];
			}
		} else {
			for (int j=0; j < hist[i].size()/2; j++) {
				A[i] += ruiseki[hist[i][j*2+1]-1] - ruiseki[hist[i][j*2]-1];
			}
			A[i] += ruiseki.back() - ruiseki[hist[i].back()-1];
		}
	}

	repp(i,1,N+1) cout << A[i] << " ";
	cout << endl;
	return 0;
}