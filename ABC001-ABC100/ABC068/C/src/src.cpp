#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, M;
	cin >> N >> M;
	vector<ll> a(M), b(M);
	vector<pair<ll,ll>> pairs(M);
	rep(i,M) {
		cin >> a[i] >> b[i];
		pairs[i] = {a[i],b[i]};
	}

	//vector<pair<int,int>> check_start, check_goal;
	vector<int> check_start(N+1,0), check_goal(N+1,0);
	rep(i,M) {
		if (a[i] == 1) check_start[b[i]] = 1;
		if (b[i] == N) check_goal[a[i]] = 1;
	}

	rep(i,N+1) {
		if (check_start[i] == 1 && check_goal[i] == 1) {
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}

	/*
	sort(check.begin(),check.end(),greater<pair<int,int>>());
	sort(pairs.begin(),pairs.end());
	rep(i,M) {
		if (pairs[i].first > 1) break;
		if (check[i].first == 1) {
			rep(j,M) {
				
				if (a[j] == 1 && b[j] == check[i].second) {
					cout << "POSSIBLE" << endl;
					return 0;
				}
			}
		} else break;
	}
	*/
	cout << "IMPOSSIBLE" << endl;
	return 0;
}