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
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	rep(i,H) cin >> S[i];

	//
	rep(i,S.size()) {
		rep(j,W) {
			if (S[i][j] == 's') {
				if (j + 4 < W) {
					if (S[i][j+1] == 'n' && S[i][j+2] == 'u' && 
							S[i][j+3] == 'k' && S[i][j+4] == 'e') {
						rep(k,5) {
							cout << i+1 << " " << j+1+k << endl;
						}
						return 0;
					}
				}
				if (j - 4 >= 0) {
					if (S[i][j-1] == 'n' && S[i][j-2] == 'u' && 
							S[i][j-3] == 'k' && S[i][j-4] == 'e') {
						rep(k,5) {
							cout << i+1 << " " << j+1-k << endl;
						}
						return 0;
					}
				}
				if (i - 4 >= 0) {
					if (S[i-1][j] == 'n' && S[i-2][j] == 'u' && 
							S[i-3][j] == 'k' && S[i-4][j] == 'e') {
						rep(k,5) {
							cout << i+1-k << " " << j+1 << endl;
						}
						return 0;
					}
				}
				if (i + 4 < H) {
					if (S[i+1][j] == 'n' && S[i+2][j] == 'u' && 
							S[i+3][j] == 'k' && S[i+4][j] == 'e') {
						rep(k,5) {
							cout << i+1+k << " " << j+1 << endl;
						}
						return 0;
					}
				}


				if (i - 4 >= 0 && j + 4 < W) {
					if (S[i-1][j+1] == 'n' && S[i-2][j+2] == 'u' && 
							S[i-3][j+3] == 'k' && S[i-4][j+4] == 'e') {
						rep(k,5) {
							cout << i+1-k << " " << j+1+k << endl;
						}
						return 0;
					}
				}
				if (i + 4 < H && j + 4 < W) {
					if (S[i+1][j+1] == 'n' && S[i+2][j+2] == 'u' && 
							S[i+3][j+3] == 'k' && S[i+4][j+4] == 'e') {
						rep(k,5) {
							cout << i+1+k << " " << j+1+k << endl;
						}
						return 0;
					}
				}


				if (i - 4 >= 0 && j - 4 >= 0) {
					if (S[i-1][j-1] == 'n' && S[i-2][j-2] == 'u' && 
							S[i-3][j-3] == 'k' && S[i-4][j-4] == 'e') {
						rep(k,5) {
							cout << i+1-k << " " << j+1-k << endl;
						}
						return 0;
					}
				}
				if (i + 4 < H && j - 4 >= 0) {
					if (S[i+1][j-1] == 'n' && S[i+2][j-2] == 'u' && 
							S[i+3][j-3] == 'k' && S[i+4][j-4] == 'e') {
						rep(k,5) {
							cout << i+1+k << " " << j+1-k << endl;
						}
						return 0;
					}
				}

			}
		}
	}



	return 0;
}