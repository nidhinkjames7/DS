#include<iostream>
using namespace std;
const int MAX=10;
class array
{
	private:
		int arr[MAX];
		int count;
	public:
		array();
		void add(int item);
		void sort();
		void display();
};
array::array()
{
	count=0;
	for(int i=0;i<MAX;i++)
		arr[i]=0;
}
void array::add(int item)
{
	if(count<MAX)
	{
		arr[count]=item;
		count++;
	}	
	else
		cout<<"\n Array is full"<<endl;
}
void array::sort()
{
	int temp;
	for(int i=0;i<=count-2;i++)
	{
		for(int j=0;j<=count-2;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void array::display()
{
	for(int i=0;i<count;i++)
		cout<<arr[i]<<"\t";	
	cout<<endl;
}
int main()
{
	cout<<"\n -------------------------BUBBLE SORT--------------------------------\n";
	cout<<"\n";
	array a;
	int num ,n;	
	cout<<"\nEnter the limit of an array";
	cin>>n;
	cout<<"\nEnter the elemnts:";
	for(int i=0;i<n;i++)
	{
		cin>>num;
		a.add(num);
	}
	cout<<"\nBubble sort";
	cout<<"\nArray beore sorting:"<<endl;
	a.display();
	a.sort();
	cout<<"\nArray after sorting:"<<endl;
	a.display();
}




