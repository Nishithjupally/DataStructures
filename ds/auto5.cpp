#include<bits/stdc++.h>

using namespace std;

struct StructEdge{
	int source,dest,weight;
};





struct StructGraph{
	int V,E;
	StructEdge* edge;
};





StructGraph* newgraph(int V){
	StructGraph* graph = new struct StructGraph;
	graph->V=V;

	return graph;

	// graph->edge = new struct StructEdge[E];
	// return graph;
}




struct subset{
	int parent;
	int rank;
};




int find(subset subsets[],int i){
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets,subsets[i].parent);
	return subsets[i].parent;
}




void Union(subset subsets[],int x,int y){
	int xr=find(subsets,x);
	int yr=find(subsets,y);

	if(subsets[xr].rank > subsets[yr].rank)
		subsets[yr].parent = xr;
	else if(subsets[xr].rank < subsets[yr].rank)
		subsets[xr].parent = yr;
	else{
		subsets[yr].parent = xr;
		subsets[xr].rank++;
	}
}




int Comp(const void* a, const void* b){
	StructEdge* a1=(StructEdge*)a;
	StructEdge* b1=(StructEdge*)b;
	return a1->weight > b1->weight;
}




void Krushkal(StructGraph* graph){
	int V= graph->V;
	StructEdge result[V];
	int e=0,i=0;

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]),Comp);

	subset *subsets = new subset[(V * sizeof(subset))];

	for(int j=0;j<V;j++){
		subsets[j].parent=j;
		subsets[j].rank=0;
	}

	while(e < V-1 && i < graph->E){
		StructEdge nextEdge = graph->edge[i];
		i++;
		int x= find(subsets, nextEdge.source);
		int y= find(subsets, nextEdge.dest);

		if(x-y != 0){
			result[e]=nextEdge;
			e++;
			Union(subsets,x,y);
		}
	}
  cout<<"Weights of MST In Krushkal are :"<<endl;
	for(int i=0;i<e;i++){
		cout<<"("<<result[i].source<<","<<result[i].dest<<")";
	}
	cout<<endl;
	return;
}


int CounterKrush(StructGraph* graph){
	int counter=0;
	int V= graph->V;
	StructEdge result[V];
	int e=0,i=0;

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]),Comp);

	subset *subsets = new subset[(V * sizeof(subset))];

	for(int j=0;j<V;j++){
		subsets[j].parent=j;
		subsets[j].rank=0;
	}

	while(e < V-1 && i < graph->E){
		StructEdge nextEdge = graph->edge[i];
		i++;
		int x= find(subsets, nextEdge.source);
		int y= find(subsets, nextEdge.dest);

		if(x-y != 0){
			result[e]=nextEdge;
			e++;
			Union(subsets,x,y);
		}
	}
 // cout<<"Weights of MST In Krushkal are :"<<endl;
	for(int i=0;i<e;i++){
		//cout<<"("<<result[i].source<<","<<result[i].dest<<")";
		counter++;
	}
	return counter;
}




int main(){

	int V,E;
	cin>>V>>E;
	char ch;
	int l,r,w;
	StructGraph* graph = newgraph(V);

	for(int i=0;i<E;i++){
		cin>>ch;
		
			cin>>l>>r>>w;
            graph->edge[i].source=l;
            graph->edge[i].dest=r;
            graph->edge[i].weight=w;
		
	}
	// int i = 0;
	// while(1)
	// {
	// 	ch = getchar();
	// 	if (ch == 'E')
	// 	{
	// 		cin>>l>>r>>w;
 //            graph->edge[i].source=l;
 //            graph->edge[i].dest=r;
 //            graph->edge[i].weight=w;
 //            i++;
	// 	}
	// 	else if (ch == '\n')
	// 	{
	// 		char ch2;
	// 		ch2 = getchar();
	// 		if (ch2 == 'E')
	// 		{
	// 			cin>>l>>r>>w;
	//             graph->edge[i].source=l;
	//             graph->edge[i].dest=r;
	//             graph->edge[i].weight=w;
	//             i++;
	// 		}
	// 		else if(ch2 == '\n')
	// 		{
	// 			break;
	// 		}
	// 	}
	// }
	if(CounterKrush(graph)==V-1)
	Krushkal(graph);
    else
  	cout<<"Minimum Spanning Tree is Not possible"<<endl;
}