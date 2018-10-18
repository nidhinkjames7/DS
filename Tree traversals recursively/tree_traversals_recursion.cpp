#include<iostream>
using namespace std;
class btree
{
	private:
		struct btreenode
		{
			btreenode *leftchild;
			int data;
			btreenode *rightchild;
		}*root;
	public:
		btree();
		void buildtree(int num);
		static void insert(btreenode **sr,int num);
		void traverse();
		static void inorder(btreenode *sr);
		static void preorder(btreenode *sr);
		static void postorder(btreenode *sr);
		~btree();
		static void del(btreenode *sr);
};
btree::btree()
{
	root=NULL;
}
void btree::buildtree(int num)
{
	insert(&root,num);
}
void btree::insert(btreenode **sr,int num)
{
	if(*sr==NULL)
	{
		*sr=new btreenode;
		(*sr)->leftchild=NULL;
		(*sr)->data=num;
		(*sr)->rightchild=NULL;
		return;
	}
	else
	{
		if(num<(*sr)->data)
			insert(&((*sr)->leftchild),num);
		else
			insert(&((*sr)->rightchild),num);
	}
	return;
}
void btree::traverse()
{
	cout<<"Inorder Traversal:";
	inorder(root);
	cout<<"\nPreorder Traversal:";
	preorder(root);
	cout<<"\nPostorder Traversal:";
	postorder(root);
	cout<<"\n";
}
void btree::inorder(btreenode *sr)
{
	if(sr!=NULL)
	{
		inorder(sr->leftchild);
		cout<<"\t"<<sr->data;
		inorder(sr->rightchild);
	}
	else
		return;
}
void btree::preorder(btreenode *sr)
{
	if(sr!=NULL)
	{
		cout<<"\t"<<sr->data;
		preorder(sr->leftchild);
		preorder(sr->rightchild);
	}
	else
		return;
}
void btree::postorder(btreenode *sr)
{
	if(sr!=NULL)
	{
		postorder(sr->leftchild);
		postorder(sr->rightchild);
		cout<<"\t"<<sr->data;

	}
	else
		return;
}
btree::~btree()
{
	del(root);
}
void btree::del(btreenode *sr)
{
	if(sr!=NULL)
	{
		del(sr->leftchild);
		del(sr->rightchild);
	}
	delete sr;
}
main()
{
	cout<<"_______Recursive traversal of BinaryTree______\n";
	btree bt;
	int req,i=1,num;
	cout<<"Enter the number of items to be inserted:";
	cin>>req;
	while(i++<=req)
	{
		cout<<"Enter data:";
		cin>>num;
		bt.buildtree(num);
	}
	bt.traverse();
}
