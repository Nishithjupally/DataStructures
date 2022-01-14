#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

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
	vector< pair<int, pair<int, int>> > edges;
	Graph(int x,int y)
	{
		n = x;
		e = y;
	}

	void addEdge(int u,int v,int w)
	{
		edges.push_back({w,{u,v}});
		edges.push_back({w,{v,u}});
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
    /* Let us create above shown weighted 
       and unidrected graph */
    // int V = 6, E = 8; 
    // Graph g(V, E); 
  
    // //  making above shown graph 
    // g.addEdge(0, 2, 5); 
    // g.addEdge(0, 1, 11); 
    // g.addEdge(2, 3, 7); 
    // g.addEdge(2, 1, 3); 
    // g.addEdge(1, 4, 1); 
    // g.addEdge(4, 3, 2); 
    // g.addEdge(4, 5, 7);  
    // g.addEdge(3, 5, 3); 

    // cout << "Edges of MST are \n"; 
    // int mst_wt = g.kruskals(); 
  
    // cout << "\nWeight of MST is " << mst_wt; 
    int vertices,edges;
  	cout<<"Enter the number of vertices:\n";
  	cin>>vertices;
  	cout<<"Enter the number of edges:\n";
  	cin>>edges;

  	Graph mst(vertices,edges);

  	for (int i = 0; i < edges; ++i)
  	{
  		char c;
  		int a,b,d;
  		cin>>c>>a>>b>>d;
  		mst.addEdge(a,b,d);
  	}

  	cout << "Edges of MST are \n"; 
    int mt = mst.kruskals(); 
  
    // cout << "\nWeight of MST is " << mst_wt;

    return 0; 
} 