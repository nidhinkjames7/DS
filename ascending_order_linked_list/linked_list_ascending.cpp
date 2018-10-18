#include<iostream>
using namespace std;
class asclinkedlist
{
	private:	
		struct node
		{
			int data;
			node *link;
		}*p;
	public:
		asclinkedlist();
		int add(int num);
		void display();	
		int count();
		void del(int num);
		~asclinkedlist();
};
asclinkedlist :: asclinkedlist()
{
	p=NULL;
};
int asclinkedlist :: add(int num)
{
	node *r,*temp=p;
	r=new node;
	r->data=num;
	if(p==NULL||p->data>=num)
	{
		r->link=p;
		p=r;
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->link==NULL)
			{
				r->link=temp->link;
				temp->link=r;
				return 0;
			}
			else if(temp->data<=num && (temp->link)->data>num)
			// || temp->link==NULL))
			{	
				r->link=temp->link;
				temp->link=r;
				return 0;
			}
			else if(temp->link==NULL)
			{
				r->link=temp->link;
				temp->link=r;
				return 0;
			}
			temp=temp->link;
		}
	}
}
void asclinkedlist :: display()
{
	node *temp=p;
	cout<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}
int asclinkedlist :: count()
{
	int c=0;
	node *temp=p;
	while(temp!=NULL)
	{
		temp=temp->link;
		c++;
	}
	return c;
}
asclinkedlist :: ~asclinkedlist()
{
	node *q;
	while(p!=NULL)
	{
		q=p->link;
		delete p;
		p=q;
	}
}
int main()
{
	asclinkedlist l;
	int s,n,i;
	cout<<"enter the size of the array\n";
	cin>>s;
	cout<<"enter the elements of the array\n";
	for(i=0;i<s;i++)
	{
		cin>>n;
		l.add(n);
	}
	cout<<"elements in the linked list\n";
	l.display();
	cout<<"number of elements in the linked list:\n"<<l.count();
}
 

