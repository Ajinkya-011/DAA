#include<iostream>
using namespace std;

class bag
{
	public:
	double p;
	double w,r;
	double fraction;
	void sort(bag a[],int n);
	void logic(bag a[],int n,int capacity);
	
};
void bag::sort(bag a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j].r<a[j+1].r)
			{
				bag temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void bag::logic(bag a[],int n,int capacity)
{
	double TW=0;
	double TP=0;
	int i=0;
	while(1)
	{
		if(TW<capacity) //still reamaining the capacity.
		{
			if(a[i].w<=(capacity-TW)) //if capacity of bag is not full,and whole element is present
			{
				TW+=a[i].w;
				TP+=a[i].p;
				a[i].fraction=1;
			}
			else  //if capacity of bag is not full,and whole element is not present then calculate fraction
			{
				a[i].fraction=((capacity-TW)/a[i].w);
				TW+=a[i].w*a[i].fraction;
				TP+=a[i].p*a[i].fraction;
			}
			
		}
		else
		{
			break;
		}
		i++;
	}
	cout<<"Total profit is:"<<TP<<endl;
	
}
int main()
{
	
	int capacity;
	int n;
	cout<<"Enter the capacity of the object:\n";
	cin>>capacity;
	cout<<"Enter the objects:";
	cin>>n;
	
	bag obj[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the profit of the object:";
		cin>>obj[i].p;
		cout<<"Enter the weight of the object:";
		cin>>obj[i].w;
		obj[i].fraction=0;
	}
	//calculate ratio
	for(int i=0;i<n;i++)
	{
		obj[i].r=obj[i].p/obj[i].w;
	}
	//printing
	cout<<"\nProfit\tWeight\tRatio\tFraction\n";
	for(int i=0;i<n;i++)
	{
		cout<<obj[i].p<<"\t"<<obj[i].w<<"\t"<<obj[i].r<<"\t"<<obj[i].fraction<<"\n";
	}
	bag b;
	b.sort(obj,n);
	cout<<"After sorting:\n";
	cout<<"\nProfit\tWeight\tRatio\tFraction\n";
	for(int i=0;i<n;i++)
	{
		cout<<obj[i].p<<"\t"<<obj[i].w<<"\t"<<obj[i].r<<"\t"<<obj[i].fraction<<"\n";
	}
	cout<<"\n";
	b.logic(obj,n,capacity);
	cout<<"After updating the fraction:\n";
	cout<<"\nProfit\tWeight\tRatio\tFraction\n";
	for(int i=0;i<n;i++)
	{
		cout<<obj[i].p<<"\t"<<obj[i].w<<"\t"<<obj[i].r<<"\t"<<obj[i].fraction<<"\n";
	}
	return 0;
	
}

