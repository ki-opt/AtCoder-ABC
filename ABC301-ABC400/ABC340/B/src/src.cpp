#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int Q; cin >> Q;
	vector<int> ans;
	rep(i,Q) {
		int query; cin >> query;
		if (query == 1) {
			int v;
			cin >> v;
			ans.push_back(v);
		} else {
			int k; cin >> k;
			cout << ans[ans.size() - k] << endl;
		}
	}

	return 0;
}