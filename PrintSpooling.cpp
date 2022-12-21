#include <iostream>
#include <ctime>
#include <queue>


using namespace std;


void set_time ( int seconds )
{
clock_t endwait;
endwait = clock () + seconds * CLOCKS_PER_SEC ;
while (clock() < endwait) {}
}


int main()
{

int max=5,choice,Qnumber=0,Q=0;
char ans,x;
srand((unsigned)time(0));
queue<char>spool;
queue<char>spool1;

do
{
cout<<"********Queue Program**********\n";
cout<<"1. Add\n";
cout<<"2. Delete\n";
cout<<"3. Current job\n";
cout<<"4. Quit\n";
cout<<"Enter Your choice : ";
cin>>choice;
if(choice==1)
{
do
{
do
{
if(Qnumber<max)
{
cout<<"\nEnter name of print job to Be Added : ";
cin>>x;
spool.push(x);
Qnumber++;

}
else
cout<<"Queue Full";
cout<<"\nDo you want to print more?[y/n]: ";
cin>>ans;
}while(ans=='y'||ans=='Y');

}while(choice=='y'||choice == 'Y');
}
else if(choice==2)
{
do
{
do
{
if(Qnumber!=0)
{
cout<<"Print Job "<<spool.front()<<" has been deleted"<<endl;
spool.pop();
Qnumber--;
}
else
{
cout<<"Queue Empty"<<endl;
}
cout<<"Want to Delete More[y/n]? ";
cin>>ans;


}while(ans=='y'||ans=='Y');

}while(choice=='y'||choice=='Y');
}
else if(choice==3)
{
if(Qnumber==0)
cout<<"\nQueue Empty!!";
else
{
cout<<"\nDisplaying Queue\n";
while(!spool.empty())
{
for(int d =1;d<=Qnumber;d++)
{
cout<<d<<". "<<spool.front()<<endl;
spool1.push(spool.front());
spool.pop();
}
}
while(!spool1.empty())
{
spool.push(spool1.front());
spool1.pop();
}
for(int d =1;d<=Qnumber;d++)
cout<<d<<". "<<spool.front()<<endl;
}
}
else if (choice==4)
exit(1);

cout<<"\nWant To Go To The Main Menu[y/n]? ";
cin>>ans;

/*srand((unsigned)time(0));
int n=(rand()%10)+1;
for(int j=n;j>0;j--)
{
set_time(1);
}*/
}while(ans == 'y'|| ans == 'Y');

return 0;
}
