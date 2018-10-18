#include<iostream>
using namespace std;
class revlinkedlist
{
	private:
		struct node
		{
			int data;
			node *link;
		}*p;
	public:
		revlinkedlist();
		void addbeg(int num);
		void reverse();
		void display();
		int count();
		~revlinkedlist();
};
revlinkedlist :: revlinkedlist()
{
	p=NULL;
}
void revlinkedlist :: addbeg(int num)
{
	node *temp;
	temp=new node;
	temp->data=num;
	temp->link=p;
	p=temp;
}
void revlinkedlist :: reverse()
{
	node *q,*r,*s;
	q=p;
	r=NULL;
	while(q!=NULL)
	{
		s=r;
		r=q;
		q=q->link;
		r->link=s;
	}
	p=r;
}
void revlinkedlist :: display()
{
	node *temp=p;
	cout<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}
int revlinkedlist :: count()
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
revlinkedlist :: ~revlinkedlist()
{
	node *q,*p;
	while(p!=NULL)
	{
		q=p->link;
		delete p;
		p=q;
	}
}
int main()
{
	revlinkedlist l;
	int n,a;
	cout<<"\n------REVERSE OF SINGLY LINKED LIST------\n";
	cout<<"enter how many elements to be added first \n";
	cin>>n;
	cout<<"enter the elements\n";
	for(int i=0;i<n;i++)
	{
		cin>>a;
		l.addbeg(a);
	}
	cout<<"number of elements are:\n"<<l.count();
	l.display();
	cout<<"number of elements in the linked list:\n"<<l.count();
	l.reverse();
	cout<<"elements in the linked list after reversing :\n";
	l.display();
}	
