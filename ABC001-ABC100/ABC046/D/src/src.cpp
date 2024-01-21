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
	string s;
	cin >> s;
	int ans = 0;
	int g = 1, p = 0;
	if (s[0] == 'p') ans--;
	
	repp(i,1,s.size()) {
		if (s[i] == 'g') {
			if (p + 1 <= g) {
				p++;
				ans++;
			} else {
				g++;
			}
		} else if (s[i] == 'p') {
			if (p + 1 <= g) {
				p++;
			} else {
				ans--;
				g++;
			}
		}
	}
	
	if (p + 1 > g) {
		cout << ans << endl;		
	} else {
		cout << ans + (g - (p + 1)) << endl;
	}
	return 0;
}