#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
	int N, A, B;
	string S;
	cin >> N >> A >> B >> S;

	int cnt_yes = 0;
	int kaigai_gakusei = 1;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'a') {
			if (cnt_yes < A + B) {
				cout << "Yes" << endl;
				cnt_yes++;
			} else {
				cout << "No" << endl;
			}
		} else if (S[i] == 'b') {
			if (cnt_yes < A + B && kaigai_gakusei <= B) {
				cout << "Yes" << endl;
				cnt_yes++;
				kaigai_gakusei++;
			} else {
				cout << "No" << endl;
			}
		} else {
			cout << "No" << endl;
		}
	}	
	return 0;
}