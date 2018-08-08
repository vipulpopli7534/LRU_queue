#include<iostream>
using namespace std;
static int queue[50],rear=-1,front=-1,pos=9999,flag=0;
void enqueue(int n,int sz){
	if(rear==sz){
		cout<<"overflow";
	}
	if(rear==-1&&front==-1){
		rear++;
		front=0;
		queue[rear]=n;
	}
	else{
	rear++;
	queue[rear]=n;
	}
}
void dequeue(){
	if(front>rear){
		rear=-1;
		front=-1;
	}
	else{
		front++;
	}
}

void check(int n,int sz){
	
	if(front>rear){
	dequeue();
	}
	else{
		int tmp=queue[front];
		dequeue();
		check(n,sz);
		if(tmp==n)
		flag=1;
	
		enqueue(tmp,sz);
		
	}
}

int backtrack(int i,int arr[],int sz){

	if(front>rear){
	dequeue();
	}
	else{
		int tmp=queue[front];
		dequeue();
		backtrack(i,arr,sz);
			for(int j=i;j>=0;j--){
				if(arr[j]==tmp){
				
				if(pos>j)
				pos=j;
				break;
			}
			}
			enqueue(tmp,sz);
	}
}
void replace(int rmv,int n,int sz){

	if(front>rear){
		
		dequeue();
			}
	else{
		int tmp=queue[front];
		dequeue();
		replace(rmv,n,sz);
		if(tmp==rmv)
		tmp=n;
		enqueue(tmp,sz);
	}
}
void reverse(int sz){
	if(front>rear){
		dequeue();
		
	}
	else{int tmp=queue[front];
		dequeue();
		reverse(sz);
		enqueue(tmp,sz);
		
	}
}
 main(){
int frames_no,pages_no;
cout<<"Enter no of Frames";
cin>>frames_no;
cout<<"Enter no of Pages";
cin>>pages_no;
int count=0 ,arr[pages_no];
for(int i=0;i<pages_no;i++)
cin>>arr[i];
cout<<"OUTPUT:"<<endl;
for(int i=0;i<pages_no;i++){
	if(i<frames_no){
	enqueue(arr[i],frames_no);
	count++;
	cout<<arr[i]<<"=>  ";
		for(int i=front;i<=rear;i++){
		cout<<queue[i]<<" ";
	}
	cout<<"Miss";
	cout<<endl;
}
	else{
	
		check(arr[i],frames_no);
		reverse(frames_no);
	if(flag==0){
			count++;
			backtrack(i,arr,frames_no);
			int rmv=arr[pos];
			pos=9999;
			
				reverse(frames_no);
			replace(rmv,arr[i],frames_no);
			reverse(frames_no);

		}
		
	cout<<arr[i]<<"=>  ";	
	for(int i=front;i<=rear;i++){
		cout<<queue[i]<<" ";}
	if(flag==0)cout<<"Miss";
	else cout<<"Hit";
	cout<<endl;
	
	flag=0;
	}
}

cout<<"Number of Page fault=>"<<count;	
  }
	

