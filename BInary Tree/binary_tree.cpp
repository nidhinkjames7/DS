#include<iostream>
using namespace std;
struct node
{
	node* left;
	char data;
	node *right;
};
class btree
{
	private:
		node* root;
		char* arr;
		int* lc;
		int* rc;
		int size;
	public:
		btree(char *a,int *l,int *r,int size);
		void insert(int index);
		static node *buildtree(char *a,int *l,int *r,int index);
		void display();
		static void inorder(node *sr);
		~btree();
		static void del(node *sr);
};
btree::btree(char *a,int *l,int *r,int size)
{
	root=NULL;
	arr=new char[size];
	lc=new int[size];
	rc=new int[size];
	for(int i=0;i<size;i++)
	{
		*(arr+i)=*(a+i);
		*(lc+i)=*(l+i);
		*(rc+i)=*(r+i);
	}
}
void btree::insert(int index)
{
	root=buildtree(arr,lc,rc,index);
}
node* btree::buildtree(char *a,int *l,int *r,int index)
{
	node* temp=NULL;
	if(index!=-1)
	{
		temp=new node;
		temp->left=buildtree(a,l,r,*(l+index));
		temp->data=*(a+index);
		temp->right=buildtree(a,l,r,*(r+index));
	}
	return temp;
}
void btree::display()
{
	inorder(root);
}
void btree::inorder(node *sr)
{
	if(sr!=NULL)
	{
		inorder(sr->left);
		cout<<sr->data<<"\t";
		inorder(sr->right);
	}
}
btree::~btree()
{
	delete arr;
	delete lc;
	delete rc;
	del(root);
}
void btree::del(node* sr)
{
	if(sr!=NULL)
	{
		del(sr->left);
		del(sr->right);
	}
	delete sr;
}
main()
{
	cout<<"Creating binary tree\n";
	char a[]={'A','B','C','D','E','F','G','\0','\0','H'};
	int l[]={1,3,5,-1,9,-1,-1,-1,-1,-1};
	int r[]={2,4,6,-1,-1,-1,-1,-1,-1,-1};
	int sz=sizeof(a);
	btree bt(a,l,r,sz);
	bt.insert(0);
	cout<<"Inorder traversal of binary tree\n";
	bt.display();
}

