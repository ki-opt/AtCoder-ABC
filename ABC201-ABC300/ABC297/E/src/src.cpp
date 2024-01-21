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
	int N, K;
	cin >> N >> K;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];

	sort(A.begin(),A.end());
	vector<ll> ans = {0};
	//priority_queue<ll,vector<ll>,greater<ll>> pque;
	//repp(i,0,N) pque.push(A[i]);

	repp(i,1,K+1) {
		ll min_val = LLONG_MAX;
		rep(j,N) {
			auto itr = upper_bound(ans.begin(),ans.end(),ans[i-1]-A[j]);
			ll tmp;
			if (itr == ans.end()) tmp = A[j];
			else tmp = *itr + A[j];
			min_val = min(min_val,tmp);
		}
		ans.push_back(min_val);
		/*
		ll tmp = pque.top(); pque.pop();
		if (tmp <= ans[ans.size()-1]) {
			queue<ll> wrk;
			while (pque.top() <= ans[ans.size()-1]) { wrk.push(pque.top()); pque.pop(); }
			ans.push_back(pque.top()); pque.pop();
			while(!wrk.empty()) { 
				pque.push(wrk.front());
				rep(j,N) pque.push(wrk.front() + A[j]);
				wrk.pop();
			}
		} else {
			ans.push_back(tmp);
			rep(j,N) pque.push(tmp + A[j]);
		}
		*/
	}
	cout << ans[ans.size()-1] << endl;

	return 0;
}