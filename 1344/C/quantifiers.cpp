/*
 * Link: https://codeforces.com/problemset/problem/1344/C
 * 
 * 
 * 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define fio ios_base::sync_with_stdio(true); cin.tie(NULL); cout.tie(NULL);
 
void print_vec(vector <int> const &s){
  cout << "<";
  for (auto const& i : s){
    cout << i << " ";
  }
  cout << ">\n";
}


void fill_order(int v, vector<vector<int>> &graph,       
                       vector<bool> &visited, 
                       vector<int> &stack){
  visited[v] = true;
  for(int child : graph[v]){
    if(!visited[child])
      fill_order(child, graph, visited, stack);
  }
  stack.push_back(v);
}


void DFS(vector<vector<int>> &graph, int root,                
         vector<bool> &visited){
  vector<int> stack;
  stack.push_back(root);
  
  while(stack.size() > 0){
    int node = stack.back();
    stack.pop_back();
    visited[node] = true;
    
    for(int child : graph[node]){
      if(!visited[child])
        stack.push_back(child);
    }
  }
}

int count_components(vector<vector<int>> &graph, vector<vector<int>> &t_graph, int n) {
    
  vector<int> stack;
  vector<bool> visited(n, false);

  for (int i = 0; i < n; i++) {
    if(!visited[i])
      fill_order(i, graph, visited, stack);
  }
    
  int num_scc = 0;
  
  vector<bool> visited_b(n, false);
  
  while(stack.size() > 0) {
    int node = stack.back();
    stack.pop_back();
    if(!visited_b[node]){
      DFS(t_graph, node, visited_b);
      num_scc += 1;
    }
  }
  
  return num_scc;
}

int main(){
  fio
  int n, m, i, u, v;
  cin >> n >> m;
  
  vector<vector<int>> graph(n);
  vector<vector<int>> transpose_graph(n);  
  vector<string> labels(200001);
  
  for (i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    transpose_graph[v].push_back(u);
  }

  int num_components = count_components(graph, transpose_graph, n);
  
  if (num_components == n) {
    string output = "";
    for (i = 0; i < n; i++) {
      if (transpose_graph.at(i).size() > 0) { output += "E"; }
      else { output += "A"; }
    }
    

    cout << count(output.begin(), output.end(), 'A') << endl;
    cout << output << endl;
    
  } else {
    cout << -1 << endl;
  }
    
  return 0;
}


