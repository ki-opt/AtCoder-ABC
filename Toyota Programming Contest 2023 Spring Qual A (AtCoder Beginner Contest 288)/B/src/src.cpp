#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector; using std::cout; using std::cin;
using std::string; using std::endl; using std::sort;

int main() {
   int N, K;
   cin >> N; cin >> K;
   vector<string> S(K);

   for (int i = 0; i < K; i++) {
      cin >> S[i];
   }

   sort(begin(S),end(S),[](string c1, string c2) {
      return c1 < c2;
   });

   for (int i = 0; i < K; i++) cout << S[i] << endl;

   return 0;
}