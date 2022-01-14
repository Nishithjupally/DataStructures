#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> vertexpair;
vector<bool> directed,sourcevec;
// d.assign()

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
	void search3(int p)
	{
		sourcevec[p] = true;
		//cout<<p<<" ";
		for (auto i = adjacency[p].begin(); i != adjacency[p].end();++i)
		{
			if (!sourcevec[*i])
			{
				search3(*i);
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
		//cout<<"In dij\n";
		priority_queue< vertexpair,vector <vertexpair>,greater<vertexpair> > equeue;
		vector<int> distance(n,10000000);
		equeue.push(make_pair(0, source)); 
   	    distance[source] = 0; 
   	    directed[source] = true;

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
   	    			//cout<<"In if\n";
   	    			distance[v] = distance[u] + edgeweight; 
   	    			//cout<<"In if2\n";
            	    equeue.push(make_pair(distance[v], v));
            	    //cout<<"In if3\n";
            	    directed[v] = true;
            	   // cout<<"ending if\n";
   	    		}
   	    	}
   	    }
   	    //cout<<"distance of 0 is"<<distance[0]<<"\n";
   	    for (int i = 0; i < n; ++i)
   	    {
   	    	// if (distance[i] < 10000000)
   	    	// {
   	    	// 	cout<<source<<" "<<i<<" "<<distance[i]<<"\n";
   	    	// }
   	    	if (directed[i] ==  true)
   	    	{
   	    		cout<<source<<" "<<i<<" "<<distance[i]<<"\n";
   	    	}
   	    	else if(directed[i] == false && sourcevec[i] == true) 
   	    	{
   	    		cout<<"No path from "<<source<<" to "<< i <<" in given directed graph!\n" ;
   	    	}
   	    	
   	    }
	}
};

int main()
{
	int p;
	cout<<"Enter the number of vertices:\n";
	cin>>p;
	Graph g(p);
	directed.assign(p,false);
	sourcevec.assign(p,false);
	cout<<"Input:\n";
    while(1)
    {
    	char f;
    	f = getchar();
    	if (f == 'E')
    	{
    		int x,y,w;
    		cin>>x>>y>>w;
    		g.addEdge(x,y);
    		g.addEdge2(x,y,w);
    	}
    	else if(f == '\n')
    	{
    		char f1;
	    	f1 = getchar();
	    	if (f1 == 'E')
	    	{
	    		int x,y,w;
	    		cin>>x>>y>>w;
	    		g.addEdge(x,y);
	    		g.addEdge2(x,y,w);
	    	}
	    	else if(f1 == '\n')
	    	{
	    		break;
	    	}

    	}
    }
    cout<<"Functionality input:\n";
    cout<<"(Enter find,SP,source)\n"
    string f1,f2;
    int s;
    cin>>f1;
    cin>>f2>>s;
    g.connected();
    cout<<"\n";
    g.search3(s);
    g.dijkstra(s);

    return 0;

}