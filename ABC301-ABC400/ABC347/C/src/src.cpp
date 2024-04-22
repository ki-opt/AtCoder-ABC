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
	ll N, A, B; cin >> N >> A >> B;
	vector<ll> D(N), d(N);
	rep(i,N) {
		cin >> D[i];
		d[i] = D[i] % (A+B);
	}

	sort(d.begin(),d.end());
	d.erase(unique(d.begin(),d.end()),d.end());
	bool isFound = false;
	if (d.size() == 1) isFound = true;
	rep(i,d.size()) {
		if (i+1==d.size()) {
			if ((d[0] + A + B - d[i]) % (A+B) > B) isFound = true;
		} else {
			if ((d[i+1] - d[i]) % (A+B) > B) isFound = true;
		}
	}
	if (isFound) cout << "Yes" << endl;
	else cout << "No" << endl;
	/*
	d.push_back(d[0]+A+B);
	bool isFound = false;
	rep(i,d.size()-1) {
		if ((d[i+1] - d[i]) > B) {
			//cout << "Yes" << endl;
			// return 0;
			isFound = true;
		}
	}
	if (isFound) cout << "Yes" << endl;
	else cout << "No" << endl;
	*/
	return 0;
}