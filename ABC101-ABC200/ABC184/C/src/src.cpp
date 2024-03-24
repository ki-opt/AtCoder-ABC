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

ll r2, c2;

bool check(ll r1, ll c1) {
	if (abs(r1-r2)+abs(c1-c2)<=3 || r1-c1==r2-c2 || r1+c1 == r2+c2) return true;
	return false;
}

int main() {
	ll r1, c1;
	cin >> r1 >> c1 >> r2 >> c2;
	
	if (r1 == r2 && c1 == c2) cout << 0 << endl;
	else if (check(r1,c1)) cout << 1 << endl;
	else {
		bool isFound = false;
		repp(c,-3,4) repp(d,-3,4) if (abs(c)+abs(d) <= 3) {
			if (check(r1+c,c1+d)) isFound = true;
		}
		if ((r1+c1+r2+c2) % 2 == 0) isFound = true;
		if (isFound) {
			cout << 2 << endl;
		} else {
			cout << 3 << endl;
		}
	}
	return 0;
}