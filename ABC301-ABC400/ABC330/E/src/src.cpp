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
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	map<int,int> mp, mp_mex;
	//priority_queue<int,vector<int>,greater<int>> pque;
	vector<bool> check(N+1,false);
	rep(i,N) {
		cin >> A[i];
		if (A[i] > N) check[N] = true;
		else check[A[i]] = true;
		mp[A[i]]++;
	}

	rep(i,N+1) { 
		if (!check[i]) mp_mex[i]++;
	}
	
	vector<int> ans;
	rep(q,Q) {
		int i, x;
		cin >> i >> x;
		i--;
		// 削除パート
		int tmp;
		if (A[i] > N) tmp = N;
		else tmp = A[i];
		if (mp[tmp] > 1) { 
			mp[tmp]--;
		} else { 
			mp.erase(tmp);
			mp_mex[tmp]++;
		}
		// 追加パート
		if (x > N) {
			if (mp_mex.count(N) > 0) mp_mex.erase(N);
			mp[N]++;
		} else {
			if (mp_mex.count(x) > 0) mp_mex.erase(x);
			mp[x]++;
		}
		A[i] = x;
		ans.push_back(mp_mex.begin()->first);
	}
	
	rep(i,ans.size()) cout << ans[i] << endl;

	//priority_queue<int,vector<int>,greater<int>> pque;
	//rep(i,N) pque.push(A[i]);
	
	return 0;
}