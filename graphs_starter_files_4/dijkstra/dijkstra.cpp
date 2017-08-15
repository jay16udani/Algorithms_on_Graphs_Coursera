#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

bool find_in_closed_set(int value, vector <pair<int,int> > closedset)
{
	bool y_n = false;
	for(int i=0; i<(int)closedset.size(); i++)
	{
		if(closedset[i].first == value)
		{
			y_n = true;
			break;
		}
	}
	
	return y_n;
}

int distance(vector<vector<pair<int,int> > > &adj, int s, int t)
{
	auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
	{
		return lhs.second > rhs.second;
	};	
	priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> openset(cmp);

	vector <pair<int,int> > closedset;
	pair<bool,bool> success_fail;
	
	success_fail.first = success_fail.second = false;
	closedset.push_back(make_pair(s,0));
	
	while(1)
	{
		if(closedset[closedset.size() - 1].first == t)
		{
			success_fail.first = true;
			break;
		}
		if(closedset.size()== adj.size())
		{
			success_fail.second = true;
			break;
		}
		for(int i=0; i<(int)adj[closedset[closedset.size() - 1].first].size(); i++)
		{
			if(find_in_closed_set(adj[closedset[closedset.size() - 1].first][i].first, closedset) == false)
			{
				openset.push(make_pair(adj[closedset[closedset.size() - 1].first][i].first, adj[closedset[closedset.size() - 1].first][i].second + closedset[closedset.size() - 1].second));
			}
		}
		
		if(openset.empty() == false)
		{
			while(1)
			{
				if(find_in_closed_set((openset.top()).first, closedset) == false)
				{
					closedset.push_back(make_pair((openset.top()).first,(openset.top()).second));
					openset.pop();
					break;
				}
				else
				{
					openset.pop();
				}
			}
		}
		else
		{
			success_fail.second = true;
			break;
		}
	}
	
	if(success_fail.first == true)
		return closedset[closedset.size() - 1].second;
	else
		return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<pair<int,int> > > adj(n); //pair of nodes and weights
  
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
	adj[x - 1].push_back(make_pair(y - 1,w));
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
