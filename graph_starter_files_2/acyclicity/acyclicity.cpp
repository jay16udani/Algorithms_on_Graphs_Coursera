#include <iostream>
#include <vector>

using namespace std;

class Vertices
{
	public:
		bool exist,visited;
		vector <int> paths;
		
	Vertices()
	{
		exist = true;
		visited = false;
		paths.resize(0);
	}	
};

int acyclic_start(Vertices myvertices[], int n, int x)
{
	myvertices[x].visited = true;
	for(int i=0; i<(int)myvertices[x].paths.size(); i++)
	{
		if(myvertices[myvertices[x].paths[i]].exist == true)
		{
			if(myvertices[myvertices[x].paths[i]].visited == true) //found a cycle
				return 1;
			else // continue on quest of finding the sink
			{
				int c = acyclic_start(myvertices,n,myvertices[x].paths[i]);
				if(c == 1)
					return 1;
			}
		}
	}
	myvertices[x].exist = false;
	return 0;
}

int main()
{
  size_t n, m;
  int x =0;
  int answer = 0;
  cin >> n >> m;
  
  Vertices myvertices[n];
  
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    myvertices[x - 1].paths.push_back(y - 1);
  }
  
  for(int i=0; i<(int)n; i++)
  {
	  //cout << "x is: " << x << endl;
	  answer = answer || acyclic_start(myvertices,n,x);
	  x++;
  }
  
  cout << answer;
  return 0;
}
