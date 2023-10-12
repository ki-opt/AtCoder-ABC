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
	int N;
	cin >> N;
	vector<int> T(N);
	rep(i,N) cin >> T[i];
	int M;
	cin >> M;
	vector<int> P(M), X(M), ans(M,0);
	rep(i,M) cin >> P[i] >> X[i];

	rep(i,M) {
		rep(j,N) {
			if (j + 1 == P[i]) {
				ans[i] += X[i];
			} else {
				ans[i] += T[j];
			}
		}
	}
	rep(i,M) {
		cout << ans[i] << endl;
	}

	return 0;
}