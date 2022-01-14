#include<bits/stdc++.h>

using namespace std;
int n;
typedef pair<int,int> vertexpair;
vector<pair<int,vertexpair>> edges;
set <int> verticeset;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void addEdge2(int u, int v, int w) 
{ 
    edges.push_back({u, {v, w}}); 
} 

void neighbours(vector<int> adj[],int v)
{
	for (auto i : adj[v])
	{
		cout<<i<<" ";
	}
	cout<<"\n";
}

void verticesf()
{
	cout<< "Vertices in graph : ";
	for (auto i = verticeset.begin(); i != verticeset.end() ; i++)
	{
		cout<<*i<<" ";
	}
	cout<<"\n";
}

void containsVertex(int v)
{
	int flag = 0;
	for (auto i = verticeset.begin(); i != verticeset.end() ; i++)
	{
		if (*i == v)
		{
			flag = 1;
			cout<<"Vertex "<<v<<" is present\n";
		}
	}
	if (!flag)
	{
		cout<<"Vertex "<<v<<" is not present\n";
	}
}



void edgeWeight(int v1,int v2)
{
	int flag = 0;
	for (auto i = edges.begin(); i != edges.end(); i++)
	{
		if (i->first == v1 && i->second.first == v2 || i->first == v2 && i->second.first == v1)
		{
			flag = 1;
			cout<<"Edge weight is "<<i->second.second<<" \n";
		}
	}	
	if (!flag)
	{
		cout<<"There is no edge between vertices "<<v1<<" and "<<v2<< "\n";
	}
}

void containsEdge(vector<int> adj[],int v1,int v2)
{
	int flag = 0;
	for (auto i : adj[v1])
	{
		if (i == v2)
		{
			flag = 1;
			cout<<"Edge is present between given vertices "<<v1<<" and "<<v2<<endl;
		}
	}
	if (!flag)
	{
		cout<<"No edge\n";
	}
}

int main()
{


	cout<<"Number of edges:\n";
	cin>>n;
	cout<<"\n";
	vector<int> adj[n];
	vector<int> vertices;
	vector<pair<int,vertexpair>> edges;
	for (int i = 0; i < n; i++)
	{
		char e;
		int x,y,z;
		cin>>e>>x>>y>>z;
		vertices.push_back(x);
		vertices.push_back(y);
		if (x > y)
		{
			int temp = x;
			x = y;
			y = temp;
		}
		addEdge(adj,x,y);
		addEdge2(x,y,z);
		verticeset.insert(x);
		verticeset.insert(y);
	}

	for (int i = 0; i < count; ++i)
	{
		/* code */
	}
	edgeWeight(2,3);
	edgeWeight(3,5);
	edgeWeight(1,0);
	edgeWeight(5,2);
	neighbours(adj,0);
	neighbours(adj,4);
	neighbours(adj,2);
	containsEdge(adj,1,2);
	containsEdge(adj,4,0);
	verticesf();
	containsVertex(4);
	containsVertex(10);

}