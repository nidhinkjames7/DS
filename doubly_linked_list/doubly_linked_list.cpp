#include<iostream>
using namespace std;
class dll
{
	private:
		struct node
		{
			node *prev;
			int data;
			node *next;
		}*p;
	public:
		dll();
		void append(int);
		void addbeg(int);
		void addafter(int,int);
		void display();
		int count();
		void del(int);
};
dll :: dll()
{
	p=NULL;
}
void dll :: append(int num)
{
	node *r,*q;
	q=p;
	if(q==NULL)
	{
		q=new node;
		q->prev=NULL;
		q->data=num;
		q->next=NULL;
		p=q;
	}
	else
	{
		while(q->next!=NULL)
			q=q->next;
		r=new node;
		r->data=num;
		r->next=NULL;
		r->prev=q;
		q->next=r;
	}
}
void dll :: addbeg(int num)
{
	node *q;
	q=new node;
	q->data=num;
	q->prev=NULL;
	if(p==NULL)
	{
	q->next=NULL;
	}
	else
	{
	q->next=p;
	p->prev=q;
	}
	p=q;
}
void dll :: addafter(int loc,int num)
{
	node *q;
	q=p;
	for(int i=0;i<loc;i++)
	{
		q=q->next;
		if(q==NULL)
		{
			cout<<"\n there are less than:"<<loc<<"elements";
			return;
		}
	}
	q=q->prev;
	node *temp=new node;
	temp->data=num;
	temp->prev=q;
	temp->next=q->next;
	(temp->next)->prev=temp;
	q->next=temp;
}
void dll :: display()
{
	node *temp=p;
	cout<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int dll :: count()
{
	int c=0;
	node *temp=p;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	return c;
}
void dll :: del(int num)
{
	node *q=p;
	while(q!=NULL)
	{
		if(q->data==num)
		{
			if(q==p)
			{
				p=p->next;
				p->prev=NULL;
			}
			else
			{
				if(q->next==NULL)
				{
					q->prev->next=NULL;
				}
				else
				{
						q->prev->next=q->next;
						q->next->prev=q->prev;
				}		
				delete q;
			}
			cout<<"element deleted\n";
			return;
		}
		q=q->next;
	}
	cout<<endl;
	cout<<num<<"not found\n";
}
int main()
{
	dll l;
	int ch,a,n,loc,d;
	cout<<"------DOUBLY LINKED LIST-----\n";
	while(1)
	{
		cout<<"\n1.add at begining\n2.append\n3.addafter\n4.delete\n5.exit\n";
		cout<<"enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter how many elements to be added first\n";
				cin>>n;
				cout<<"enter the elements \n";
				for(int i=0;i<n;i++)
				{
					cin>>a;
					l.addbeg(a);
				}
				cout<<"no of elements are:\n"<<l.count()<<"\n";
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
				cout<<"no of elements are:\n"<<l.count()<<"\n";
				l.display();
				break;
			case 3:
				cout<<"number of elements to be inserted \n";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"enter the positon\n";
					cin>>loc;
					cout<<"enter the elements\n";
					cin>>a;
				l.addafter(loc,a);
				}
//				l.addafter(loc,a);

				cout<<"number of elements are:\n"<<l.count()<<"\n";
				l.display();
				break;
			case 4:
				cout<<"enter the elements to be deleted\n";
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
	return 0;
}		
	
		
