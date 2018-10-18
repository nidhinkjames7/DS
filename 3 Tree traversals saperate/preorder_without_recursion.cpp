#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
	public:
		class node *left;
		class node *right;
		int data;
};
class tree : public node
{
	public:
		int stk[50],top;
		node *root;
		tree()
		{
			root=NULL;
			top=0;
		}
		void insert(int ch)
		{
			node *temp,*temp1;
			if(root==NULL)
			{
				root=new node;
				root->data=ch;
				root->left=NULL;
				root->right=NULL;
				return;
			}
			temp1=new node;
			temp1->data=ch;
			temp->right=temp1->left=NULL;
			temp=search(root,ch);
			if(temp->data>ch)
				temp->left=temp1;
			else
				temp->right=temp1;
		}
		node *search(node *temp,int ch)
		{
			if(root==NULL)
			{
				cout<<"No node present\n";
				return NULL;
			}
			if(temp->left=NULL && temp->right==NULL)
				return temp;
			if(temp->data>ch)
			{
				if(temp->left==NULL)
					return temp;
				search(temp->left,ch);
			}
			else
			{
				if(temp->right==NULL)
					return temp;
				search(temp->right,ch);
			}
		}
		void display(node *temp)
		{
			if(temp==NULL)
				return;
			display(temp->left);
			cout<<temp->data<<" ";
			display(temp->right);
		}
		void preorder(node *root)
		{
			node *p,*q;
			p=root;
			q=NULL;
			top=0;
			while(p!=NULL)
			{
				cout<<p->data<<" ";
				if(p->right!=NULL)
				{
					stk[top]=p->right->data;
					top++;
				}
				p=p->left;
				if(p==NULL && top>0)
				{
					p=pop(root);
				}
			}
		}
		node *pop(node *p)
		{
			int ch;
			ch=stk[top-1];
			if(p->data==ch)
			{
				top--;
				return p;
			}
			if(p->data>ch)
				pop(p->left);
			else
				pop(p->right);
		}
};
main()
{
	tree t1;
	int ch,n,i;
	cout<<"1.INSERT\n2.DISPLAY\n3.PREORDER TRAVERSAL\n4.EXIT\n";
	cout<<"Enter your choice\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter number of elements to insert\n";
			cin>>n;
			cout<<"Enter the elements\n";
			for(i=0;i<=n;i++)
			{
				cin>>ch;
				t1.insert(ch);
			}
			break;
		case 2:
			t1.display(t1.root);
			break;
		case 3:
			t1.preorder(t1.root);
			break;
		case 4:
			exit(1);
			break;
		default:
			cout<<"Invalid choice\n";
			break;
	}
}

							
