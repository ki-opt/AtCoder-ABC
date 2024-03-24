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
	int N; cin >> N;
	vector<int> P(N);
	rep(i,N) cin >> P[i];
	
	int Q; cin >> Q;
	rep(i,Q) {
		int A, B, a, b; cin >> A >> B;
		rep(j,N) {
			if (P[j] == A) a = j;
			else if (P[j] == B) b = j;
		}
		if (a < b) cout << A << endl;
		else cout << B << endl;
	}

	return 0;
}