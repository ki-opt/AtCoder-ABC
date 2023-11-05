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
	int X, Y;
	cin >> X >> Y;
	if (Y - X <= 2 && Y - X >= 0) cout << "Yes" << endl;
	else if (Y - X >= -3 && Y - X <= 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}