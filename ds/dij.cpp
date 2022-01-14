#include <iostream>
#include <utility>
#include <list>
#include <queue>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> vertexpair;

int counter = 0;
class Graph
{
public:
	int n;
	list<int> *adjacency;
	list< pair<int, int> > *adj;
	Graph(int x)
	{
		n = x;
		adjacency = new list<int>[n];
		adj = new list<vertexpair>[n];
	}
	void addEdge(int u,int v)
	{
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}
	void addEdge2(int u, int v, int w)
	{
		adj[u].push_back(make_pair(v, w)); 
  	    //adj[v].push_back(make_pair(u, w)); 
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
	void dijkstra(int source)
	{
		priority_queue< vertexpair,vector <vertexpair>,greater<vertexpair> > equeue;
		vector<int> distance(n,10000000);
		equeue.push(make_pair(0, source)); 
   	    distance[source] = 0; 

   	    while(!equeue.empty())
   	    {
   	    	int u = equeue.top().second;
   	    	//cout<<" u is \n";
   	    	equeue.pop();
   	    	for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
   	    	{
   	    		//cout<<" in loop \n";
   	    		int v = (*i).first;
   	    		int edgeweight = (*i).second;
   	    		//cout<<distance[v]<< " "<<distance[u]<<" "<<edgeweight<<"\n";
   	    		if (distance[v] > distance[u] + edgeweight)
   	    		{
   	    			distance[v] = distance[u] + edgeweight; 
            	    equeue.push(make_pair(distance[v], v));
   	    		}
   	    	}
   	    }

   	    for (int i = 0; i < n; ++i)
   	    {
   	    	if (distance[i] < 10000000)
   	    	{
   	    		cout<<source<<" "<<i<<" "<<distance[i]<<"\n";
   	    	}
   	    	
   	    }
	}
};

int main()
{
	Graph g(17);
    {
    	char f;
    	cin>>f;
    	if (f == 'E')
    	{
    		int x,y,w;
    		cin>>x>>y>>w;
    		g.addEdge(x,y);
    		g.addEdge2(x,y,w);
    	}
    	else
    		break;
    }
    
   
    g.connected();
    g.dijkstra(1);

    return 0;

}