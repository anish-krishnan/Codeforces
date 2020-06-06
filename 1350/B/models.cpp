/*
  * Link: https://codeforces.com/contest/1350/problem/B
  * 
  * Algorithm: Dynamic Programming Brute Force Algorithm. 
  *  We use a memo table to brute force the solution space.
  *  
  * Runtime: O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);

int A[100002];
int n;

int DP(int i, vector<int> &memo){
  if(i > n){
    return 0;
  } else {
    if(memo[i] != -1){
        return memo[i];
    }
    vector<int> results;
    for(int k=2*i; k <= n; k += i){
      if(A[k-1] > A[i-1])
        results.push_back(DP(k, memo));
      else
        DP(k, memo);
    }
    if(results.size() > 0){
      int max_elem = *max_element(results.begin(), results.end());
      memo[i] = 1 + max_elem;
      return 1 + max_elem;
    } else {
      memo[i] = 1;
      return 1;
    }
  }
}

int main() {
  fio
  int epochs;

  cin >> epochs;

  for (int i = 0; i < epochs; i++) {
    cin >> n;
    for(int j = 0; j < n; j++){
      cin >> A[j];
    }
    vector<int> memo(n+1, -1);
    DP(1, memo);
    int max_elem = *max_element(memo.begin(), memo.end());
    cout << max_elem << endl;
  }
  return 0;
}