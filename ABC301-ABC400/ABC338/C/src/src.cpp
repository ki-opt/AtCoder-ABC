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
	int N; cin >> N;
	vector<int> Q(N), A(N), B(N), qa(N);//, qb(N);
	rep(i,N) cin >> Q[i];
	rep(i,N) {
		cin >> A[i];
		if (A[i] == 0) qa[i] = 1e9;
		else qa[i] = Q[i] / A[i];
	}
	rep(i,N) {
		cin >> B[i];
		//if (B[i] == 0) qa[i] = 1e9;
		//else qb[i] = Q[i] / B[i];
	}

	int ans = 0;
	int min_a = *min_element(qa.begin(),qa.end());
	//int min_b = *min_element(qb.begin(),qb.end());
	rep(i,min_a+1) {
		vector<int> q = Q;
		int b_min = INT_MAX;
		rep(j,N) {
			q[j] -= A[j] * i;
			if (B[j] == 0) continue;
			if (q[j] / B[j] < b_min) b_min = q[j] / B[j];
		}
		ans = max(ans,i + b_min);
	}
	cout << ans << endl;
	

	return 0;
}