#include<iostream>
using namespace std;

void display(int arr[],int n)
{
cout<<"current array:";
for(int i=0;i<n;i++)
{
cout<<arr[i]<<"";
}
cout<<endl;
}

int main()
{
int arr[100]={10,20,30,40,50};
int n=5;
int choice, element, pos;

while(true){
cout<<"\n--Array Operations Menu--"<<endl;
cout<<"1.Insert\n2.Delete\n3.Update\n4.Display\n5.Exit"<<endl;

cout<<"enter your choice:";
cin>>choice;

switch(choice)
{
case 1:
cout<<"enter element and position:";
cin>>element>>pos;
 
if(pos<=n)
{
for(int i=n; i>pos; i--)
{
arr[i]=arr[i-1];
arr[pos]=element;
n++;
cout<<"Inserted"<<endl;
}
else
{
cout<<"invalid position"<<endl;
break;

case 2:
cout<<"enter position to delete:";
cin>>pos;
if(pos<n)
{
for(int i=pos; i<n-1 ;i++)
{
arr[i]=arr[i+1];
}
n--;
cout<<"Deleted<<endl;
}
else
{cout<<"invalid position"<<endl;
}
break;

case 3:
cout<<"enter position and new value:";
cin>>pos>>element;
if(pos<n){
arr[pos]=element;
cout<<"Updated"<<endl;
}
else
{
cout<<"invalid position"<<endl;
}
break;

case 4:
display(arr,n);
break;

case 5:
return 0;

default:
cout<<"invalid choice"<<endl;
}
}
return 0;
}




 