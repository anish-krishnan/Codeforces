// Problem: https://codeforces.com/contest/1367/problem/C
#include <iostream>

using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);

int max(int x, int y){
  if(x > y)
    return x;
  return y;
}

int num_tables(int i,int j,int n,int k){

  int len = j-i+1;
  
  // Starting or Ending with 0's
  if((i == 0 && j != n-1) || (i != 0 && j == n-1))
    return (len % 2) ? (len)/(k+1) : (len)/(k+1);
  
  // All 0's
  if(i == 0 && j == n-1)
    return 1 + num_tables(i+1, j, n, k);
  
  if(i != 0 && j != n-1)
    return (len+1)/(k+1) - 1;
  
  return 0;
}


int main() {
  fio
  int epochs, n, k;
  string s;
  int i, j;
  
  cin >> epochs;


  for (i = 0; i < epochs; i++) {
    cin >> n >> k;
    cin >> s;

    int start = 0;
    int end = -1;
    int total_tables = 0;
    
    for (j = 0; j < n; j++) {      
      if (s[j] == '1') { 
        end = j-1;
        
        if (start < end) {
          total_tables += num_tables(start, end, n, k);
        }
        start = j+1;
      }  
    }

    // Ends with 0 case (encompasses all 0s)
    if (end != n-1 && start > end && start <= n-1) {
     total_tables += num_tables(start, n-1, n, k); 
    }
    
    cout << total_tables << endl;
      
  }
  
  
  return 0;
}