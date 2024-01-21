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

int N;
string R, C;
int row = 0;

void recursive(vector<vector<int>> &haiti, vector<int> &perm, int col) {
	rep(i,N) {
		perm[col] = i;
		if (col+1 != N) {
			recursive(haiti, perm, col+1);
		} else {
			haiti[row] = perm;
			row++;
		}
	}
}

int main() {
	cin >> N >> R >> C;
	vector<vector<char>> tmp(N,vector<char>(N));
	rep(i,N) rep(j,N) tmp[i][j] = '.';

	vector<int> a(N),b(N),c(N);
	rep(i,N) a[i] = i;
	b = a; c = a;

	do {
		vector<vector<char>> tmp_2 = tmp;
		rep(i,N) tmp_2[i][a[i]] = 'A';
		do {
			vector<vector<char>> tmp_3 = tmp_2;
			bool b_flag = true;
			rep(i,N) {
				if (tmp_3[i][b[i]] != '.') { b_flag = false; break; }
				tmp_3[i][b[i]] = 'B';
			}
			if (!b_flag) continue;
			do {
				vector<vector<char>> tmp_4 = tmp_3;
				bool c_flag = true;
				rep(i,N) {
					if (tmp_4[i][c[i]] != '.') { c_flag = false; break; }
					tmp_4[i][c[i]] = 'C';
				}
				if (!c_flag) continue;

				// check
				bool isTrue = true;
				rep(r,N) {
					rep(c,N) {
						if (tmp_4[r][c] != '.') {
							if (tmp_4[r][c] != R[r]) {
								isTrue = false;
								break;
							} else if (tmp_4[r][c] == R[r]) break;
						}
					}
					if (!isTrue) break;
				}
				if (!isTrue) continue;

				rep(c,N) {
					rep(r,N) {
						if (tmp_4[r][c] != '.') {
							if (tmp_4[r][c] != C[c]) {
								isTrue = false;
								break;
							} else if (tmp_4[r][c] == C[c]) break;
						}
					}
					if (!isTrue) break;
				}
				if (!isTrue) continue;

				// output
				if (isTrue) {
					cout << "Yes" << endl;
					rep(r,N) {
						rep(c,N) {
							cout << tmp_4[r][c];
						}
						cout << endl;
					}
					return 0;
				}
			} while (next_permutation(c.begin(),c.end()));
		} while (next_permutation(b.begin(),b.end()));
	} while (next_permutation(a.begin(),a.end()));

	/*
	vector<int> perm(N);
	vector<vector<int>> haiti((int)pow(N,N),vector<int>(N));
	recursive(haiti,perm,0);

	rep(i,haiti.size()) {
		vector<vector<char>> tmp = ans;
		rep(r,N) {
			tmp[r][haiti[i][r]] = R[r];
		}
		rep(j,haiti.size()) {
			vector<vector<char>> tmp_2 = tmp;
			rep(c,N) {
				tmp_2[haiti[j][c]][c] = C[c];
			}
	*/
	/*		
			// check
			bool isTrue = true;
			rep(r,N) {
				vector<int> check(3,0);
				rep(c,N) {
					if (tmp_2[r][c] != '.') {
						if (tmp_2[r][c] != R[r]) {
							isTrue = false;
							break;
						}
						if (tmp_2[r][c] == 'A') check[0]++;
						else if (tmp_2[r][c] == 'B') check[1]++;
						else if (tmp_2[r][c] == 'C') check[2]++;
					}
				}
				rep(alphabet,3) { if (check[alphabet] != 1) isTrue = false; }
				if (!isTrue) break;
			}
			if (!isTrue) continue;

			rep(c,N) {
				vector<int> check(3,0);
				rep(r,N) {
					if (tmp_2[r][c] != '.') {
						if (tmp_2[r][c] != C[c]) {
							isTrue = false;
							break;
						}
						if (tmp_2[r][c] == 'A') check[0]++;
						else if (tmp_2[r][c] == 'B') check[1]++;
						else if (tmp_2[r][c] == 'C') check[2]++;
					}
				}
				rep(alphabet,3) { if (check[alphabet] != 1) isTrue = false; }
				if (!isTrue) break;
			}
			if (!isTrue) continue;

			if (isTrue) {
				cout << "Yes" << endl;
				rep(r,N) {
					rep(c,N) {
						cout << tmp_2[r][c];
					}
					cout << endl;
				}
				return 0;
			}
		//}
	//}*/
	cout << "No" << endl;
	return 0;
}