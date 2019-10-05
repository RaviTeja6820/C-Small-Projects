#include<iostream>
#include<conio.h>
using namespace std;
class Ticketbook
{
	private:
		char a[11][15],b[11][15],row[6];
		int nu[11][15],tr[11][15],seatno[6],sortseat,h;
	public:
		void createseats()
		{
			for(int i=0;i<11;i++)
			{
				int t=1;
				for(int j=1;j<=14;j++)
				{
					switch(i+1)
					{
						case 1:
							{
							if(j==1||j==7||j==8||j==14)
							{
								a[i][j]=' ';
								b[i][j]=' ';
								nu[i][j]=0;
								tr[i][j]=0;
							}
							else
							{
								a[i][j]='[';
								b[i][j]=']';
								nu[i][j]=t;
								tr[i][j]=t;
								t++;
							}
							};break;
						case 2:case 3:case 4:case 5:
							{
								if(j==3||j==4||j==11||j==12)
								{
									a[i][j]=' ';
									b[i][j]=' ';
									nu[i][j]=0;
									tr[i][j]=0;
								}
								else
								{
								a[i][j]='[';
								b[i][j]=']';
								nu[i][j]=t;
								tr[i][j]=t;
								t++;
								}
							};break;
						case 6:case 7:case 8:case 9:case 10:
							{
								if(j>=1&&j<=4||j>=11&&j<=14)
								{
									a[i][j]=' ';
									b[i][j]=' ';
									nu[i][j]=0;
									tr[i][j]=0;
								}
								else
								{
								a[i][j]='[';
								b[i][j]=']';
								nu[i][j]=t;
								tr[i][j]=t;
								t++;
								}
							};break;
						case 11:
							{
								if(j>=1&&j<=5||j>=10&&j<=14)
								{
									a[i][j]=' ';
									b[i][j]=' ';
									nu[i][j]=0;
									tr[i][j]=0;
								}
								else
								{
								a[i][j]='[';
								b[i][j]=']';
								nu[i][j]=t;
								tr[i][j]=t;
								t++;
								}
							};break;
					}
				}
			}
			for(int i=0;i<11;i++)
			{
				a[10-i][0]='A'+i;
				b[10-i][0]=' ';
				nu[i][0]=0;
				tr[i][0]=0;
			}
			a[5][1]='E';
			a[6][1]='X';
			a[7][1]='I';
			a[8][1]='T';
			b[5][14]='E';
			b[6][14]='N';
			b[7][14]='T';
			b[8][14]='R';
			b[9][14]='Y';
		}
		void selectticket(int range)
		{
			cout<<"Select Seats(Case Sensitive)"<<endl;
			for(int k=0;k<range&&k<6;k++)
			{
				try{
					cin>>row[k]>>seatno[k];
					if(row[k]>='L')
					throw 1;
					for(int i=0;i<11;i++)
					{
						if(i==(int)row[k]-'A')
						{
							if(i==0)
							{
								if(seatno[k]>=5)
								throw 2;
							}
							else if(i>=1&&i<=5)
							{
								if(seatno[k]>=7)
								throw 3;
							}
							else
							{
								if(seatno[k]>=11)
								throw 4;
							}
						}
					}
					h=10-((int)row[k]-'A');
					for(int j=0;j<=14;j++)
					{
						if(tr[h][j]==seatno[k])
						{
							sortseat=j;
							break;
						}
					}
					if(a[h][sortseat]=='-'&&b[h][sortseat]=='-'&&nu[h][sortseat]==0)
					{
						throw "seat already booked";
					}
				}catch(int x){
					cout<<"No such seats exist,Error No."<<x<<endl;
					k--;
				}
				catch(const char* msg){
					cout<<msg<<endl;
					k--;
				}
				for(int j=0;j<=14;j++)
				{
					if(a[h][j]=='['&&b[h][j]==']'&&nu[h][j]==seatno[k])
					{
						a[h][j]='-';
						b[h][j]='-';
						nu[h][j]=0;
					}
				}
			}
		}
		void amount(int r)
		{
			h=0;
			char c;
			int popcorn=150,coke=100,FF=80,nachos=250,ni,ch,f[5];
			cout<<"Add Foodies?(y/n)"<<endl;
			cin>>c;
			if(c=='y')
			{
				cout<<"Popcorn=0"<<endl;
				cout<<"Coke=1"<<endl;
				cout<<"French Fries=2"<<endl;
				cout<<"Nachos=3"<<endl;
				cout<<"Enter Number of Items you want to choose"<<endl;
				cin>>ni;
				for(int i=0;i<ni;i++)
				{
					cout<<"Enter Choice"<<endl;
					cin>>ch;
					if(ch==0)
					{
						char k;
						cout<<"Popcorn Large(l)="<<popcorn*3<<endl;
						cout<<"Popcorn medium(m)="<<popcorn*1.5<<endl;
						cout<<"Popcorn small(s)="<<popcorn*1<<endl;
						cin>>k;
						if(k=='l')
						f[h]=popcorn*3;
						else if(k=='m')
						f[h]=popcorn*1.5;
						else if(k=='s')
						f[h]=popcorn*1;
						h++;
					}
					else if(ch==1)
					{
						char k;
						cout<<"Coke Large(l)="<<coke*3<<endl;
						cout<<"Coke small(s)="<<coke*1<<endl;
						cin>>k;
						if(k=='l')
						f[h]=coke*3;
						else if(k=='s')
						f[h]=coke*1;
						h++;
					}
					else if(ch==2)
					{
						char k;
						cout<<"French Fries medium(m)="<<FF*1.5<<endl;
						cout<<"French Fries small(s)="<<FF*1<<endl;
						cin>>k;
						if(k=='m')
						f[h]=FF*1.5;
						else if(k=='s')
						f[h]=FF*1;
						h++;
					}
					else if(ch==3)
					{
						char k;
						cout<<"Nachos Large(l)="<<nachos*3<<endl;
						cout<<"Nachos medium(m)="<<nachos*1.5<<endl;
						cout<<"Nachos small(s)="<<nachos*1<<endl;
						cin>>k;
						if(k=='l')
						f[h]=nachos*3;
						else if(k=='m')
						f[h]=nachos*1.5;
						else if(k=='s')
						f[h]=nachos*1;
						h++;
					}
				}
			}
			int s=0;
			for(int i=0;i<h;i++)
			s=s+f[i];
			float rate=100;
			float tax=0.18;
			float bill=(r*rate)+(s)+(r*rate*tax)+(s*tax);
			cout<<"Ticket Rate="<<(r*rate)<<endl;
			cout<<"Food Rate="<<s<<endl;
			cout<<"Tax="<<(r*rate*tax)+(s*tax)<<endl;
			cout<<"Total Bill="<<bill<<endl;
		}
		void print()
		{
			for(int i=0;i<11;i++)
			{
				for(int j=0;j<=14;j++)
				{
					if(nu[i][j]==0)
					cout<<a[i][j]<<b[i][j]<<"\t";
					else
					cout<<a[i][j]<<nu[i][j]<<b[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		void seatprint(int range)
		{
			cout<<"Selected seats are:"<<endl;
			for(int k=0;k<range&&k<=5;k++)
			{
				cout<<row[k]<<"-"<<seatno[k]<<endl;
			}
		}
		int check()
		{
			int flag=0;
			for(int i=0;i<11;i++)
			{
				for(int j=1;j<=14;j++)
				{
					if(a[i][j]=='-')
					flag++;
				}
			}
			if(flag==84)
			return 1;
			else
			return 0;
		}
		void autoselect(int range)
		{
			if(check()==1)
			return;
			int k=0;
			for(int i=0;i<11;i++)
				{
					for(int j=1;j<=14;j++)
					{
						if(a[i][j]=='['&&b[i][j]==']')
						{
							row[k]=a[i][0];
							seatno[k]=nu[i][j];
							a[i][j]='-';
							b[i][j]='-';
							nu[i][j]=0;
							k++;
						}
						if(k==range)
						break;
					}
					if(k==range)
					break;
				}
		}
};
int main()
{
	Ticketbook o;
	int r,choice;
	o.createseats();
	while(1){
		if(o.check()==1){
			cout<<endl<<"\t\t\t\t\t"<<"---------->HOUSEFULL<----------"<<endl;
			break;
		}
	cout<<endl<<"Enter Number of tickets(Max. 6)"<<endl;
	try{
		cin>>r;
		if(r>6){
			throw 5;
		}
	}catch(int x){
		cout<<"Wrong range:Error"<<x<<endl;
		cout<<"Maximum seats 6 are selected by default"<<endl;
	}
	cout<<"'--'=>Seat filled "<<endl;
	o.print();
	cout<<endl<<"Want to select your seat or auto select?"<<"\n"<<"Select choice:\nAuto Select-0\nUser Select-1"<<endl;
	cout<<endl<<"Your choice:";cin>>choice;
	if(choice==0)
	o.autoselect(r);
	else
	o.selectticket(r);
	o.print();
	o.seatprint(r);
	o.amount(r);
	}
	getch();
	return 0;
}
