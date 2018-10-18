#include<iostream>
using namespace std;
class binary
{
	int arr[10],n;
	public :
		void read();
		void bsearch();
		void sort();
};
void binary::read()
{
	int i;
	cout<<"Enter size of the array";
	cin>>n;
	cout<<"Enter elements";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void binary::sort()
{
	int temp;
	for(int i=0;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	cout<<"----------------Sorted array is.............";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<arr[i];
	}
}
void binary:: bsearch()
{
	int s,beg=0,mid,end=n-1,k=0;
	cout<<"\nEnter element to search";
	cin>>s;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(s==arr[mid])
		{
			k=1;	
			break;
		}
		if(arr[mid]<s)
		{
			beg=mid+1;
		}
		else if(arr[mid]>s)
		{
			end=mid-1;
		}
	}
	if(k==1)
		cout<<"Element\t"<<s<<"\tis found in position\t"<<mid+1;
	else
		cout<<"Element not found"  ;
}
int main()
{
	cout<<"\n ----------------------BINARY SEARCH-----------------------------------";
	cout<<"\n";
	binary b;
	b.read();
	b.sort();
	b.bsearch();
}


