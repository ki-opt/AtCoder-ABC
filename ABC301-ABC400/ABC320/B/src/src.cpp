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
	string S;
	cin >> S;

	int ans = 1;
	for(int i = 0; i < S.size(); i++) {
		string tmp;
		for (int j = i; j < S.size(); j++) {
			tmp += S[j];
			bool flag = true;
			for (int k = 0; k < tmp.size() / 2; k++) {
				if (tmp[k] == tmp[tmp.size()-(k+1)]) continue;
				else { flag = false; break; }
				//if (k + 1 == tmp.size() / 2) break;
			}
			if (flag) ans = max(ans,(int)tmp.size());
		}
	}
	cout << ans << endl;

	return 0;
}