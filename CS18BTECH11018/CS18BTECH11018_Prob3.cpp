#include <bits/stdc++.h>

using namespace std;
int n;
typedef pair<int,int> vertexpair;
vector<pair<int,vertexpair>> edges;

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
	cout<<"Vertices in graph : ";
	for (int i = 0; i <= n-1; i++)
	{
		cout<<i<<" ";
	}
	cout<<"\n";
}

void containsVertex(int v)
{
	//int flag = 0;
	if (v <= n-1)
	{
		cout<<"Vertex "<<v<<" is present\n";
	}
	else
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
			cout<<"Edge weight is "<<i->second.second<<" between vertices "<<v1<<" and "<<v2<<"\n";
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
		cout<<"No edge between vertices "<<v1<<" and "<<v2<<"\n";
	}
}

int main()
{


	cout<<"Number of Vertices:\n";
	cin>>n;
	cout<<"\n";
	vector<int> adj[n];
	vector<int> vertices;
	vector<pair<int,vertexpair>> edges;
	cout<<"Input:\n";
	while(1)
	{
		char e;
		int x,y,z;
		e = getchar();
		if (e == 'E')
		{
			cin>>x>>y>>z;
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
			// verticeset.insert(x);
			// verticeset.insert(y);
		}
		else if(e == '\n')
		{
			char e2;
			e2 = getchar();
			if (e2 == 'E')
			{
				int x1,y1,z1;
				cin>>x1>>y1>>z1;
				vertices.push_back(x1);
				vertices.push_back(y1);
				if (x1 > y1)
				{
					int temp1 = x1;
					x1 = y1;
					y1 = temp1;
				}
				addEdge(adj,x1,y1);
				addEdge2(x1,y1,z1);
				// verticeset.insert(x1);
				// verticeset.insert(y1);
			}
			else if(e2 == '\n')
			{
				break;
			}

		}
		
	}

	cout<<"Select the function(with the alphabet before function name) and with the necessary arguments with spaces:(For example a 2 or c 2 3 or b or d 1)\n";
	cout<<"For example a 2 or c 2 3 or b:\n";
	cout<< "a.neighbours(v):\n";
	cout<< "b.vertices():\n";
    cout<< "c.edgeWeight(v1,v2)\n";
	cout<< "d.containsVertex(v)\n";
	cout<< "e.containsEdge(v1,v2)\n";

	while(1)
	{
		char choice;
		choice = getchar();

		if (choice == 'a')
		{
			int v;
			cin>>v;
			neighbours(adj,v);
		}

		else if(choice == 'b')
		{
			verticesf();
		}
		else if(choice == 'c')
		{
			int v1,v2;
			cin>>v1>>v2;
			edgeWeight(v1,v2);
		}
		else if(choice == 'd')
		{
			int v;
			cin>>v;
			containsVertex(v);
		}
		else if(choice == 'e')
		{
			int v1,v2;
			cin>>v1>>v2;
			containsEdge(adj,v1,v2);
		}
		else if(choice == '\n')
		{
			char choice2;
			choice2 = getchar();

			if (choice2 == 'a')
			{
				int v;
				cin>>v;
				neighbours(adj,v);
			}

			else if(choice2 == 'b')
			{
				verticesf();
			}
			else if(choice2 == 'c')
			{
				int v1,v2;
				cin>>v1>>v2;
				edgeWeight(v1,v2);
			}
			else if(choice2 == 'd')
			{
				int v;
				cin>>v;
				containsVertex(v);
			}
			else if(choice2 == 'e')
			{
				int v1,v2;
				cin>>v1>>v2;
				containsEdge(adj,v1,v2);
			}
			else if(choice2 == '\n')
			{
				return 0;
			}
		}



	}

}