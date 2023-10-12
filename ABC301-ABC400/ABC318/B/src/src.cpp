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
	int N;
	cin >> N;
	vector<int> A(N), B(N), C(N), D(N);
	rep(i,N) cin >> A[i] >> B[i] >> C[i] >> D[i];

	vector<vector<bool>> flag(101,vector<bool>(101,false));
	rep(i,N) {
		for(int j = A[i]; j < B[i]; j++) {
			for (int k = C[i]; k < D[i]; k++) {
				flag[j][k] = true;
			}
		}
	}

	int ans = 0;
	rep(i,101) {
		rep(j,101) {
			if (flag[i][j]) ans++;
		}
	}
	cout << ans << endl;

	return 0;
}