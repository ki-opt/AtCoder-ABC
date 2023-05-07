#include <iostream>
#include <vector>

using namespace std;

int main() {
	long int H, W;
	cin >> H >> W;

	if (H == 1 || W == 1) {
		cout << 1 << endl;
		return 0;
	}

	long int reached;

	long int n_col;
	if (W % 2 == 1) n_col = (W / 2 + 1) + W / 2;
	else n_col = (W / 2) * 2; 

	if (H % 2 == 0) {
		cout << n_col * (H / 2) << endl;
	} else {
		long int wrk;
		if (W % 2 == 1) {
			wrk = W / 2 + 1;
		} else {
			wrk = W / 2;
		}
		cout << n_col * (H / 2) + wrk;
	}

	
	return 0;
}