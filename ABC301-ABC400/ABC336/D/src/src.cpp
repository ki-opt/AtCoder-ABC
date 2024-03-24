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
	ll N; cin >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	vector<int> left(N+2,0), right(N+2,0);
	for (int i = 1; i < N+1; i++) left[i] = min(A[i-1],left[i-1]+1);
	for (int i = N; i > 0; i--) right[i] = min(A[i-1],right[i+1]+1);
	/*
	rep(i,N) {
		int cnt = 2;
		repp(j,i+1,N) {
			if (A[j] < cnt) { 
				if (cnt != 2) i = j - 2;
				else i = j - 1;
				break;
			}
			left[j] = cnt;
			cnt++;
			if (j + 1 == N) i = N;
		}
	}
	reverse(A.begin(),A.end());
	rep(i,N) {
		int cnt = 2;
		repp(j,i+1,N) {
			if (A[j] < cnt) { 
				if (cnt != 2) i = j - 2;
				else i = j - 1;
				break;
			}
			right[j] = cnt;
			cnt++;
			if (j + 1 == N) i = N;
		}
	}
	reverse(right.begin(),right.end());
	*/
	int ans = 0;
	rep(i,N) {
		int tmp = min(left[i],right[i]);
		ans = max(ans,tmp);
	}
	if (ans == 0) cout << 1 << endl;
	else cout << ans << endl;

	return 0;
}