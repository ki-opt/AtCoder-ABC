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
	int N, M, Q; cin >> N >> M >> Q;
	vector<int> a(Q), b(Q), c(Q), d(Q);
	rep(i,Q) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--; b[i]--;
	}
	ll ans = 0;
	vector<int> A(N,1);
	while(1) {
		ll tmp = 0;
		rep(i,Q) if (A[b[i]] - A[a[i]] == c[i]) tmp += (ll)d[i];
		ans = max(ans,tmp);

		A[N-1]++;
		int index = N-1;
		while (index > 0 && A[index] > M) A[index-1]++, index--;
		if (A[0] > M) break;
		repp(i,index+1,N) A[i] = A[i-1];
	}
	cout << ans << endl;

	return 0;
}