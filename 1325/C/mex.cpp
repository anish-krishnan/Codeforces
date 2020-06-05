/*
  * Link: https://codeforces.com/contest/1325/problem/C
  * 
  * Algorithm: Greedily assign increasing labels
  *  in decreasing order of degrees of vertices.
  * 
  *  So first choose the highest degree vertex,
  *  and assign increasing labels along the 
  *  incident edges, and so on.
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm> 
 
#define ll long long
using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);
 
// Adj list mapping vertex to degree
vector<pair<int, int>> degrees;
 
// Vector mapping index to pair(u,v)
vector<pair<int, int>> order;
 
// Adjacency matrix
unordered_map<int, unordered_map<int,int>> M; 
 
// Visited array
int visited[100002];
 
 
void printDegrees(){
    for(size_t i=0; i<degrees.size(); i++){
        cout << "deg(" << degrees[i].first << "): " << degrees[i].second << endl;
    }
}
 
// Returning vector of pairs (vertex, deg(vertex))
void map_to_degree(int n){
    for(int i=0; i<n; i++){
      int vertex = i;
      int deg = M[i].size();
      degrees.push_back(make_pair(vertex, deg));
    }
}
 
void bfs(int n) {
    int label = 0;
    for (int i = 0; i < n; i++) {
        
        // Retrieve the vertex with ith highest degree
        int u = degrees[i].first;   
        
        // Mark as visited
        visited[u] = 1;
        unordered_map<int, int> neighbors = M[u];
        
        for (auto pair : neighbors) {
            
            int v = pair.first;
            // For some pair (u,v), if we have not seen v...
            if (!visited[v]) {
                M[u][v] = label;
                M[v][u] = label;
                label++;
            }
        }
    }
}
    
 
void printResult() {
  for(int i=0; i < order.size(); i++){
    int u = order[i].first;
    int v = order[i].second;
    int label = M[u][v];
    cout << label << endl;
  }
}
 
int main() {
   fio
   int n, u, v, i;
   
   cin >> n;
   for (i = 1; i < n; i++) {
      cin >> u >> v;
      u--;
      v--;
      M[u][v] = -1;
      M[v][u] = -1;
      order.push_back(make_pair(u,v));
   }
   
   map_to_degree(n);
  
   std::sort(degrees.begin(), degrees.end(), 
             [](const pair<int,int> & a, const pair<int,int> & b){ 
      return a.second > b.second; 
   });
 
   bfs(n);
   printResult();
  
   return 0;
}
 
 
 