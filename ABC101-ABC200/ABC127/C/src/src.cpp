#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> L(M), R(M);
	rep(i,M) cin >> L[i] >> R[i];

	int l = 0, r = INT_MAX;
	rep(i,M) {
		if (L[i] > l) l = L[i];
		if (R[i] < r) r = R[i];
	}

	int ans = 0;
	rep(i,N) {
		if (i + 1 >= l && i + 1 <= r) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}