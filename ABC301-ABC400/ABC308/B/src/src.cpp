#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> C(N), D(M);
	vector<int> P(M+1);
	rep(i,N) cin >> C[i];
	rep(i,M) cin >> D[i];
	rep(i,M+1) cin >> P[i];

	int ans = 0;
	rep(i,N) {
		int flag = 0;
		rep(j,M) {
			if (C[i] == D[j]) {
				ans += P[j+1];
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			ans += P[0];
		}
	}
	cout << ans << endl;


	return 0;
}