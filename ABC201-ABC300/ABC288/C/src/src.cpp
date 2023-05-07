#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector; using std::cout; using std::cin;
using std::string; using std::endl; using std::sort;



void func(vector<vector<int>>& node, int& count, int& node_number, vector<int>& check) {
   for (int i = 0; i < node[node_number].size(); i++) {
      
   }
}

int main() {
   int N, M;
   cin >> N; cin >> M;
   vector<vector<int>> node(N);

   for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a; cin >> b;
      node[a].push_back(b);
   }

   int count = 0;
   for (int i = 0; i < N; i++) {
      if (node[i].empty()) continue;
      vector<int> check(N,0);
      func(node,count,i,check);
   }

   return 0;
}