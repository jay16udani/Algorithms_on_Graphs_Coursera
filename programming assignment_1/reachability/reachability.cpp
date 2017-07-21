#include <iostream>
#include <vector>

using std::vector;
using std::pair;


int reach(vector<pair<bool,vector<int> > > &adj, int x, int y) {
  //DFS implementation
  if(x == y )
	  return 1;
  else
  {
	  adj[x].first = 1;
	  for(int i=0; i<(int)adj[x].second.size(); i++)
	  {
		  if(adj[(adj[x].second)[i]].first == 0)
		  {
			  if(((adj[x].second)[i]) == y)
				  return 1;
			  else
			  {
				  int c = reach(adj,((adj[x].second)[i]),y);
				  if(c==1)
					  return 1;
			  }
		  }
	  }
	  return 0;
  }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<pair<bool,vector<int> > > adj(n);
  
  for(int i=0; i<(int)n; i++)
	  adj[i].first = 0;
  
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].second.push_back(y - 1);
    adj[y - 1].second.push_back(x - 1);
  }
  /*std::cout << "\nGraph is:\n";
  for(int i=0; i<(int)adj.size(); i++)
  {
	  std::cout << i+1 << " ";
	  for(int j=0; j<(int)adj[i].second.size(); j++)
		  std::cout << ((adj[i].second)[j])+1 << " ";
	  std::cout << "\n";
  }*/
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
