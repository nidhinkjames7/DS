#include<iostream>
using namespace std;
const int MAX=10;
class queue
{
	private:
		int arr[MAX];
		int front,rear;
	public:
		queue();
		void addq(int item);
		int delq();
		void display();
};
queue::queue()
{
	front=-1;
	rear=-1;
}
void queue::addq(int item)
{
	if(rear==MAX-1)
	{
		cout<<"queue is full\n";
		return;
	}
	rear++;
	arr[rear]=item;
	if(front==-1)
		front=0;
	cout<<"item pushed\n"<<item;
}
int queue::delq()
{
	int data;
	if(front==-1)
	{
		cout<<"queue is empty\n";
		return NULL;
	}
	data=arr[front];
	arr[front]=0;
	if(front==rear)
		front=rear=-1;
	else
		front++;
	return data;
}
void queue::display()
{
	int i;
	if(front==-1)
	{
		cout<<"queue is empty\n";
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			cout<<arr[i]<<"\n";
		}
		//cout<<arr[i]<<"\n";
	}		
}		
int main()
{
	queue a;
	int ch,nu;
	int c,i;
	do
	{
		cout<<"-----QUEUE AS AN ARRAY----\n1.add elements\n2.delete elements\n3.display\n4.exit\n";
		cout<<"enter your choice\n";
		cin>>ch;
		switch(ch)		
		{
			case 1: cout<<"enter the elements\n";
				cin>>nu;
				a.addq(nu);
				break;
			case 2:	i=a.delq();
				cout<<"iterm is popped:\n"<<i;
				break;
			case 3:	a.display();
				break;
			deafult:cout<<"invalid choice\n";
				break;
		}
		cout<<"\ndo you want to continue(y/n)???\n";
		cin>>c;
	}while(c==1);
}
