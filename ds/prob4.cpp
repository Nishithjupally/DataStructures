#include <iostream>
#include <utility>
#include <list>

using namespace std;


int counter = 0;
class Graph
{
public:
	int n;
	list<int> *adjacency;
	Graph(int x)
	{
		n = x;
		adjacency = new list<int>[n];
	}
	void addEdge(int u,int v)
	{
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}
	void search1(int p,int visited1[])
	{
		visited1[p] = 1;
		//cout<<p<<" ";
		for (auto i = adjacency[p].begin(); i != adjacency[p].end();++i)
		{
			if (!visited1[*i])
			{
				search1(*i,visited1);
			}
		}
	}
	void search2(int p,int visited2[])
	{
		visited2[p] = 1;
		cout<<p<<" ";
		for (auto i = adjacency[p].begin(); i != adjacency[p].end();++i)
		{
			if (!visited2[*i])
			{
				search2(*i,visited2);
			}
		}
	}
	void connected()
	{
		int *visited1 = new int[n];
		int *visited2 = new int[n];
		for (int i = 0; i < n; i++)
		{
			visited1[i] = 0;
			visited2[i] = 0;
 		}
 		for (int j = 0; j < n; j++)
		{
			if (!visited1[j])
			{
				search1(j,visited1);
				counter = counter + 1;
				//cout<<"\n";
			}
		}
		cout<<counter<<" components\n";
		for (int j = 0; j < n; j++)
		{
			if (!visited2[j])
			{
				search2(j,visited2);
				cout<<"\n";
			}
		}
	}
};

int main()
{
	Graph g(10);
	g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(3, 4); 
    g.addEdge(1, 4); 
    g.addEdge(5, 6);
    g.addEdge(8, 9);
    g.addEdge(6, 7);
    //g.addEdge(7, 9);    


    cout << "Following are connected components:\n";
    g.connected();

    return 0;

}