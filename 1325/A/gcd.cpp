// Problem: https://codeforces.com/contest/1325/problem/A
#include <iostream>

using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);

int main() {
  fio
  int epochs, x;

  cin >> epochs;

  for (int i = 0; i < epochs; i++) {
    cin >> x;
    cout << 1 << " " << x-1 << endl;
  }
  return 0;
}