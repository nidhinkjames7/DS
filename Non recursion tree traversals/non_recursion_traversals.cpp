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
class tree:public node
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
			temp1->right=temp1->left=NULL;
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
				cout<<"\n No node present";
				return NULL;
			}
			if(temp->left==NULL&&temp->right==NULL)
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
				if(p==NULL&&top>0)
				{
					p=pop(root);
				}
			}
		}
		void postorder(node *root)
		{
			node *p;
			p=root;
			top=0;
			while(1)
			{
				while(p!=NULL)
				{
					stk[top]=p->data;
					top++;
					if(p->right!=NULL)
						stk[top++]=-p->right->data;
					p=p->left;
				}
				while(stk[top - 1]>0||top==0)
				{
					if(top==0)
						return;
					cout<<stk[top - 1]<<" ";
					p=pop(root);
				}
				if(stk[top - 1]<0)
				{
					stk[top - 1]=-stk[top - 1];
					p=pop(root);
			
				}
			}
		}
		void inorder(node *root)
		{
			node *p;
			p=root;
			top=0;
			do
			{
				while(p!=NULL)
				{
					stk[top]=p->data;
					top++;
					p=p->left;
				}
				if(top>0)
				{
					p=pop(root);
					cout<<p->data<<" " ;
					p=p->right;
				}
			}while(top!=0||p!=NULL);
		}
		node *pop(node *p)
		{
			int ch;
			ch=stk[top - 1];
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
int main(int argc,char **argv)
{
	tree t1;
	int ch,c,i,n;
	node *temp;
	do
	{
		cout<<"\n1.INSERT\n2.DISPLAY\n3.INORDER TRAVERSAL\n4.PREORDER TRAVERSAL\n5.POSTORDER TRAVERSAL\n6.EXIT\n";
		cout<<"ENTER YOUR CHOICE:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the number of elements to be inserted:";
				cin>>n;
				cout<<"Enter the elements:";
				for(i=1;i<=n;i++)
				{
					cin>>ch;
					t1.insert(ch);
				}
				break;
			case 2:
			
				cout<<"The elements are:";
				t1.display(t1.root);
				break;
			case 3:
				cout<<"After inorder traversal\n";
				t1.inorder(t1.root);
				break;
			case 4:
				cout<<"After preorder traversal\n";
				t1.preorder(t1.root);
				break;
			case 5:
				cout<<"After postorder traversal\n";
				t1.postorder(t1.root);
				break;
			case 6:
				exit(1);
		}
		cout<<"\n";
		cout<<"Do you want to continue(1/0):";
		cin>>c;
	}while(c==1);
}

