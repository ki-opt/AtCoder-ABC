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
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	long int ans = 0;
	rep(r,3001) {
		rep(g,3001) {
			int tmp = r * R;
			tmp += g * G;
			if ((N - tmp) % B == 0 && N - tmp >= 0) {
				cout << r << " " << g << " " << N - tmp << endl;
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}