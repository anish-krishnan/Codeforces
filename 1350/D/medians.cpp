#include <iostream>

#define ll long long
using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);

ll A[100002];

string solve(int n, ll k){
   // find pair (A[i], A[i+1])  k <= A[i] <= A[i+1]
   bool k_exists = (A[n-1] == k);
   bool pair_exists = false;
   bool triple_exists = false;
   for(int i=0; i < n - 1; i++){
      if(A[i] == k) 
         k_exists = true;
      if(k <= A[i] && k <= A[i+1])
         pair_exists = true;
   }

   for(int i=0; i < n - 2; i++){
      bool a = A[i] >= k;
      bool b = A[i+1] >= k; 
      bool c = A[i+2] >= k ;
      
      if(a + b + c >= 2)
         triple_exists = true;
   }
   
   return k_exists && (n == 1 || pair_exists || triple_exists) ? "yes" : "no";
}


int main() {
   fio
   int epochs, n, i, j;
   ll k;
   
   cin >> epochs;
   for (i = 0; i < epochs; i++) {
      cin >> n >> k;
      for (j = 0; j < n; j++) {
         cin >> A[j];
      }
      cout << solve(n,k) << endl;
   }
   return 0;
}