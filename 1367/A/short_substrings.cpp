// Problem: https://codeforces.com/contest/1367/problem/A
#include <iostream>

using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);

int main() {
  fio
  int epochs;
  int j;
  string s;

  cin >> epochs;

  for (int i = 0; i < epochs; i++) {
    cin >> s;
    for (j = 0; j < s.length(); j++) {
      if(j % 2 == 0) {
        cout << s[j];
      }  
    }
    cout << s[j-1] << endl;
  }
  
  
  return 0;
}