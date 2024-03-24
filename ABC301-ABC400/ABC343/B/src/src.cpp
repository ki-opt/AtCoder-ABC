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
	vector<vector<int>> A(N,vector<int>(N));
	rep(i,N) rep(j,N) cin >> A[i][j];

	rep(i,N) {
		rep(j,N) {
			if (A[i][j] == 1) cout << j+1 << " ";
		}
		cout << endl;
	}

	return 0;
}