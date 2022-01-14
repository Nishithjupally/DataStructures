void ansf(vector<int> adj[],int &max,int root,vector<int> &B,int &ans,int &count)
{
	//int count = 0;
	if (B[root]==0)
	{
		B[root]=1;
	//	if(B[root])
		for(auto x =adj[root].begin();x!= adj[root].end();x++)
		{
		    if(B[*x]==0)
		    {
		        count++;
		    //	cout<<*x<<" "<<count<<"\n";
		    	ansf(adj,max,*x,B,ans,count);
		    }
			
		}
	}
//	else
//	{
		if (max < count)
		{
			max = count;
			ans = root;
		}
		count = count-1;
//		return;
///	}	
	return;
	
}

int Solution::solve(vector<int> &A) {
	int max = -1;
	int ans = 0,ans2=0;
	int root;
	if (A.size()<3)
	{
		return A.size()-1;
	}
	
	int n = A.size();
	std::vector<int> B(n,0);
	std::vector<int> adj[n];
//	int root;
	for(int i=0; i<A.size(); i++){
        if(A[i]==-1){
        	root = i;
        	continue;
        } //continue;
        adj[A[i]].push_back(i);
        adj[i].push_back(A[i]);
    }
    int count = 0;
    ansf(adj,max,root,B,ans,count);
   // cout<<max<<" \n";
    //cout<<ans<<"ans \n";
    int max2 = -1;
    std::vector<int> C(n,0);
    count = 0;
    ansf(adj,max2,ans,C,ans2,count);
    return max2;
}
