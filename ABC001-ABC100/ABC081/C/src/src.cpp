#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	int sum = 0;
	vector<int> check(N+1,0);
	rep(i,N) {
		check[A[i]] += 1;
		if (check[A[i]] == 1) sum++;
	}
	if (sum <= K) {
		cout << 0 << endl;
		return 0;
	} else {
		int ans = 0;
		sort(check.begin(),check.end());
		rep(i,N) {
			if (check[i] >= 1) {
				ans += check[i];
				sum--;
			}
			if (sum <= K) {
				cout << ans << endl;
				return 0;
			}
		}
	}
	/*
	rep(i,N) {
		if (check[A[i]] > 1)
	}
	if (sum <= K) cout << 0 << endl;
	else {
		int ans = 0;
		rep(i,N) {
			if (check[i] > 1) ans += (check[i] - 1);
		}
		cout << ans << endl;
	}
	/*
	sort(check.begin(),check.end());
	int ans = 0;
	rep(i,N) {
		if (check[i] == 1) ans++;
	}
	*/

	return 0;
}