#include <iostream>
using namespace std;

struct node
{
	struct node* parent;
	int data;
	struct node* left;
	struct node* right;
};

struct node *createNode(int element)
{
	struct node *temp = new struct node;
	temp->right = NULL;
	temp->left = NULL;
	temp->data = element;
	
};

void predecessor(struct node* root,int givennode,struct node* &predec)
{
	if (root == NULL)
	{
		return;
	}
	if (root->data == givennode)
	{
		if (root->left != NULL)
		{
			struct node *temp = root->left;
			while(temp->right)
			{
				temp = temp->right;
			}
			predec = temp;
		}
		return;
	}
	 if (root->data > givennode) 
    { 
        predecessor(root->left, givennode,predec); 
    } 
    else
    {
    	predec = root;
    	predecessor(root->right,givennode,predec); 
    }
}

void successor(struct node* root,int givennode,struct node* &succes)
{
	if (root == NULL)
	{
		return;
	}
	if (root->data == givennode)
	{
		if (root->right != NULL)
		{
			struct node *temp = root->right;
			while(temp->left)
			{
				temp = temp->left;
			}
			succes = temp;
		}
		return;
	}
	if (root->data > givennode) 
    { 
    	succes = root;
        successor(root->left, givennode,succes); 
    } 
    else
    {
    	successor(root->right,givennode,succes); 
    }
}

struct node *insert(struct node* rootnode, int value)
{
	if (rootnode == NULL)
	{
		return createNode(value);
	}

	if (value < rootnode->data)
	{
		rootnode->left = insert(rootnode->left,value);
	}
	else
	{
		rootnode->right = insert(rootnode->right,value);
	}
	return rootnode;
}

void minimum(struct node* root, int value,struct node* &min)
{
	if (root == NULL)
	{
		return;
	}
	if (root->data == value)
	{
		while(root->left!=NULL)
		{
			min = root->left;
			root = root->left;
		}
		return;
	}
	if (root->data > value) 
    { 
        minimum(root->left, value,min); 
    } 
    else
    {
    	 minimum(root->right, value,min); 
    }
}

void maximum(struct node* root, int value,struct node* &max)
{
	if (root == NULL)
	{
		return;
	}
	if (root->data == value)
	{
		while(root->right!=NULL)
		{
			max = root->right;
			root = root->right;
		}
		return;
	}
	if (root->data > value) 
    { 
        maximum(root->left, value,max); 
    } 
    else
    {
        maximum(root->right, value,max); 
    }
}

struct node *commonancestor(struct node *root,int x,int y)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data > x && root->data > y)
	{
		return commonancestor(root->left,x,y);
	}

	if (root->data < x && root->data < y)
	{
		return commonancestor(root->right,x,y);
	}
	return root;

}

// int main()
// {
// 	struct node *root = NULL;
// 	root = insert(root,50);
// 	insert(root, 30); 
//     insert(root, 20); 
//     insert(root, 40); 
//     insert(root, 70); 
//     insert(root, 60); 
//     insert(root, 80); 
//     int key = 40;

//     struct node *pre = NULL; 
//     struct node *suc = NULL;
//     predecessor(root,key,pre);

//     if (pre != NULL) 
//       cout << "Predecessor is " << pre->data << endl; 
//     else
//       cout << "No Predecessor\n"; 

//   	successor(root,key,suc);
//   	if (suc != NULL) 
//       cout << "Successor is " << suc->data <<endl; 
//     else
//       cout << "No Successor\n"; 

//     struct node *min = NULL,*max = NULL;
//     minimum(root,key,min);

//     if (min != NULL) 
//       cout << "MIN is " << min->data << endl; 
//     else
//       cout << "No MIn\n"; 

//   	maximum(root,key,max);
//   	successor(root,key,suc);
//   	if (max != NULL) 
//       cout << "MAX is " << max->data; 
//     else
//       cout << "No MAx\n"; 
//     return 0; 

// }

int main()
{
	struct node *root = NULL;
	int n;
	cout<<"Enter the number of nodes :";
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	root = insert(root,a[0]);
	for (int i = 1; i < n; i++)
	{
		insert(root,a[i]);
	}
	cout<<"Choose the function or enter 'e' to exit:\n";
	while(1)
	{
		char choice;
		cin>>choice;

		if (choice == 'M')
		{
			int key;
			cin>>key;
			struct node *min = NULL,*max = NULL;
			minimum(root,key,min);
			maximum(root,key,max);
			if (min != NULL)
			{
				cout << min->data << " "; 
			}
			else if(min == NULL)
			{
				cout << key<<" ";
			}
			if (max != NULL)
			{
				cout << max->data << " "; 
			}
			else if(max == NULL)
			{
				cout << key;
			}
			cout<<"\n";
		}

		else if(choice == 'P')
		{
			int key;
			cin>>key;
			struct node *pre = NULL;
			predecessor(root,key,pre);

  		    if (pre != NULL)
  		    {
  			  	cout << pre->data <<" "<< endl;
  			} 
      			 
    		else
    		{
      			cout << "No Predecessor"<<endl; 
    		}
    		//cout<<"\n";
		}
		else if(choice == 'S')
		{
			int key;
			cin>>key;
			struct node *suc = NULL;
			successor(root,key,suc);

  		    if (suc != NULL)
  		    {
  			  	cout << suc->data<<" "<<endl;
  			} 
      			 
    		else
    		{
      			cout << "No Successor"<<endl; 
    		}
    		//cout<<"\n";
		}
		else if(choice == 'C')
		{
			int a,b;
			cin>>a>>b;
			struct node *ancestor = NULL;
			ancestor = commonancestor(root,a,b);
			int c = ancestor->data;
			cout<<c<<endl;
		}
		else if(choice == 'E')
		{
			return 0;	
		}
	}
}