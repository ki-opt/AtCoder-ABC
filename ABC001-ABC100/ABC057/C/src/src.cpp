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
	ll N;
	cin >> N;

	int ans = INT_MAX;
	repp(i,1,(int)pow(N,0.5)+1) {
		if (N % i == 0) {
			int A = i, B = N / i;
			int tmp_A = 0, tmp_B = 0;
			while(A != 0) { A /= 10; tmp_A++; }
			while(B != 0) { B /= 10; tmp_B++; }
			int tmp = max({tmp_A, tmp_B});
			ans = min(tmp,ans);
		}
	}
	cout << ans << endl;
	return 0;
}