#include<iostream>
using namespace std;
class array
{
	private:
		int *arr;
		int size;
		int count;
	public:
		array();
		array(int sz);
		void add(int num);
		static void sort(int *a,int sz);
		void merge(array &a,array &b);
		void display();
		~array();
};
array::array()
{
	count=size=0;
	arr=NULL;
}
array::array(int sz)
{
	count=0;
	size=sz;
	arr=new int[sz];
}
void array::add(int num)
{
	if(count<size)
	{
		arr[count]=num;
		count++;	
	}
	else	
		cout<<"\n array is full"<<endl;
}
void array::display()
{
	cout<<"\n elements";
	for(int j=0;j<count;j++)
		cout<<"\t"<< arr[j];
	cout<<endl;
}
void array::merge(array &a,array &b)
{
	sort(a.arr,a.size);
	sort(b.arr,b.size);
	size=a.count + b.count+1;
	arr=new int[size];
	int i,j,k;
	for(i=j=k=0;j< a.count||k< b.count;)
	{
		if(a.arr[j]<=b.arr[k])
			arr[i++]=a.arr[j++];
		else
			arr[i++]=b.arr[k++];
		count++;
		if(j==a.count||k==b.count)
			break;
	}
	for(;k<b.count;)
	{
		arr[i++]=b.arr[k++];
		count++;
	}	
}
void array::sort(int *a,int sz)
{
	int temp;
	for(int i=0;i<=sz-1;i++)
	{
		for(int j=i+1;j<=sz-1;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}	
		}
	}
}
array::~array()
{
	delete arr;
}
int main()
{
	cout<<"........................... MERGE SORT-----------------------------------\n";
	cout<<"\n";
	int i,n1,n2,num1,num2;
	cout<<"\n enter the limit for first array:";
	cin>>n1;
	array a(n1);
	for(i=0;i<n1;i++)
	{	
		cout<<"\n enter number:";
		cin>>num1;
		a.add(num1);
	}
	cout<<"\n first array:"<<endl;
	a.display();
	cout<<"\n enter the limit for second array:";
	cin>>n2;
	array b(n2);
	for(i=0;i<n2;i++)
	{
		cout<<"\n enter number:";
		cin>>num2;
		b.add(num2);
	}
	cout<<"\n second array:"<<endl;
	b.display();
	array c;
	c.merge(a,b);
	cout<<"\n array after sorting";
	c.display();
}


