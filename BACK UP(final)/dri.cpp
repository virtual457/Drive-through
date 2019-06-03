#include<iostream>    //Main header used
#include<ctime>       //Header Used to display time in the Users bill
#include<iomanip>     //Header used to set the coloms
#include<fstream>     //Header for using files
#include<cstring>     //Heder for manuplating string
#include <unistd.h>   //Header for Sleep fn()
#ifdef __cplusplus__  //Header for clear screen fn()
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif
using namespace std;
unsigned int microseconds=5000000; //Pre defined value set for sleep
//Clear screen fn()
void clear_screen()
{
		if (system("CLS")) 
		system("clear");
}
//Creating a class for the MENU
class MENU
{
	protected:
		char Pizza[100][50],Burger[100][50],Dounut[100][50],Beverages[100][50];	//Name of Items
		int Pizza_Price[100],Burger_Price[100],Dounut_Price[100],Beverages_Price[100];	//Price of Items
		int Pizza_list,Burger_list,Dounut_list,Beverages_list;	//File content Tracker
		//Using Constructor to load contents to the Array
	public:	MENU()
		{
			regg_name();
		}
		void regg_name();	//Fn() to open file and save its contents to array
		void display(int a);	//Display Array
		int print_name();	//Save a Unique No (Persons order)
};
//Fn() to open file and save its contents to array
void MENU::regg_name()
{
	int p,j,b,be,d,p_p,b_b,be_be,d_d;
	p=0;
	b=0;
	be=0;
	d=0;
	//Opening File to creat the menu
	ifstream PIZ("PIZZA");
	ifstream BUR("BURGER");
	ifstream DOU("DOUGHNUT");
	ifstream BEV("BEVERAGES");
	ifstream PIZ_PRICE("PIZZA_PRICE");
	ifstream BUR_PRICE("BURGER_PRICE");
	ifstream DOU_PRICE("DOUNUT_PRICE");
	ifstream BEV_PRICE("BEVERAGES_PRICE");
	//Checking if FILE is Present	
	if(!PIZ || !BUR || !DOU || !BEV ||!PIZ_PRICE || !BUR_PRICE || !DOU_PRICE || !BEV_PRICE)
	{
		cout<<"Please contact the service team\n";
		return;
	}
	//Saving contents of the File to array
	while(!PIZ.eof())
	{
		PIZ>>Pizza[p];
		PIZ_PRICE>>Pizza_Price[p];
		p++;
	}
	while(!BUR.eof())
	{
		BUR>>Burger[b];
		BUR_PRICE>>Burger_Price[b];
		b++;
	}
	while(!DOU.eof())
	{
		DOU>>Dounut[d];
		DOU_PRICE>>Dounut_Price[d];
		d++;
	}
	while(!BEV.eof())
	{
		BEV>>Beverages[be];
		BEV_PRICE>>Beverages_Price[be];
		be++;
	}
	//Counting the No of Items Present
	Pizza_list=p-1;
	Burger_list=b-1;
	Beverages_list=be-1;
	Dounut_list=d-1;
	//Closing the File
	PIZ.close();
	BUR.close();
	DOU.close();
	BEV.close();
	PIZ_PRICE.close();
	BUR_PRICE.close();
	DOU_PRICE.close();
	BEV_PRICE.close();
}
//Displaying the contents of the file To the coustomer
int MENU::print_name()
{
	int j,a,OPTION_ONE,OPTION_TWO,result;
	OPTION_ONE=0;
	OPTION_TWO=0;
	result=0;
	clear_screen();
	cout<<"----------------------------------------------------------\n";
	cout<<"                          MENU                            \n";
	cout<<"----------------------------------------------------------\n";
	cout<<"1.Pizza\n2.Burger\n3.Doughnut\n4.Beverages\n5.Delete Content For Present MENU\n6.PRINT BILL\n7.View contents\n8.Delete order\n";
	cin>>OPTION_ONE;
	//Printing the sub-contents
	if(OPTION_ONE==1)
	{
		clear_screen();
		cout<<setw(53)<<left<<"ITEMS"<<"PRICE\n";
		for(j=0;j<Pizza_list;j++)
		{
			cout<<setw(2)<<left<<j+1<<setw(1)<<left<<"."<<setw(53)<<left<<Pizza[j]<<Pizza_Price[j]<<endl;
		}
		cin>>OPTION_TWO;
		if(OPTION_TWO>Pizza_list || OPTION_TWO<=0)
		{
			cout<<"Invalid option \n";
			return(-2);
		}
	}
	else if(OPTION_ONE==2)
	{
		clear_screen();
		cout<<setw(53)<<left<<"ITEMS"<<"PRICE\n";
		for(j=0;j<Burger_list;j++)
		{
			cout<<setw(2)<<left<<j+1<<setw(1)<<left<<"."<<setw(53)<<left<<Burger[j]<<Burger_Price[j]<<endl;
		}
		cin>>OPTION_TWO;
		if(OPTION_TWO>Burger_list || OPTION_TWO<=0)
		{
			cout<<"Invalid option \n";
			return(-2);
		}
	}
	else if(OPTION_ONE==3)
	{
		clear_screen();
		cout<<setw(53)<<left<<"ITEMS"<<"PRICE\n";
		for(j=0;j<Dounut_list;j++)
		{
			
			cout<<setw(2)<<left<<j+1<<setw(1)<<left<<"."<<setw(53)<<left<<Dounut[j]<<Dounut_Price[j]<<endl;
		}
		cin>>OPTION_TWO;
		if(OPTION_TWO>Dounut_list || OPTION_TWO<=0)
		{
			cout<<"Invalid option \n";
			return(-2);
		}
	}
	else if(OPTION_ONE==4)
	{
		clear_screen();
		cout<<setw(53)<<left<<"ITEMS"<<"PRICE\n";
		for(j=0;j<Beverages_list;j++)
		{
			cout<<setw(2)<<left<<j+1<<setw(1)<<left<<"."<<setw(53)<<left<<Beverages[j]<<Beverages_Price[j]<<endl;
		}
		cin>>OPTION_TWO;
		if(OPTION_TWO>Beverages_list || OPTION_TWO<=0)
		{
			cout<<"Invalid option \n";
			return(-2);
		}
	}
	else if(OPTION_ONE==5)
	{
		clear_screen();
		cout<<"Please Pick the Item No from your list to delete the order\n";
		return -4;
	}
	//ENDNG THE PROGRAME
	else if(OPTION_ONE==6)
	{
		return 0;
	}
	//Viewing Ordered contents
	else if(OPTION_ONE==7)
	{
		clear_screen();
		cout<<"Your Order is \n";
		return -1;
	}
	//Deleting the Obj
	else if(OPTION_ONE==8)
	{
		return -3;
	}
	//Wrong entry@1
	else
	{
		cout<<"Invalid option\n";
		return(-2);
	}
	//cout<<"Option one="<<OPTION_ONE<<"Option two="<<OPTION_TWO<<endl;
	result=(100*OPTION_ONE)+OPTION_TWO;
	//Returning a Unique ID
	return(result);
	
}
//Class for Coustomer Inherited the contents from MENU class
class DRIV:public MENU
{
	int cost[100];
	char ITEMS[100][50],driv_no[5];
	public:	int unique_id[100];
		void set_driverno();	//Save Driver's no
		void show_contents(int);	//Show drivers contents
		void BILL(int,char n[]);	//Creat Drivers bill
		void delete_one(int,int);	//Deleting a single item from Present order
		~DRIV()				//Destroctor to delete The obj Driver
		{
			cout<<"Thank You! Come again\n";
			usleep(microseconds);
		}

};
//Set Driver  no
void DRIV::set_driverno()
{
	int i;
	cin>>driv_no;
	 driv_no[5]='\0';
	//cout<<driv_no;
}
//Show drivers contents
void DRIV::show_contents(int a)
{
	int i,opt1,opt2;
	cout<<setw(53)<<left<<"Items"<<"PRICE"<<endl;
	for(i=0;i<a;i++)
	{
		opt1=unique_id[i]/100;			//Claculation to decode
		opt2=unique_id[i]%100;			//      Unique no
		opt2-=1;
		switch(opt1)
		{
			case 1:cout<<setw(2)<<left<<i+1<<setw(1)<<left<<"."<<setw(53)<<left<<Pizza[opt2]<<Pizza_Price[opt2]<<endl;
				break;
			case 2:cout<<setw(2)<<left<<i+1<<setw(1)<<left<<"."<<setw(53)<<left<<Burger[opt2]<<Burger_Price[opt2]<<endl;
				break;
			case 3:cout<<setw(2)<<left<<i+1<<setw(1)<<left<<"."<<setw(53)<<left<<Dounut[opt2]<<Dounut_Price[opt2]<<endl;
				break;
			case 4:cout<<setw(2)<<left<<i+1<<setw(1)<<left<<"."<<setw(53)<<left<<Beverages[opt2]<<Beverages_Price[opt2]<<endl;
				break;
			default:break;
		}
	}
}
//Creat Bill
void DRIV::BILL(int a,char no[1])
{
	no[1]='\0';
	time_t t1=time(0);						//Setting time obj
	struct tm*now=localtime(&t1);					//Setting Current Bios time
	int i,opt1,opt2,total,vat;
	fstream KOT,NEW;						//File OBJ
	total=0;
	clear_screen();
	cout<<"----------------------------------------------------------\n";
	cout<<"                     FAST FOOD                            \n";
	cout<<"----------------------------------------------------------\n";
	cout<<"YOUR ORDER                                      TIME:"<<now->tm_hour<<":"<<now->tm_min<<endl;
	cout<<setw(53)<<left<<driv_no<<"PRICE\n";
	KOT.open(driv_no,ios::out);					//opening file for Kitcher Order Ticket
	NEW.open(no,ios::out);						//Opening File for Saving current order for Back Traching
	for(i=0;i<a;i++)
	{
		opt1=unique_id[i]/100;
		opt2=unique_id[i]%100;
		opt2-=1;
		switch(opt1)
		{
			case 0:break;
			case 1:strcpy(ITEMS[i],Pizza[opt2]);
				cost[i]=Pizza_Price[opt2];
				break;
			case 2:strcpy(ITEMS[i],Burger[opt2]);
				cost[i]=Burger_Price[opt2];
				break;
			case 3:strcpy(ITEMS[i],Dounut[opt2]);
				cost[i]=Dounut_Price[opt2];
				break;
			case 4:strcpy(ITEMS[i],Beverages[opt2]);
				cost[i]=Beverages_Price[opt2];
				break;
			default:break;
		}		
		total+=cost[i];						//Total cost
		if(opt1!=0)
		{
			NEW<<ITEMS[i]<<endl;
			KOT<<setw(53)<<left<<ITEMS[i]<<setw(10)<<left<<cost[i]<<endl;
			cout<<setw(53)<<left<<ITEMS[i]<<setw(10)<<left<<cost[i]<<endl;                                     
		}
	}
	vat=(14*total)/100;
	total+=vat;
	cout<<setw(53)<<left<<"Service tax and vat(14%)"<<vat<<endl;
	cout<<setw(53)<<left<<"Total"<<"="<<total<<endl;
	NEW<<"AMT="<<total;
	KOT.close();
	NEW.close();
}
//Delete Contents from Present order
void DRIV::delete_one(int START,int ARR)
{
	int i;
	for(i=START-1;i<ARR;i++)
	{
		unique_id[i]=unique_id[i+1];
	}
}
//Main FN()		
int main()
{
	//MENU OBJ1;
	//OBJ1.regg_name();
	int temp;
	char CAR,no_list[1];
	no_list[0]=65;
	for(;;)
	{
		clear_screen();
		cout<<"-------------------------------------------------------------------------\n";
		cout<<"                       WELCOME TO QUICK ORDER                            \n";
		cout<<"-------------------------------------------------------------------------\n"<<"Please Enter your car's last 4 DIGITS\n";
		DRIV OBJ2;
		OBJ2.set_driverno();
		for(int i=0;i<100;i++)
		{
			OBJ2.unique_id[i]=OBJ2.print_name();			//Save unique NO
			if(OBJ2.unique_id[i]==0)				//Print bill if =0
			{
				clear_screen();
				cout<<"HERE IS YOU BILL\n";
				OBJ2.BILL(i,no_list);
				cout<<"Please move along and wait for your order to be served\n";
				OBJ2.~DRIV();
				break;
			}
			else if(OBJ2.unique_id[i]==-1)				//Show contents if =-1
			{
				OBJ2.show_contents(i);
				i--;
				usleep(microseconds);
			}
			else if(OBJ2.unique_id[i]==-4)				//Show current contents and take option to delete
			{
				OBJ2.show_contents(i);
				cin>>temp;
				OBJ2.delete_one(temp,i);
				OBJ2.unique_id[i]=0;
				i--;
			}
			else if(OBJ2.unique_id[i]==-2)				//Invalid choice
				i--;
			else if(OBJ2.unique_id[i]==-3)				//Call dustroctor
			{
				OBJ2.~DRIV();
				no_list[0]--;
				break;
			} 
		}
	no_list[0]++;
	}
}
