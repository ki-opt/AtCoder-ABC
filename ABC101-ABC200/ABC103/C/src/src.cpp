#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i,N) cin >> a[i];

	int ans = 0;
	rep(i,N) {
		ans += a[i] - 1;
	}
	/*
	int max_val = *max_element(a.begin(),a.end());
	for (int i = max_val; i > 0; i--) {
		int tmp = 0;
		rep(j,N) {
			tmp += i % a[j];
		}
		if (tmp > ans) ans = tmp;
	}*/
	cout << ans << endl;

	return 0;
}