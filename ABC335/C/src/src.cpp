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
	ll N, Q; cin >> N >> Q;
	deque<pair<int,int>> deq;
	rep(i,N) deq.push_back({i+1,0});
	vector<pair<ll,ll>> ans;
	rep(q,Q) {
		int query, p; char C;
		cin >> query;
		if (query == 1) {
			cin >> C;
			if (C == 'U') deq.push_front({deq[0].first,deq[0].second+1});
			else if (C == 'D') deq.push_front({deq[0].first,deq[0].second-1});
			else if (C == 'L') deq.push_front({deq[0].first-1,deq[0].second});
			else if (C == 'R') deq.push_front({deq[0].first+1,deq[0].second});
		} else if (query == 2) {
			cin >> p;
			p--;
			ans.push_back(deq[p]);
		}
	}

	for (auto a : ans) {
		cout << a.first << " " << a.second << endl;
	}

	return 0;
}