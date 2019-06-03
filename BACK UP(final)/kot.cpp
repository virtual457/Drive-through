#include<iostream>
#include<fstream>
#include<unistd.h>
int i=0;
unsigned int microseconds=5000000;
using namespace std;
class ORDER
{
	int size;
	char Array[101][80];
	public:void read(char a[]);
		void display();
		~ORDER()
		{
			i++;
			cout<<"------------\n";
			cout<<" Next order:-"<<i<<"  \n";
			cout<<"------------\n";
		}
};
void ORDER::read(char a[])
{
	int i;
	i=0;
	ifstream test(a,ios::in);
	if(!test)
	{
		cout<<"ERROR";
	}
	while(!test.eof())
	{
		test>>Array[i];
		i++;
	}
	test.close();
	size=i;
}
void ORDER::display()
{
	for(int i=0;i<size;i++)
		cout<<Array[i]<<endl;
}
int main()
{
	int i;
	char cont[0];
	cont[0]=65;
	ORDER x[1000];
	for(;;)
	{
		ifstream test(cont,ios::in);
		if(test)
		{
			test.close();
			//cout<<cont<<"TEST\n";
			x[i].read(cont);
			x[i].display();
			x[i].~ORDER();
			cont[0]++;
		}
		usleep(microseconds);
	}
}
