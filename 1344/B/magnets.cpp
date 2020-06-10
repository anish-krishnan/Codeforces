/*
  * Link: https://codeforces.com/problemset/problem/1344/B
  * 
  * Algorithm: 
  *   1) Convexity. All black regions must be convex.
  *       We can verify this by checking for 
  *       [black] ... [white ... white] ... [black]
  *   
  *   2) Every row & col contains atleast 1 black square 
  *       OR we are able to place South magnets on white squares
  * 
  *   3) Return numIslands where an island is region of black squares
  *  
  * Runtime: O(n^2)
 */
 
#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);
 
void print_set(unordered_set <int> const &s){
  cout << "{";
  for (auto const& i : s){
    cout << i << " ";
  }
  cout << "}\n";
}

void print_grid(vector<vector<int>> grid){
  int n = grid.size();
  int m = grid[0].size();
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << grid[i][j] << " ";
    }
  cout << endl;
  }
}
 
bool check_convexity(vector<vector<int>> &grid){
  int n = grid.size();
  int m = grid[0].size();
 
  bool saw_black, saw_white;
 
  for(int i=0; i<n; i++){
    saw_black = false;
    saw_white = false;
    for(int j=0; j<m; j++){
      if(grid[i][j] == 0)
        saw_black = true;
      if(saw_black && grid[i][j] == 1)
        saw_white = true;
      if(saw_black && saw_white && grid[i][j] == 0)
        return false;
    }
  }
  for(int j=0; j<m; j++){
    saw_black = false;
    saw_white = false;
    for(int i=0; i<n; i++){
      if(grid[i][j] == 0)
        saw_black = true;
      if(saw_black && grid[i][j] == 1)
        saw_white = true;
      if(saw_black && saw_white && grid[i][j] == 0)
        return false;
    }
  }
  return true;
}


bool check_row_col(vector<vector<int>> &grid, unordered_set<int> &black_rows, unordered_set<int> &black_cols){
  int n = grid.size();
  int m = grid[0].size();
  
  unordered_set <int> filled_white_rows;
  unordered_set <int> filled_white_cols;
      
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(grid[i][j] == 1 && black_rows.find(i) == black_rows.end() && 
            black_cols.find(j) == black_cols.end()){
          filled_white_rows.insert(i);
          filled_white_cols.insert(j);
      }
    }
  }
  
  int total_rows = black_rows.size() + filled_white_rows.size();
  int total_cols = black_cols.size() + filled_white_cols.size();
  return total_rows == n && total_cols == m;
}
 
 
bool is_new_island(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j){
  int n = grid.size();
  int m = grid[0].size();
 
  if(!(i >= 0 && i < n && j >=0 && j < m))
    return false;
  if(visited[i][j] || grid[i][j] == 1){
    return false;
  }
 
  visited[i][j] = true;
  is_new_island(grid, visited, i-1, j);
  is_new_island(grid, visited, i+1, j);
  is_new_island(grid, visited, i, j-1);
  is_new_island(grid, visited, i, j+1);
  return true;
}
 
int num_islands(vector<vector<int>> &grid){
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> visited(
    n,
    vector<int>(m, 0));

  int count = 0;
 
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(!visited[i][j] && is_new_island(grid, visited, i, j))
        count += 1;
    }
  }
  return count;
}
 
int main(){
  fio
  int n, m;
  char c;
  cin >> n >> m;
  
 
  vector<vector<int>> grid(
    n,
    vector<int>(m, -1));
  
  unordered_set <int> blackRows; 
  unordered_set <int> blackCols; 
 
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> c;
      if(c == '.'){
        grid[i][j] = 1;
      } else if(c == '#'){
        grid[i][j] = 0;
        blackRows.insert(i);
        blackCols.insert(j);
      }
    }
  }

  bool is_convex = check_convexity(grid);
  bool is_row_col = check_row_col(grid, blackRows, blackCols);
 
  if(is_convex && is_row_col)
    cout << num_islands(grid) << endl;
  else
    cout << "-1" << endl;
 
  return 0;
}


