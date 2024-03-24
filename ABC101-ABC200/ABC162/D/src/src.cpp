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

string RGB = "RGB";
int R = 0, G = 1, B = 2;

int main() {
	int N;
	string S;
	cin >> N >> S;

	vector<vector<int>> vec(3,vector<int>());
	int r = 0, g = 0, b = 0;
	rep(i,N) {
		if (S[i] == RGB[R]) r++;
		else if (S[i] == RGB[G]) g++;
		else b++;
	}
	rep(i,N) {
		vec[R].push_back(r), vec[G].push_back(g), vec[B].push_back(b);
		if (S[i] == RGB[R]) r--;
		else if (S[i] == RGB[G]) g--;
		else b--;
	}

	ll ans = 0;
	rep(i,N) {
		repp(j,i+1,N-1) {
			if (S[i] == S[j]) continue;
			int c;
			if ((S[i] == RGB[R] || S[i] == RGB[G]) && (S[j] == RGB[R] || S[j] == RGB[G])) c = B;
			else if ((S[i] == RGB[R] || S[i] == RGB[B]) && (S[j] == RGB[R] || S[j] == RGB[B])) c = G;
			else c = R;
			int k = 2 * j - i;
			if (k < N && S[k] == RGB[c]) ans += vec[c][j+1] - 1;
			else ans += vec[c][j+1];
		}
	}
	cout << ans << endl;

	return 0;
}