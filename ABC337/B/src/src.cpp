#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S; cin >> S;
	vector<int> a, b, c;
	rep(i,S.size()) {
		if (S[i] == 'A') a.push_back(i);
		else if (S[i] == 'B') b.push_back(i);
		else if (S[i] == 'C') c.push_back(i);
	}
	string ans = "Yes";
	rep(i,a.size()-1) if (a[i] + 1 != a[i+1]) ans = "No"; 
	rep(i,b.size()-1) if (b[i] + 1 != b[i+1]) ans = "No";
	rep(i,c.size()-1) if (c[i] + 1 != c[i+1]) ans = "No";
	if (!a.empty() && !b.empty() && !c.empty()) {
		if (a[0] > b[0] || b[0] > c[0]) ans = "No";
	} else if (a.empty() && !b.empty() && !c.empty()) {
		if (b[0] > c[0]) ans = "No";
	} else if (!a.empty() && b.empty() && !c.empty()) {
		if (a[0] > c[0]) ans = "No";
	} else if (!a.empty() && !b.empty() && c.empty()) {
		if (a[0] > b[0]) ans = "No"; 
	}
	cout << ans << endl;

	return 0;
}