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
	int N, K, Q;
	cin >> N >> K >> Q;
	vector<ll> ans;

	ll total = 0;
	vector<ll> A(N,-1);
	map<ll,ll> mp;
	priority_queue<ll> next_pque;
	rep(q,Q) {
		int X, Y;
		cin >> X >> Y;
		X--;


		A[X] = Y;
		ans.push_back(total);
		/*
		if (A[X] == -1) {
			if (mp.size() < K) {
				total += Y;
				mp[Y]++;		
			} else if (mp.size() >= K) {
				if (Y > mp.begin()->first) {
					total += Y - mp.begin()->first;
					next_pque.push(mp)
					if (mp[mp.begin()->first] == 1) mp.erase(mp.begin()->first);
					else mp[mp.begin()->first]--;
					mp[Y]++;
				} else if (Y == mp.begin()) {

				}
				/*
				if (next_pque.empty()) {
					if (Y > mp.begin()->first) {
						total += Y - mp.begin()->first;
						if (mp[mp.begin()->first] == 1) mp.erase(mp.begin()->first);
						else mp[mp.begin()->first]--;
						mp[Y]++;
					} else {
						next_pque.push(Y);
					}
				} else if (!next_pque.empty()) {
					if (Y > next_pque.top() && ) {
						total += Y;
						mp[Y]++;
					} else {
						total
					}
				}
			}
		} else {

		}*/

		/*
		// 存在する場合
		if (mp.count(A[X]) > 0 && mp[A[X]] > 0) {
			if (mp.count(A[X]) <= 1) mp.erase(A[X]);
			else mp[A[X]]--;
			if (next_pque.empty() || Y > A[X]) {
				total += Y - A[X];	
				mp[Y]++;
			} else if (Y <= next_pque.top()) {
				total += next_pque.top() - A[X];
				mp[next_pque.top()]++;
				next_pque.pop();
				next_pque.push(Y);
			}
		// 存在しない場合
		} else {
			if (mp.size() >= K) {
				if (Y > mp.begin()->first) {
					total += Y - mp.begin()->first;
					if (mp.count(A[X]) == 1) mp.erase(mp.begin()->first);
					else mp[mp.begin()->first]--;
					mp[Y]++;
				} else {
					next_pque.push(Y);
				}
			} else {
				mp[Y]++;
				total += Y;
			}
		}
		*/
	}

	rep(i,ans.size()) {
		cout << ans[i] << endl;
	}


	return 0;
}