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
	int N;
	cin >> N;
	vector<int> A(7*N);
	rep(i,7*N) cin >> A[i];

	for (int i = 0; i < 7*N; i+=7) {
		int ans = 0;
		repp(j,i+7,i) ans += A[j];
		cout << ans << " " ;
	}

	return 0;
}