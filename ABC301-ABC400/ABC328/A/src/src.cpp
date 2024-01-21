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
	int N, X;
	cin >> N >> X;
	vector<int> S(N);
	rep(i,N) cin >> S[i];

	int ans = 0;
	rep(i,N) {
		if (S[i] <= X) ans += S[i];
	}
	cout << ans << endl;

	return 0;
}