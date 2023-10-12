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
	long int X;
	cin >> X;

	/*vector<int> dp(100000,0);
	rep(i,100000) {
		dp
	}*/

	long int i = 1;
	long int ans = 0;
	while(ans < X) {
		ans = 0.5 * i * (i + 1);
		i++;
	}
	if (ans == X) {
		cout << i - 1 << endl;
	} else {
		cout << i - 1 << endl;
	}

	return 0;
}