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
	int N, K;
	cin >> N >> K;
	vector<int> P(N);
	rep(i,N) cin >> P[i];

	priority_queue<int,vector<int>,greater<int>> pque;
	rep(i,K) pque.push(P[i]);
	cout << pque.top() << endl;
	repp(i,K,N) {
		pque.push(P[i]);
		pque.pop();
		cout << pque.top() << endl;
	}

	/*
	vector<int> ans(N);
	vector<int> val;
	rep(i,K) val.push_back(P[i]);
	sort(val.begin(),val.end());
	repp(i,K,N) {}
	*/

	/*
	vector<int> ans(N);
	//vector<int> sorted_arr(N);
	map<int,int> mp;
	ans[0] = P[0]; mp[P[0]]++;
	repp(i,1,N) {
		mp[P[i]]++;
		ans[i] = 
	}*/
	
	/*
	vector<int> ans(N);
	ans[0] = P[0];
	priority_queue<int> pque;
	repp(i,1,N) {
		pque.push(P[i]);
		int tmp = pque.top(); pque.pop();
		ans[i] = pque.top();
	}

	repp(i,K-1,N) {
		cout << ans[i] << endl;
	}
	*/

	return 0;
}