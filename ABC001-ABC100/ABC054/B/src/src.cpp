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
	int N, M;
	cin >> N >> M;
	vector<string> A(N), B(M);
	rep(i,N) cin >> A[i];
	rep(i,M) cin >> B[i];

	int i = 0, j = 0;
	while (i + M <= N) {
		bool flag = true;
		repp(y,i,i+M) {
			repp(x,j,j+M) {
				if (B[y-i][x-j] != A[y][x]) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) {
			cout << "Yes" << endl;
			return 0;
		}

		j++;
		if (j + M > N) { i++; j = 0; }
	}
	cout << "No" << endl;
	return 0;
}