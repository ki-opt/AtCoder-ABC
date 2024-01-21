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
	int N, L;
	cin >> N >> L;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	int ans = 0;
	rep(i,N) if (A[i] >= L) ans++;
	cout << ans << endl;

	return 0;
}