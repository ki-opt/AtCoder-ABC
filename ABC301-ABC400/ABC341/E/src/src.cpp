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
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, Q;
	string S;
	cin >> N >> Q >> S;
	vector<int> v(N-1);
	rep(i,N-1) {
		if (S[i] != S[i+1]) v[i] = 1;
		else v[i] = 0;
	}
	rep(i,Q) {
		int q, l, r; cin >> q >> l >> r;
		l--; r--;
		if (q == 1) {

		} else if (q == 2) {
			cout << 
		}
	}

	return 0;
}