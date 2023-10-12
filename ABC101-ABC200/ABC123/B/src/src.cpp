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
	vector<int> order(5);
	rep(i,order.size()) cin >> order[i];

	int min_val = INT_MAX;
	do {
		int ans = 0;
		for (int i = 0; i < order.size(); i++) {
			if(i == 0) ans += order[0];
			else {
				if (ans % 10 == 0) ans += order[i];
				else {
					ans += order[i] + (10 - (ans % 10));
				}
			}
		}
		if (ans < min_val) min_val = ans;
	} while(next_permutation(order.begin(),order.end()));
	cout << min_val << endl;

	return 0;
}