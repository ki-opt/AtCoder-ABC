#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, S, K;
	cin >> N >> S >> K;
	vector<int> P(N), Q(N);
	rep(i,N) cin >> P[i] >> Q[i];

	int ans = 0;
	rep(i,N) {
		ans += P[i] * Q[i];
	}
	if (ans >= S) cout << ans << endl;
	else cout << ans + K << endl;

	return 0;
}