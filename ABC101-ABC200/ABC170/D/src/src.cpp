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
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	vector<int> check(1e6+1,0);
	rep(i,N) check[A[i]]++;
	repp(i,1,1e6+1) {
		if (check[i] == 0) continue;
		for (int j = 2; j * i <= 1e6; j++) check[j*i]++;
	}

	ll ans = 0;
	rep(i,N) {
		if (check[A[i]] > 1) continue;
		ans++;
	}
	cout << ans << endl;
	return 0;
}