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

bool next_combination(vector<int>& combination, int n, int k) {
	for (int i = k - 1; i >= 0; --i) {
		if (combination[i] < n - k + i) {
			++combination[i];
			for (int j = i + 1; j < k; ++j) {
					combination[j] = combination[j - 1] + 1;
			}
			return true;
		}
	}
	return false;
}

int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	vector<vector<int>> row(N),col(N);
	rep(i,N) {
		cin >> S[i];
	}
	rep(i,N) rep(j,N) {
		if (S[i][j] == 'o') row[i].push_back(j);
		if (S[j][i] == 'o') col[i].push_back(j);
	}

	ll ans = 0;
	rep(i,N) {
		if (row[i].size() <= 1) continue;
		ll total = 0;
		rep(j,row[i].size()) {
			total += (row[i].size()-1) * (col[row[i][j]].size() > 1 ? col[row[i][j]].size()-1 : 0);
		}
		ans += total;

		/*
		ans += total;
		repp(j,1,row[i].size()) {
			if (col[row[i][j]].size() > 1) ans += total - col[row[i][j]].size();
		}
		*/
	}

	/*
	rep(i,N) {
		repp(j,i+1,col[i].size()) {
			ans += (row[i].size() > 1 ? row[i].size()-1 : 0) +
						(row[j].size() > 1 ? row[j].size()-1 : 0);
		}
	}
	*/
	cout << ans << endl;

	return 0;
}