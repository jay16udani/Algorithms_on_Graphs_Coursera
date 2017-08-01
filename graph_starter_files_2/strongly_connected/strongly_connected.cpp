#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int clock_counter = 0;

class Vertices
{
	public:
		bool visited;
		vector <int> paths;
		
	Vertices()
	{
		visited = false;
		paths.resize(0);
	}	
};

void explore(Vertices myvertices[], int x)
{
	myvertices[x].visited = true;
	for(int i=0; i<(int)myvertices[x].paths.size(); i++)
	{
	  if(myvertices[(myvertices[x].paths)[i]].visited == false)
	  {
		  explore(myvertices,((myvertices[x].paths)[i]));
	  }
	}
}

//RUN DFS on reverse graph
void dfs_reverse_graph(Vertices reverse_graph[], int x, vector <pair<int,int> > &post_vertex)
{
	reverse_graph[x].visited = true;
	clock_counter++;
	for(int i=0; i<(int)reverse_graph[x].paths.size(); i++)
	{
	  if(reverse_graph[(reverse_graph[x].paths)[i]].visited == false)
	  {
		  dfs_reverse_graph(reverse_graph,((reverse_graph[x].paths)[i]), post_vertex);
	  }
	}
	post_vertex.push_back(make_pair(clock_counter,x));
	clock_counter++;
}

int main()
{
  int n, m,counter = 0;
  vector <pair<int,int> > post_vertex; //vector to store pairs of postvisit numbers and vertex index
  cin >> n >> m;
  
  Vertices myvertices[n];
  Vertices reverse_graph[n];
  
  for (int i = 0; i<m; i++)
  {
    int x, y;
    cin >> x >> y;
    myvertices[x - 1].paths.push_back(y - 1);
	reverse_graph[y - 1].paths.push_back(x - 1);
  }
  
  //running DFS on reverse graph for postvisit numbers
  for(int i=0; i<(int)n; i++)
  {
	  if(reverse_graph[i].visited == false)
	  {
		  dfs_reverse_graph(reverse_graph,i,post_vertex);
	  }
  }
  
  //sort the pair vector in descending order according to post visit numbers
  std::sort(post_vertex.begin(), post_vertex.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
    return left.first > right.first;
});  
  
  for(int i=0; i<(int)post_vertex.size(); i++)
  {
	  if(myvertices[post_vertex[i].second].visited == false)
	  {
		  counter++;
		  explore(myvertices,post_vertex[i].second);
	  }
  }
  
  cout << counter;
  return 0;
}
