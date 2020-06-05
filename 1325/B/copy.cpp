// Problem: https://codeforces.com/contest/1325/problem/A
#include <iostream>
#include <unordered_set>

using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);

int main() {
  fio
  int epochs, n, val;

  cin >> epochs;

  for (int i = 0; i < epochs; i++) {
    cin >> n;
    unordered_set<int> set;
    for (int j = 0; j < n; j++) {
      cin >> val;
      set.insert(val);
    }
    cout << set.size() << endl;
  }
  return 0;
}