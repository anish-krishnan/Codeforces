// Problem: https://codeforces.com/contest/1367/problem/B
#include <iostream>

using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);

int main() {
  fio
  int epochs, n, x;
  int i, j;
  string s;

  int num_odds, num_evens, num_mismatches;
  
  cin >> epochs;

  for (i = 0; i < epochs; i++) {
    cin >> n;
    
    num_odds = 0; num_evens = 0; num_mismatches = 0;
    
    int total_evens = n%2 ? n/2 + 1 : n/2;
    int total_odds = n/2;
    
    for (j = 0; j < n; j++) {
      cin >> x;
      
      if(x % 2 == 0) num_evens ++;
      else num_odds ++;
      
      if(x % 2 != j % 2) num_mismatches ++;
    }

    if (num_evens != total_evens || num_odds != total_odds)
      cout << -1 << endl; 
    else 
      cout << num_mismatches / 2 << endl;      
  }
  
  
  return 0;
}
