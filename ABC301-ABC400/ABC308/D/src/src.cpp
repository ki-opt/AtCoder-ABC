#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

struct node {
	char c;
	int i, j;
};

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	rep(i,H) cin >> S[i];
	vector<vector<int>> check(H,vector<int>(W,0));

	queue<node> que;
	if (S[0][0] == 's') {
		if (S[0][1] == 'n') {
			que.push({'n',0,1});
			check[0][1] = 1;
		}
		if (S[1][0] == 'n') {
			que.push({'n',1,0});
			check[1][0] = 1;
		}
	} else { cout << "No" << endl; return 0;}

	while (!que.empty()) {
		node tmp = que.front(); que.pop();
		char next_c;
		if (tmp.c == 's') next_c = 'n';
		else if (tmp.c == 'n') next_c = 'u';
		else if (tmp.c == 'u') next_c = 'k';
		else if (tmp.c == 'k') next_c = 'e';
		else next_c = 's';

		int i = tmp.i, j = tmp.j;
		if (i - 1 >= 0) {
			if (S[i-1][j] == next_c && check[i-1][j] == 0) { 
				que.push({next_c,i-1,j});
				check[i-1][j] = 1;
			}
		}
		if (i + 1 < H) {
			if (S[i+1][j] == next_c && check[i+1][j] == 0) { 
				que.push({next_c,i+1,j});
				check[i+1][j] = 1;
				if (i + 1 == H - 1 && j == W - 1) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
		if (j - 1 >= 0) {
			if (S[i][j-1] == next_c && check[i][j-1] == 0) { 
				que.push({next_c,i,j-1}); 
				check[i][j-1] = 1;
			}
		}
		if (j + 1 < W) { 
			if (S[i][j+1] == next_c && check[i][j+1] == 0) { 
				que.push({next_c,i,j+1}); 
				check[i][j+1] = 1;
				if (i == H - 1 && j + 1 == W - 1) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}

	}
	cout << "No" << endl;

	return 0;
}