#include<iostream>
#include<conio.h>
using namespace std;
class staff
{
 	  int code[5];
	   public:
	   	char name[100];
	   		void getcode()
	   		{
  		 	  code[0]=6001;
			  code[1]=6002;
			  code[2]=6003;
 		    }
 		    void printcode()
 		    {
 		  	  cout<<"Teacher:"<<code[0]<<endl;
			  cout<<"Typist:"<<code[1]<<endl;	
			  cout<<"Officer:"<<code[2]<<endl;   	
		   }
};
class teacher:public staff
{
	public:
	char subject[50],publication[50];
		//char tname[50];
		int id;
		void getsp(int i)
		{
			cout<<"Enter Name:";
			cin>>name;
			cout<<"tid registered"<<endl;
			id=i;
			cout<<"Enter Subject:";
			cin>>subject;
			cout<<"Enter Publication:";
			cin>>publication;
			cout<<endl;
		}
		void print()
		{
			cout<<"Teacher Name:"<<name<<endl;
			cout<<"Subject:"<<subject<<endl;
			cout<<"Publication"<<publication<<endl;			
		}
};
class typist:public staff
{
	public:
		float speed;
		//char tyname[10];
		int id;
		void gettyd(int i)
		{
			cout<<"Enter Typist Name:";
			cin>>name;
			cout<<"id registered"<<endl;
			id=i;
			cout<<"Enter speed:";
			cin>>speed;
			cout<<endl;
		}
		void print()
		{
			cout<<"Typist Name:"<<name<<endl;
			cout<<"Speed:"<<speed<<"lps"<<endl;
		}
};
class officer:public staff
{
	public:
		int grade,id;
		//char oname[50];
		void getod(int i)
		{
			cout<<"Enter Officer Details:";
			cin>>name;
			cout<<"id registered:\n";
			id=i;
			cout<<"Enter Grade:";
			cin>>grade;
			cout<<endl;
		}
		void print()
		{
			cout<<"Officer name:"<<name<<endl;
			cout<<"Grade:"<<grade<<endl;
		}
};
class regular:public typist
{
	public:
		void getrtd(int i)
		{
			gettyd(i);
		}
		void print()
		{
			cout<<"Typist name:"<<name<<endl;
			cout<<"Speed:"<<speed<<endl;
		}
};
class casual:public typist
{
	public:
		int wages;
		void getrtd(int i)
		{
			gettyd(i);
			cout<<"Enter Wage:";
			cin>>wages;
			cout<<endl;
		}
		void print()
		{
			cout<<"Typist name:"<<name<<endl;
			cout<<"Speed:"<<speed<<endl;
			cout<<"Wages:"<<wages<<endl;
		}
};
int main()
{
	int k;
	staff obj;
	teacher obj1[10];
	typist obj2[10];
	officer obj3[10];
	regular obj4[10];
	casual obj5[10];
	int r1,r2,r3;
	cout<<"Enter Teacher range:";cin>>r1;
	for(int i=0;i<r1;i++)
	{
		obj1[i].getsp(i);
	}
	cout<<"Enter Typist range:";cin>>r2;
	for(int i=0;i<r2;i++)
	{
		if(i<=6)
		{
		obj4[i].gettyd(i);
		}
		else
		{
		obj5[i].gettyd(i);
		}
	}
	cout<<"Enter Officer range:";cin>>r3;
	for(int i=0;i<r3;i++)
	{
		obj3[i].getod(i);
	}
	obj.getcode();
	obj.printcode();
	int n;
	cout<<"Enter code:";cin>>n;
	switch(n)
	{
		case 6001:
			for(int i=0;i<r1;i++)
			cout<<obj1[i].name<<"="<<obj1[i].id<<endl;
			cout<<"Enter id";cin>>k;
			cout<<endl;
			obj1[k].print();
			cout<<"\n";
		case 6002:
			for(int i=0;i<r2;i++)
			if(i<=6)
			cout<<obj4[i].name<<"="<<obj4[i].id<<endl;
			else
			cout<<obj5[i].name<<"="<<obj5[i].id<<endl;
			cout<<"Enter id";cin>>k;
			if(k<=6)
			obj4[k].print();
			else
			obj5[k].print();
			cout<<"\n";
		case 6003:
			for(int i=0;i<r3;i++)
			cout<<obj3[i].name<<"="<<obj3[i].id<<endl;
			cout<<"Enter id";cin>>k;
			obj3[k].print();
			cout<<"\n";
	}

getch();
return 0;
}
