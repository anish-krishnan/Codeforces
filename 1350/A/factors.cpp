// Problem: https://codeforces.com/contest/1325/problem/A
#include <iostream>
#include <cmath>

using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);

int f(int n) {
  int root = (int) sqrt(n);
  for(int factor=2; factor <= root+1; factor++) {
    if(n % factor == 0)
      return factor;
  }
  return n;
}

int main() {
  fio
  int epochs, n, k;

  cin >> epochs;

  for (int i = 0; i < epochs; i++) {
    cin >> n >> k;

    if(n % 2 == 0){
      n += k * 2;
    } else {
      n += f(n);
      n += (k-1) * 2;
    }
    cout << n << endl;
  }
  return 0;
}