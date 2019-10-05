#include<iostream>
#include<conio.h>
using namespace std;
class Ticketbook
{
	public:
		int a[10][10],n,t[10];
		float rate,tax,bill;
		void getvalues()
		{
			for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
			{
				a[i][j]=1+i*10+j;
			}
		}
		void selectticket(int r)
		{
			cout<<"Enter Ticket Numbers"<<endl;
			for(int i=0;i<r;i++)
			cin>>t[i];
			for(int k=0;k<r;k++)
			{
				for(int i=0;i<10;i++)
				for(int j=0;j<10;j++)
				{
				 if(t[k]==a[i][j])
				 {
					a[i][j]=0;
				 }
			}
			}
		}
		void amount(int r)
		{
			rate=100;
			tax=0.18;
			bill=(r*rate)+(r*tax*rate);
			cout<<"Rate="<<(r*rate)<<endl;
			cout<<"Tax="<<r*rate*tax<<endl;
			cout<<"Total Bill="<<bill<<endl;
		}
		void print()
		{
			for(int i=0;i<10;i++)
			{
			for(int j=0;j<10;j++)
			{
				cout<<a[i][j]<<"\t";
			}
			cout<<endl;
			}
		}
};
int main()
{
	Ticketbook o;
	int r;
	cout<<"Enter Number of tickets(Max. 10)"<<endl;
	cin>>r;
    o.getvalues();
    o.print();
	    o.selectticket(r);
        o.print();
        o.amount(r);
	getch();
	return 0;
}
