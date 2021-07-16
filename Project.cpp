#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<string.h>
#include<conio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
//headerfile for time

class customer
{
	public:
	char id[20];
	char name[20];
	char phone_no[20];
	vector<string> customer_order;
	char status[20];
	int k;
	void get_info()
	{
		gtinfo:
		cout<<"Enter your first name: ";
		cin>>name;
		cout<<"Enter your mobile number: ";
		cin>>phone_no;
		cout<<"Is this information correct?(Y/N)\n";
		cout<<"Name: "<<name<<", Phone number: "<<phone_no<<endl;
		char ch;
		cin>>ch;
		if(ch=='y'||ch=='Y')
			assign_id();
		if(ch=='n'||ch=='N')
			goto gtinfo;
	}
	void get_order()
	{
		cout<<"Enter the number of items that you want to order: ";
		int n;
		cin>>n;
        char od[20];
        cout<<"Enter the items that you wish to order: ";
        for(int i=0;i<n;i++)
        {
        	cin>>od;
        	customer_order.push_back(od);
		}
	}
	void assign_id()
	{
		strcpy(id,name);
		strcat(id,"@");
		strcat(id,phone_no);
		cout<<"Your id is: "<<id<<endl;
	}
	void display()
	{
		int i;
		for(i=0;i!=customer_order.size();i++)
		cout<<customer_order[i]<<endl;
	}
	void clear_all()
	{
		customer_order.clear();
	}
	
	void complete(int a)
	{
		if(a==1)
		strcpy(status,"Completed.");
		else
		strcpy(status,"Not completed!");
	}
};

vector<customer> cus;

main()
{
	customer a;
	int k=0;
	int p=0;
	start:
	//system("CLS");	
	cout<<"Welcome to CC retail services, please enter '1'' if you are a customer, and '2' if you are a retailer: ";
	int option;
	cin>>option;
	if(option==1) 
	{
		again:
		int opt;
		cout<<"Do you want to make a new order(1) or see a previous one(2)?";
		cin>>opt;
		if(opt==1)
		{
			a.get_info();
		    a.get_order();
		    cus.push_back(a);
		    a.clear_all();
		    
		}
		if(opt==2)
		{
			char ID[20];
			cout<<"ENTER YOUR CUSTOMER_ID:"<<endl;
		    cin>>ID;
		    vector<customer>::iterator it;
		    for(it=cus.begin();it!=cus.end();it++)
		    {
			if(strcmp(ID,it->id)==0)
			{
			   cout<<"Found"<<endl;
			   cout<<"Yours details are:"<<endl;
			   cout<<"NAME:"<<it->name<<endl<<"PHONE NUMBER:"<<it->phone_no<<endl<<"CUSTOMER ID:"<<it->id<<endl<<"ITEMS ORDERED:"<<endl;
			   it->display();
			   if(it->k!=1)
			   {
			   cout<<"Status:Not completed"<<endl;
			   cout<<"If you wish to continue, press 1, else press 2 to cancel your order!"<<endl;
			   int opti;
			   k=1;
			   cin>>opti;
			   if(opti==2)
			   {
			   cus.erase(it);
			   cout<<"Your order has been cancelled.";
			   }
			   else
			   	   goto start;
		       }
		       else
		       {
		       	cout<<"Status:Completed"<<endl;
		       	cus.erase(it);
		       	k=1;
			   }
			   
			   	   
			   	
			}
		}
		if(k==0)
	
	        
	        {
			cout<<"Not found"<<endl;
	        goto again;
			}	        
			}
	goto start;		
   }
	if(option==2)
	{
		int i=1;
        vector<customer>::iterator it;
		for(it=cus.begin();it!=cus.end();it++)
		{
		cout<<"Customer "<<i++<<endl<<"The details are as follows:"<<endl;
		cout<<"NAME:"<<it->name<<endl<<"PHONE NUMBER:"<<it->phone_no<<endl<<"CUSTOMER ID:"<<it->id<<endl;
		it->display();
		it->complete(0);
		cout<<"Status:"<<it->status;
		cout<<endl;
		cout<<"Is this order completed?(1 for yes, 0 for no)";
		cin>>option;
		if(option==1)
		{
			it->k=1;
			cout<<"order completed"<<endl;
		}
		else
		{
		
		continue;
	}
		}
		goto start;
	}
	
	if(option==3)
		return 0;
    
	if(option>3)
	{
	cout<<"Invalid option,choose again!!!\n";
		goto start;}
	
	
}
