#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;

int distance(vector<pair <pair <int,bool>,vector<int> > > &adj) {
  //write your code here
  int c = 0;
  queue <int> vertices;
  adj[0].first.second = false;
  vertices.push(0);
  
  while(!vertices.empty())
  {
	  int temp = vertices.front();
	  vertices.pop();
	  for(int i=0; i<(int)adj[temp].second.size(); i++)
	  {
		  if(adj[((adj[temp].second)[i])].first.first == -1) //when you discover a previously undiscovered edge
		  {
			  vertices.push(((adj[temp].second)[i]));
			  adj[((adj[temp].second)[i])].first.first = 1;
			  adj[((adj[temp].second)[i])].first.second = !adj[temp].first.second;
		  }
		  
		  else if(adj[((adj[temp].second)[i])].first.first == 1)
		  {
			  if(adj[((adj[temp].second)[i])].first.second != (!adj[temp].first.second))
			  {
				  c = 1;
				  break;
			  }
		  }
	  }
	  if(c == 1)
		  break;
  }
  
  if(c == 1)
	  return 0;
  else
	return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<pair <pair<int,bool>, vector<int> > > adj(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].second.push_back(y - 1);
    adj[y - 1].second.push_back(x - 1);
  }
  //setting all the vertices to being undiscovered
  for(int i=0; i<n; i++)
	  adj[i].first.first = -1;
  
  std::cout << distance(adj);
  return 0;
}
