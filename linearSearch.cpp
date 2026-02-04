#include<iostream>
using namespace std;
int main(){
	int n , item;
	cout<<"enter size of array: "<<endl;
	cin>>n;
	int a[n];
	cout<<"enter element of array: "<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<"enter searching element: "<<endl;
	cin>>item;
	
	for(int i=0; i<n; i++){
		if(a[i]==item){
			cout<<"enter found at index "<<i<<endl;
			break;
		}
	}
	return 0;
}