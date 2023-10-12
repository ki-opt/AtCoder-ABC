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
	string s;
	cin >> s;

	vector<char> ans;
	rep(i,s.size()) {
		if (s[i] == '0' || s[i] == '1') ans.push_back(s[i]);
		else if (ans.size() != 0) ans.pop_back();
	}

	rep(i,ans.size()) cout << ans[i];

	return 0;
}