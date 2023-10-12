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
	vector<string> S(N);
	rep(i,N) cin >> S[i];

	sort(S.begin(),S.end());
	do {
		int flag = 0;
		rep(k,N-1) {
			int cnt = 0;
			rep(l,M) {
				if (S[k][l] != S[k+1][l]) {
					cnt++;
				}
			}
			if (cnt > 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "Yes" << endl;
			return 0;
		}
	} while (next_permutation(S.begin(),S.end()));
	cout << "No" << endl;

	return 0;
}