#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	vector<int> T(N);

	int gokaku_flag = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'o') gokaku_flag = 1;
		if (S[i] == 'x') {
			gokaku_flag = 0;
			break;
		}
	}

	if (gokaku_flag == 1) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}