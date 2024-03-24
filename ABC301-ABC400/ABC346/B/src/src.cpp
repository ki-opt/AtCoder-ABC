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
#include <set>
#include <math.h>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int W, B; cin >> W >> B;
	string tmp = "wbwbwwbwbwbw";
	string S;
	rep(i,30) S += tmp;
	rep(i,S.size()) {
		int w = 0, b = 0;
		int j = i;
		while (j < S.size() && w <= W && b <= B) {
			if (S[j] == 'w') w++;
			else if (S[j] == 'b') b++;
			j++;
			if (w == W && b == B) {
				cout << "Yes" << endl;
				return 0;
			}
 		}
	} 
	cout << "No" << endl;

	return 0;
}