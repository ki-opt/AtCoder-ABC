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
	vector<string> s(N);
	rep(i,N) cin >> s[i];
	int M;
	cin >> M;
	vector<string> t(M);
	rep(i,M) cin >> t[i];

	int ans = 0;
	rep(i,N) {
		int tmp = 0;
		rep(j,N) {
			if (s[i] == s[j]) tmp++;
		}
		//cout << tmp << endl;
		rep(k,M) {
			if (s[i] == t[k]) tmp--;
		}
		if (tmp > ans) ans = tmp;
	}
	cout << ans << endl;

	return 0;
}