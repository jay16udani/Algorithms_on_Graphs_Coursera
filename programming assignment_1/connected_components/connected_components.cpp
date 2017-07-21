#include <iostream>
#include <vector>

using std::vector;
using std::pair;


void reach(vector<pair<bool,vector<int> > > &adj, int x)
{
  //DFS implementation
  adj[x].first = 1;
  for(int i=0; i<(int)adj[x].second.size(); i++)
  {
	  if(adj[(adj[x].second)[i]].first == 0)
	  {
		  reach(adj,((adj[x].second)[i]));
	  }
  }
}

int main() {
  size_t n, m;
  int counter = 0;
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
  for(int i=0; i<(int)n; i++)
  {
	  if(adj[i].first == 0)
	  {
		  reach(adj,i);
		  counter++;
	  }
  }
  std::cout << counter << std::endl;
  return 0;
}
