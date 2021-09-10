/* Problem: https://codeforces.com/problemset/problem/1569/A
 * 
 * Simply check if both 'a' and 'b' exist and return the point
 * at which the string switches from 'a' to 'b' or vice-versa
 */
#include <iostream>
#include <string>

using namespace std;
#define fio                        \
  ios_base::sync_with_stdio(true); \
  cin.tie(NULL);                   \
  cout.tie(NULL);

int main()
{
  int N, n;
  string s;
  bool found;

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> n;
    cin >> s;
    found = false;

    for (int j = 0; j < n - 1; j++)
    {
      if (s[j] != s[j + 1])
      {
        cout << j + 1 << " " << j + 2 << endl;
        found = true;
        break;
      }
    }
    if (!found)
      cout << -1 << " " << -1 << endl;
  }

  return 0;
}