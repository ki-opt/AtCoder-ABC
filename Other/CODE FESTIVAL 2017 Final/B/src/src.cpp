#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S;
	cin >> S;
	ll a = 0, b = 0, c = 0;

	vector<int> check(3,0);
	rep(i,S.size()) {
		if (S[i] == 'a') check[0]++;
		else if (S[i] == 'b') check[1]++;
		else if (S[i] == 'c') check[2]++;
	}

	sort(check.begin(),check.end());
	if (check[1] - check[0] > 1) {
		cout << "NO" << endl;
		return 0;
	} else if (check[1] - check[0] == 1 && check[1] == check[2]) {
		cout << "YES" << endl;
		return 0;
	} else if (check[1] - check[0] == 0 && check[2] - check[1] <= 1) {
		cout << "YES" << endl;
		return 0;
	} else {
		cout << "NO" << endl;
		return 0;
	}

	/*ll min_val = min({a,b,c});
	while(1) {
		a -= min_val;
		b -= min_val;
		c -= min_val;
	}*/

	return 0;
}