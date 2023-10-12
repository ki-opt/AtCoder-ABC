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
	string S;
	cin >> N >> S;

	int cnt = 0;
	repp(i,1,N) {
		if (S[i] == 'E') cnt++;
	}
	
	vector<int> right(N,0), left(N,0);
	right[0] = cnt;
	left[0] = 0;
	int ans = right[0] + left[0];
	repp(i,1,N) {
		if (S[i-1] == 'W') left[i] = left[i-1] + 1;
		else left[i] = left[i-1];
		if (S[i] == 'E') right[i] = right[i-1] - 1;
		else right[i] = right[i-1];
		ans = min(ans,right[i]+left[i]);
	}

	cout << ans << endl;
	

	return 0;
}