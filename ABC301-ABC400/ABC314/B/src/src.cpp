#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int> C(N);
	vector<vector<int>> A(N,vector<int>());
	rep(i,N) {
		cin >> C[i];
		rep(j,C[i]) {
			int tmp;
			cin >> tmp;
			A[i].push_back(tmp);
		}
	}
	int X;
	cin >> X;

	vector<int> check(N,-1);
	int min_val = INT_MAX;
	rep(i,N) {
		rep(j,C[i]) {
			if (A[i][j] == X) {
				min_val = min(min_val,C[i]);
				check[i] = 1;
				break;
			}
		}
	}

	int sum = 0;
	int flag = 0;
	rep(i,N) {
		if (C[i] == min_val && check[i] == 1) {
			sum++;
		}
	}
	if (sum == 0) {
		cout << 0 << endl;
		return 0;
	} else {
		cout << sum << endl;
	}
	rep(i,N) {
		if (C[i] == min_val && check[i] == 1) {
			cout << i + 1 << " ";
		}
	}
	return 0;
}