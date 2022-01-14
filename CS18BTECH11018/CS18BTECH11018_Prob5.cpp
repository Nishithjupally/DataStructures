#include <bits/stdc++.h>

using namespace std;

int counter = 0;

class sets
{
public:
	int count,*parent,*rank;

	sets(int p)
	{
		count = p;
		parent = new int[count+1];
		rank = new int[count+1];

		for (int i = 0; i <=count; i++)
		{
			rank[i] = 0;
			parent[i] = i;
		}

	}

	int findSet(int r)
	{
		if (r != parent[r])
		{
			parent[r] = findSet(parent[r]);
		}
		return parent[r];
	}

	void mergeSets(int x,int y)
	{
		x = findSet(x);
		y = findSet(y);

		if (rank[x] > rank[y])
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}

		if (rank[x] == rank[y])
		{
			rank[y]++;
		}
	}
};

class Graph
{
public:
	int n,e;
	list<int> *adjacency;
	vector< pair<int, pair<int, int>> > edges;
	Graph(int x)
	{
		n = x;
		adjacency = new list<int>[n];
	}

	void addEdge(int u,int v,int w)
	{
		edges.push_back({w,{u,v}});
		edges.push_back({w,{v,u}});
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}

	void search1(int p,int visited1[]) //for conneeted components
	{
		visited1[p] = 1;
		for (auto i = adjacency[p].begin(); i != adjacency[p].end();++i)
		{
			if (!visited1[*i])
			{
				search1(*i,visited1);
			}
		}
	}

	void connected()
	{
		int *visited1 = new int[n];
		for (int i = 0; i < n; i++)
		{
			visited1[i] = 0;
 		}
 		for (int j = 0; j < n; j++)
		{
			if (!visited1[j])
			{
				search1(j,visited1);
				counter = counter + 1;
			}
		}
	}

	int kruskals()
	{
		int min = 0;
		sort(edges.begin(),edges.end());
		sets s(n);
		for (auto i = edges.begin(); i != edges.end(); i++)
		{
			int u = i->second.first; 
       	    int v = i->second.second; 
       	    int j = s.findSet(u);
       	    int k = s.findSet(v);

       	    if (j != k)
       	    {
       	    cout <<"(" << u << ", " << v <<")"<< endl; 
            min = min + i->first; 
            s.mergeSets(j,k); 
       	    }
		}
		return min;
	}
};

int main() 
{ 
    int vertices,edges;
  	cout<<"Enter the number of vertices:\n";
  	cin>>vertices;
  	// cout<<"Enter the number of edges:\n";
  	// cin>>edges;

  	Graph mst(vertices);

  	// for (int i = 0; i < edges; ++i)
  	// {
  	// 	char c;
  	// 	int a,b,d;
  	// 	cin>>c>>a>>b>>d;
  	// 	mst.addEdge(a,b,d);
  	// }
  	cout<<"Input:\n";
  	while(1)
  	{
  		char c;
  		int a,b,d;
  		c = getchar();
  		if(c == 'E')
  		{
  			int a,b,d;
  			cin>>a>>b>>d;
  			mst.addEdge(a,b,d);	
  		}
  		else if(c == '\n')
  		{
  			char c1;
  			int a1,b1,d1;
	  		c1 = getchar();
	  		if(c1 == 'E')
	  		{
	  			//int a,b,d;
	  			cin>>a1>>b1>>d1;
	  			mst.addEdge(a1,b1,d1);	
	  		}
	  		else if(c1 == '\n')
	  		{
	  			break;
	  		}

  		}
  		
  	}

  	mst.connected();
  	if (counter != 1)
  	{
  		cout<<"Spanning tree doesn't exist\n";
  	}
  	else
  	{
  		cout << "Edges of MST are \n"; 
   	    int mt = mst.kruskals();
  	}
  	 
    return 0; 
} 