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
	string S;
	cin >> S;
	
	string ans;
	rep(i,S.size()) {
		ans += S[i];
		if (ans.size() >= 3 && ans.substr(ans.size()-3,3) == "ABC") {
			ans.erase(ans.size()-3);
		}
	}
	cout << ans << endl;

	return 0;
}