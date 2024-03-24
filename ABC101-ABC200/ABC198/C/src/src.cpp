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
	ll R, X, Y; cin >> R >> X >> Y;
	double length = sqrt(X*X+Y*Y);
	double r = R;
	if (length < r) {
		cout << 2 << endl;
		return 0;
	}
	repp(i,1,1e7) {
		if (fabsl(r * (double)i - length) <= DBL_EPSILON) {
			cout << i << endl;
			return 0;
		} else if (r * (double)i > length) {
			cout << i  << endl;
			return 0;
		}
	}

	
	return 0;
}