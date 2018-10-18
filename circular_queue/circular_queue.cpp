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
	front=rear=-1;
	for(int i=0;i<MAX;i++)
		arr[i]=0;
}
void queue::addq(int item)
{
	if((rear==MAX-1&&front==0)||(rear+1==front))
	{
		cout<<"queue is full\n";
		return;
	}
	if(rear==MAX-1)
		rear=0;
	else
		rear++;
	arr[rear]=item;
	if(front==-1)
		front=0;
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
	{
		front=-1;	
		rear=-1;
	}
	else
	{
		if(front==MAX-1)
			front=0;
		else
			front++;
	}
	return data;
}
void queue::display()
{
	cout<<endl;
	for(int i=0;i<MAX;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	cout<<"-----CIRCULAR QUEUE OPEARTIONS----\n";
	cout<<"\n";
	queue a;
	int num,n,dnum,ch,j;
	while(1)
	{
		cout<<"1.adding element\n2.deleting elements\n3.exit\n";
		cout<<"enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter the number of elements\n";
				cin>>num;
				cout<<"enlements are\n";	
				for(int i=1;i<=num;i++)
				{
					cin>>n;
					a.addq(n);
				}
				cout<<"elements in the circular queue\n";
				a.display();
				break;
			case 2:
				cout<<"how many elements to be deleted\n";
				cin>>dnum;
				for(int i=1;i<=dnum;i++)
				{
					a.delq();
				}
				cout<<"item deleted\n";		
				cout<<"elements in the circular queue after deletion\n";
				a.display();
				break;
			default:	
				cout<<"invalid choice\n";
				break;
		}
	}
}					
