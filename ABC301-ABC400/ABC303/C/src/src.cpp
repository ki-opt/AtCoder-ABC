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
	int N, M, H, K;
	cin >> N >> M >> H >> K;
	string S;
	cin >> S;
	unordered_map<string,int> xy;
	rep(i,M) {
		int x, y;
		cin >> x >> y;
		string tmp = to_string(x) + "_" + to_string(y);
		xy[tmp] = 1;
		//cout << tmp << endl;
	}

	int now_x = 0, now_y = 0;
	rep(i,N) {//S.size()
		if (S[i] == 'R') {
			now_x++;
		} else if (S[i] == 'L') {
			now_x--;
		} else if (S[i] == 'U') {
			now_y++;
		} else if (S[i] == 'D') {
			now_y--;
		}
		H--;
		string tmp = to_string(now_x) + "_" + to_string(now_y);
		if (H < 0) {
			cout << "No" << endl; 
			return 0;
		} else {
			if (H < K && xy.count(tmp) > 0) {
				if (xy[tmp] == 1) {
					H = K;
					xy[tmp] = 0;
				}
			}
		}
	}
	cout << "Yes" << endl;

	return 0;
}