#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

void check(int &H, int &W, vector<vector<int>> &A, vector<vector<int>> &B) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (A[i][j] != B[i][j]) goto done;
		}
	}
	cout << "Yes" << endl;
	exit;
done:
}

void rotation(int &H, int &W, vector<vector<int>> &A, vector<vector<int>> &B) {

}

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>> A, B;
	
	for (int i = 0; i < H; i++) {
		string wrk;
		cin >> wrk;
		for (int j = 0; j < W; j++) {
			if (wrk[j] == '#') A[i][j] = 0;
			else A[i][j] = 1;
		}
	}
	for (int i = 0; i < H; i++) {
		string wrk;
		cin >> wrk;
		for (int j = 0; j < W; j++) {
			if (wrk[j] == '#') B[i][j] = 0;
			else B[i][j] = 1;			
		}
	}

	//check(H, W, A, B);

	for (int j = 0; j < W; j++) {
		
		for (int i = 0; i < H; i++) {

		}
	}

	return 0;
}