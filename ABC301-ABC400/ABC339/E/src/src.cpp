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
	int N, D; cin >> N >> D;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	

	/*
	vector<int> v(N,0);
	rep(i,N-1) {
		if (abs(A[i] - A[i+1]) <= D) {
			int cnt = 1;
			int j = i;
			while (j+1 < N && abs(A[j]-A[j+1]) <= D) cnt++, j++;
			v[i] += cnt;
			repp(k,i+1,j+1) v[k] += (v[k-1] - 1);
			i = j - 1;
		}
	}
	int ans = 0, tmp = 0;
	rep(i,N) {
		tmp += v[i];
		ans = max(ans,tmp);
	}
	cout << ans << endl;
	return 0;
	*/
}