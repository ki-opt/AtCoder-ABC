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
	int K, G, M;
	cin >> K >> G >> M;

	int g = 0, m = 0;
	rep(k,K) {
		if (g == G) {
			g = 0;
		} else if (m == 0) {
			m = M;
		} else {
			if (m <= G - g) { 
				g += m;
				m = 0;
			} else {
				m -= (G - g);
				g = G;
			}
		}
	}
	cout << g << " " << m << endl;

	return 0;
}