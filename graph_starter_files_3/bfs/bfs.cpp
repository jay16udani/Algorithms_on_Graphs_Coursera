#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;

int distance(vector<pair <int,vector<int> > > &adj, int s, int t) {
  //write your code here
  int c = 0;
  queue <int> vertices;
  adj[s].first = 0;
  vertices.push(s);
  
  while(!vertices.empty())
  {
	  int temp = vertices.front();
	  vertices.pop();
	  for(int i=0; i<(int)adj[temp].second.size(); i++)
	  {
		  if(adj[((adj[temp].second)[i])].first == -1)
		  {
			  vertices.push(((adj[temp].second)[i]));
			  adj[((adj[temp].second)[i])].first = (adj[temp].first) + 1;
			  if(((adj[temp].second)[i]) == t)
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
	  return adj[t].first;
  else
	return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<pair <int, vector<int> > > adj(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].second.push_back(y - 1);
    adj[y - 1].second.push_back(x - 1);
  }
  //setting all the distances initially to infinity(-1)
  for(int i=0; i<n; i++)
	  adj[i].first = -1;
  
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
