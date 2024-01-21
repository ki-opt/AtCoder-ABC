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
	vector<int> t(N), x(N);
	rep(i,N) cin >> t[i] >> x[i];

	vector<vector<int>> potion(N+1);
	vector<int> kodo(N,-1);
	rep(i,N) {
		if (t[i] == 1) {
			kodo[i] = 1;
			potion[x[i]].push_back(i);
		} else if (t[i] == 2) {
			if (potion[x[i]].empty()) {
				cout << -1 << endl;
				return 0;
			}
			potion[x[i]].pop_back();
		}
	}

	repp(i,1,N+1) {
		for (auto p : potion[i]) {
			kodo[p] = 0;
		}
	}

	int ans = 0;
	int max_val = 0;
	rep(i,N) {
		if (kodo[i] == 1) {
			ans++;
			max_val = max(ans,max_val);
		} else if (t[i] == 2) {
			ans--;
		}
	}

	cout << max_val << endl;
	rep(i,N) if (t[i] == 1) cout << kodo[i] << " ";
	return 0;
}