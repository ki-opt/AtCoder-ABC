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
	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;
	int ans = 0;
	while (1) {
		int muji = M, logo = ans;
		bool isFound = true;
		rep(i,N) {
			if (S[i] == '0') {
				muji = M;
				logo = ans;
			} else if (S[i] == '1') {
				if (muji > 0) muji--;
				else if (logo > 0) logo--;
				else { isFound = false; break; }
			} else {
				if (logo > 0) logo--;
				else { isFound = false; break; }
			}
		}
		if (isFound) break;
		ans++;
	}
	cout << ans << endl;
	return 0;
}