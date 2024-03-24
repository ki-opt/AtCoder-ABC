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
	int N; cin >> N;
	vector<int> A(N-1);
	rep(i,N-1) cin >> A[i];

	vector<int> ans(N+1,0);
	rep(i,N-1) ans[A[i]]++;
	repp(i,1,N+1) cout << ans[i] << endl;

	return 0;
}