#include<iostream>
using namespace std;
int main(){
	int n,item;
	cout<<"enter size of array: "<<endl;
	cin>>n;
	
	int a[n];
	cout<<"enter element of array: "<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	//bubble sort
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if(a[j]>a[j+1]){
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	
	cout<<"sorted element "<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;


	cout<<"enter searching element: "<<endl;
	cin>>item;
	int beg = 0;
	int end = n-1;
	
	while(beg<=end){
		int mid = (beg+end)/2;
		
		if(a[mid]==item){
			cout<<"element found at index "<<mid<<endl;
			break;
		}else if(a[mid]<item){
			beg = mid+1;
		}else{
			end = mid-1;
		}
	}
	return 0;
	}