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
	vector<int> K(N);
	vector<vector<int>> A(N,vector<int>());
	rep(i,N) {
		cin >> K[i];
		rep(j,K[i]) {
			int tmp;
			cin >> tmp;
			A[i].push_back(tmp);
		}
	}

	vector<int> check(M,0);
	rep(i,N) {
		rep(j,K[i]) {
			check[A[i][j]-1]++;
		}
	}

	int ans = 0;
	rep(i,M) {
		if (check[i] == N) ans++;
	}

	cout << ans << endl;

	return 0;
}