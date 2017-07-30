#include <iostream>
#include <vector>

using namespace std;

class Vertices
{
	public:
		bool exist;//,visited;
		vector <int> paths;
		
	Vertices()
	{
		exist = true;
		//visited = false;
		paths.resize(0);
	}	
};

void acyclic_start(Vertices myvertices[], int n, int x, vector <int> &result)
{
	//myvertices[x].visited = true;
	for(int i=0; i<(int)myvertices[x].paths.size(); i++)
	{
		if(myvertices[myvertices[x].paths[i]].exist == true)
		{
			acyclic_start(myvertices,n,myvertices[x].paths[i],result);
		}
	}
	myvertices[x].exist = false;
	result.push_back(x);
}

int main()
{
  size_t n, m;
  vector <int> result;
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
	  if(myvertices[i].exist != false)
		acyclic_start(myvertices,n,i,result);
  }
  
  for(int i=0; i<(int)result.size(); i++)
	  cout << result[result.size() - i -1] + 1 << " ";
  return 0;
}
