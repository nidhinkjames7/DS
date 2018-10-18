#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
class btree1
{
	private:
		struct btreenode
		{
			btreenode *leftchild;
			int data;
			btreenode *rightchild;
		}*root;
	public:
		btree1();
		void buildtree(int num);
		static void insert(btreenode **sr,int);
		static void search(btreenode **sr,int num,btreenode **par,btreenode  **x,int *found);
		void remove(int num);
		static void inorder(btreenode *sr);
		void display();
		static void rem(btreenode **sr,int num);
		~btree1();
		static void del(btreenode *sr);
};
btree1::btree1()
{
	root=NULL;
}
void btree1::buildtree(int num)
{
	insert(&root,num);
}
void btree1::insert(btreenode **sr,int num)
{
	if(*sr==NULL)
	{
		*sr=new btreenode;
		(*sr)->leftchild=NULL;
		(*sr)->data=num;
		(*sr)->rightchild=NULL;
	}
	else
	{
		if(num<(*sr)->data)
			insert(&((*sr)->leftchild),num);

		else


			insert(&((*sr)->rightchild),num);
	}
}
void btree1::remove(int num)
{
	rem(&root,num);
}
void btree1::rem(btreenode **sr,int num)
{
	int found;
	btreenode *parent,*x,*xsucc;
	if(*sr==NULL)
	{	
		cout<<"\n Tree is empty\n";
		return;
	}
	parent=x=NULL;
	search(sr,num,&parent,&x,&found);
	if(found==FALSE)
	{
		cout<<"\n Data to be deleted is not present\n";
		return;
	}
	if(x->leftchild!=NULL&&x->rightchild!=NULL)
	{
		parent=x;
		xsucc=x->rightchild;
		while(xsucc->leftchild!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->leftchild;
		}
		x->data=xsucc->data;
		x=xsucc;
	}
	if(x->leftchild==NULL&&x->rightchild==NULL)
	{
		if(parent->rightchild==x)
			parent->rightchild=NULL;
		else
			parent->leftchild=NULL;
		delete x;
		return;
	}
	if(x->leftchild==NULL&&x->rightchild!=NULL)
	{
		if(parent->leftchild==x)
			parent->leftchild=x->rightchild;
		else
			parent->rightchild=x->rightchild;
		delete x;
		return;
	}
	if(x->leftchild!=NULL&&x->rightchild==NULL)
	{
		if(parent->leftchild==x)
			parent->leftchild=x->rightchild;
		else
			parent->rightchild=x->leftchild;
		delete x;
		return;
	}
}
void btree1::search(btreenode **sr,int num,btreenode **par,btreenode **x,int *found)
{
	btreenode *q;
	q=*sr;
	*found=FALSE;
	*par=NULL;
	while(q!=NULL)
	{
		if(q->data==num)
		{
			*found=TRUE;
			*x=q;
			return;
		}
		*par=q;
		if(q->data>num)
			q=q->leftchild;
		else
			q=q->rightchild;
	}
}
void btree1::display()
{
	inorder(root);
}
void btree1::inorder(btreenode *sr)
{
	if(sr!=NULL)
	{
		inorder(sr->leftchild);
		cout<<sr->data<<"\t";
		inorder(sr->rightchild);
	}
}
btree1::~btree1()
{
	del(root);
}
void btree1::del(btreenode *sr)
{
	if(sr!=NULL)
	{
		del(sr->leftchild);
		del(sr->rightchild);
	}
	delete sr;
}
int main()
{
	cout<<"\n BINARY SEARCH TREE\n----------------------";
	cout<<"\n";
	btree1 bt;
	int req,i=0,num;

	int a[]={17,52,13,24,55,66,78,80,91};
	while(i<=8)
	{
		bt.buildtree(a[i]);

		i++;
	}
	cout<<"\nBinary tree before deletion:\n";
	bt.display();	
	bt.remove(17);
	cout<<"\n Binary tree after deletion:\n";
	bt.display();
	bt.remove(55);
	cout<<"\n Binary tree after deletion:\n";
	bt.display();
	bt.remove(80);
	cout<<"\n Binary tree after deletion:\n";
	bt.display();
}
