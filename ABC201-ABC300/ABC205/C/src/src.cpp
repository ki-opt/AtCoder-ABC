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
	ll A, B, C; cin >> A >> B >> C;
	if (A == B) {
		cout << "=" << endl;
		return 0;
	}
	if (A == 0 && B == 0) {
		cout << "=" << endl;
		return 0;
	} else if (A == 0) {
		if (B < 0) {
			if (C % 2 == 1) cout << ">" << endl;
			else cout << "<" << endl;
			return 0;
		}
	} else if (B == 0) {
		if (A < 0) {
			if (C % 2 == 1) cout << "<" << endl;
			else cout << ">" << endl;
			return 0;
		} 
	}
	if (A < 0 && B < 0) { 
		if (C % 2 == 1) {
			if (A < B) cout << "<" << endl;
			else if (A > B) cout << ">" << endl;
			return 0;
		}
		A = -A, B = -B;
	} else if (A < 0) {
		if (C % 2 == 1) {
			cout << "<" << endl;
			return 0;
		}
		A = -A;
	} else if (B < 0) {
		if (C % 2 == 1) {
			cout << ">" << endl;
			return 0;
		}
		B = -B;
	}

	double a = (double)C * log10((double)A);
	double b = (double)C * log10((double)B);
	if (fabs(a-b) < DBL_EPSILON) cout << "=" << endl;
	else if (a < b) cout << "<" << endl;
	else cout << ">" << endl;
	return 0;
}