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
	string S;
	cin >> S;
	int ans = 0;
	rep(i,S.size()-1) {
		if (S[i] == S[i+1]) {
			if (S[i+1] == '0') S[i+1] = '1';
			else S[i+1] = '0';
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}