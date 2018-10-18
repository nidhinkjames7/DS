#include<iostream>
using namespace std;
class linkstack
{
	private:
		struct node
		{
			int data;
			node *link;
		}*top;
	public:	
		linkstack();
		void push(int);
		int pop();
		~linkstack();
		void display();
};
linkstack::linkstack()
{
	top=NULL;
}
void linkstack::push(int item)
{
	node *temp;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"stack is full\n";
	}
	temp->data=item;
	temp->link=top;
	top=temp;
	cout<<endl<<" "<<temp->data<<"is inserted\n";
}
int linkstack :: pop()
{
	if(top==NULL)
	{
		cout<<"stack empty\n";
		return NULL;
	}
	node *temp;
	int item;
	temp=top;
	item=temp->data;
	top=top->link;
	delete temp;
	return item;
}
void linkstack:: display()
{
	node *r;
	if(top==NULL)
	{
		cout<<"stack is empty\n";
	}
	else
	{
		for(r=top;r->link!=NULL;r=r->link)
		{
			cout<<r->data<<"\n";
		}
		cout<<r->data<<"\n";
	
	}
}
linkstack::~linkstack()
{
	if(top==NULL)
	return;
	node *temp;
	while(top!=NULL)
	{
		temp=top;
		top=top->link;
		delete temp;
	}
}
main()
{
	linkstack s;
	int ch,nu;
	int c,i;
	do
	{
		cout<<"stack as an linked list\n1.add elements\n2.delete elements\n3.display\n4.exit\n";
		cout<<"enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter elements:\n";
				cin>>nu;
				s.push(nu);
				break;
			case 2:
				i=s.pop();
				cout<<"item is deleted:\n"<<i;
				break;
			case 3:
				cout<<"the elements are:\n";
				s.display();
				break;
			defult:
				cout<<"invalid choice\n";
				break;
		}
		cout<<"do you want to continue(1/0)???\n";
		cin>>c;
	}while(c==1);
}
	
