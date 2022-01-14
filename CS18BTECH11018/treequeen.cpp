#include <bits/stdc++.h>

using namespace std;



void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void search2(int p,int visited[],int distance[]) //to print
	{
		visited[p] = 1;
		//cout<<p<<" ";
		ll distances = 0;
		for (auto i = adjacency[p].begin(); i != adjacency[p].end();++i)
		{
			if (!visited2[*i])
			{
				distance[i]= distances;
				search2(*i,visited2);
			}
			distances = 0;
		}
	}

int main()
{
	ll n,k;
	cin>>n>>k;
	vector<int> adj[n];

	for (ll i = 0; i < n-1; ++i)
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	int visited[n+1]={0},distance[n+1]={0};
	visited[1] = 1;
	ll distances = 0;
	for (int i = 0; i < n; ++i)
	{
		cout<<distance[i]<<" ";
	}


	



}
