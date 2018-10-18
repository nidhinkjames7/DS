#include<iostream>
using namespace std;
const int MAX=10;
class Quick
{
	private:
		int arr[MAX];
		int count;
	public:
		Quick();
		void add(int item);
		int getcount();
		static int split(int *,int,int);
		void quicksort(int lower,int upper);
		void display();
};
Quick::Quick()
{
	count=0;
	for(int i=0;i<MAX;i++)
		arr[i]=0;
}
void Quick::add(int item)
{
	if(count<MAX)
	{
		arr[count]=item;
		count++;
	}
	else
		cout<<"\nQuick is full\n";
}
int Quick::getcount()
{
	return count;
}
void Quick::quicksort(int lower,int upper)
{
	if(upper>lower)
	{
		int i=split(arr,lower,upper);
		quicksort(lower,i-1);
		quicksort(i+1,upper);
	}
}
int Quick::split(int *a,int lower,int upper)
{
	int i,p,q,t;
	p=lower+1;
	q=upper;
	i=a[lower];
	while(q>=p)
	{
		while(a[p]<i)
			p++;
		while(a[q]>i)
			q--;
		if(q>p)
		{
			t=a[p];
			a[p]=a[q];
			a[q]=t;
		}
	}
	t=a[lower];
	a[lower]=a[q];
	a[q]=t;
	return q;
}
void Quick::display()
{
	for(int i=0;i<count;i++)
	{
		cout<<arr[i];
		cout<<"\n";
	}
}
int main()
{
	Quick a;
	int s,n;
	cout<<"\nEnter the size of an Quick:";
	cin>>s;
	cout<<"\nelements are:";
	for(int i=1;i<=s;i++)
	{
		cin>>n;
		a.add(n);
	}
	cout<<"\nQuick sort\n";
	cout<<"\nQuick before sort:\n";
	a.display();
	int c=a.getcount();
	a.quicksort(0,c-1);
	cout<<"\nQuick after quick sorting:\n";
	a.display();
}


