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
	int N; string S; int Q; cin >> N >> S >> Q;
	string S1, S2;
	rep(i,N) S1 += S[i];
	repp(i,N,2*N) S2 += S[i];

	rep(i,Q) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) {
			a--; b--;
			if (a < N) {
				if (b < N) swap(S1[a],S1[b]);
				else swap(S1[a],S2[b-N]);
			} else {
				if (b < N) swap(S2[a-N],S1[b]);
				else swap(S2[a-N],S2[b-N]);
			}
		} else if (t == 2) {
			S1.swap(S2);
		}
	}
	cout << S1+S2 << endl;

	return 0;
}