#include<iostream>
using namespace std;
class sll
{
	private:
		struct node
		{
			int data;
			node *link;
		}*p;
	public:
		sll();
		void append(int);
		void addbeg(int);
		void addafter(int,int);
		void display();
		int count();
		void del(int);
		~sll();
};
sll :: sll()
{
	p=NULL;
}
void sll :: append(int num)
{
	node *temp,*r;
	if(p==NULL)
	{
		temp=new node;
		temp->data=num;
		temp->link=NULL;
		p=temp;
	}
	else
	{
		temp=p;
		while(temp->link!=NULL)
		temp=temp->link;
		r=new node;
		r->data=num;
		r->link=NULL;
		temp->link=r;
	}
}
void sll :: addbeg(int num)
{
	node *temp;
	temp=new node;
	temp->data=num;
	temp->link=p;
	p=temp;
}
void sll :: addafter(int loc,int num)
{
	int i;
	node *temp,*r;
	temp=p;
	for(i=1;i<loc;i++)
	{
		temp=temp->link;
		if(temp==NULL)
		{
			cout<<"less than"<<loc<<"elements"<<endl;
			return;
		}
	}
	r=new node;
	r->data=num;
	r->link=temp->link;
	temp->link=r;
}
void sll :: del(int num)
{
	node *old,*temp;
	temp=p;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			if(temp==p)
				p=temp->link;
			else
				old->link=temp->link;
			delete temp;
			return;
		}
		else
		{
			old=temp;
			temp=temp->link;
		}
	}
	cout<<"Not found\n";
}
int sll :: count()
{
	node *temp=p;
	int c=0;
	while(temp!=NULL)
	{
		temp=temp->link;
		c++;
	}
	return c;
}
void sll :: display()
{
	node *temp=p;
	while(temp!=NULL)
	{
		cout<<temp->data<<" "<<"\n";
		temp=temp->link;
	}
}
sll :: ~sll()
{
	node *q;
	while(q!=NULL)
	{
		q=p->link;
		delete p;
		p=q;
	}
}
main()
{
	sll l;
	int a,n,ch,loc,m,b,d;
	cout<<"\n-----SINGLY LINKED LIST----\n";
	while(1)
	{
		cout<<"1. add at begining\n 2.append\n 3.add after\n 4.delete\n 5.exit\n";
		cout<<"enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter how many elements to be addeded first\n";
				cin>>n;
				cout<<"enter the elements\n";
				for(int i=0;i<n;i++)
				{
					cin>>a;
					l.addbeg(a);
				}
				cout<<"number of elements are\n"<<l.count();
				cout<<"\n";
				l.display();
				break;
			case 2:
				cout<<"enter how many elements to be added last\n";
				cin>>n;
				cout<<"enter the elements\n";
				for(int i=0;i<n;i++)
				{
					cin>>a;
					l.append(a);
				}
				cout<<"number of elements are\n"<<l.count()<<"\n";
				l.display();
				break;
			case 3:
				cout<<"number of elements to be inserted\n";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"enter the position\n";
					cin>>loc;
					cout<<"enter the elements\n";
					cin>>a;
					l.addafter(loc,a);
				}
				cout<<"number of the elements are:\n"<<l.count();
				cout<<"\n";
				l.display();
				break;
			case 4:	
				cout<<"enter the element to be deleted\n";
				cin>>d;
				l.del(d);	
				cout<<"\n";
				l.display();	
				break;
			case 5:
				return 0;
				break;
			default:
				cout<<"invalid entry\n";
				break;
		}
	}
}
	
