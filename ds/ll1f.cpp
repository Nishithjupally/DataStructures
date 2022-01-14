#include <bits/stdc++.h>

using namespace std;

typedef pair<char,int> pairmaker;
vector<pairmaker> sortar;

struct node
{
    char data;
    struct node* link;
};

map<char,int> counter,sorts;
struct node* root = NULL;

void display2()
{
	struct node *temp,*temp2;
    temp = root;
    temp2 = root;
    if (temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
    	cout<<temp2->data<<" ";
    	temp = temp->link;
        while(temp != NULL)
        {
            temp = temp->link;
            temp2 = temp2->link;
        }
        cout<<temp2->data;
        printf("\n");
    }

}

void print()
{
	copy(sorts.begin(),sorts.end(),back_inserter<vector<pairmaker>>(sortar));
	sort(sortar.begin(),sortar.end(),[](const pairmaker& l,const pairmaker& r)
	{
		if (l.second != r.second)
			return l.second > r.second;

		return l.first < r.first;
	});

	for (auto const &pairmaker : sortar)
	{
		cout<<pairmaker.first;
	}
	cout<<"\n";
}

void remove(int T)
{
	struct node *temp,*temp2;
    temp = root;
    temp2 = root;
    if (temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            int count = 1;
            temp2 = temp->link;
            while(temp2 != NULL && temp2->data == temp->data )
            {
            	count++;
            	temp2 = temp2->link;
            }
            
            if (count > T)
            {
            	for (int i = 0; i < T; i++)
            	{
            		cout<<temp->data;
            	}
            }
            else
            {
            	for (int i = 0; i < count; i++)
            	{
            		cout<<temp->data;
            	}
            }
	        temp = temp2;
            
        }
        cout<<"\n";
    }
}

void printer()
{
	struct node *temp,*temp2;
    temp = root;
    temp2 = root;
    if (temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            int count = 1;
            temp2 = temp->link;
            while(temp2 != NULL && counter[temp->data] != 0)
            {
            	int change = 0;
            	if (temp2->data == temp->data)
            	{
            		change = 1;
            		count++;
            	}
            	temp2 = temp2->link;
            }
            if (count != 1 || counter[temp->data] == 1)
            {
	            cout<<temp->data<<" "<< count <<" ";
	            sorts[temp->data] = count;
            }
            counter[temp->data] = 0;
	        temp = temp->link;
            
        }
        cout<<"\n";
    }
}

void append(char x)
{
    struct node* temp;
    temp = new node;
    temp->data = x;
    temp->link = NULL;

    if (root == NULL) 
    {
        root = temp;
    }
    else 
    {
        struct node* p;
        p = root;
        while(p->link != NULL)
        {
            p=p->link;
        }
        p->link = temp;
    }
}

int main() 
{

	cout<<"Just enter the string and value of T:(other functional inputs not required!)\n";
	string input;
	cin>>input;
	int t;
	cin>>t;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 97)
		{
			input[i] = input[i] - 32;
		}
		append(input[i]);
		counter[input[i]]++;
	}

 	display2();
 	printer();
 	print();
 	remove(t);
 	return 0;
}