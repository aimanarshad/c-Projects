#include <iostream>
using namespace std;
struct Queue{
	int value;
	int arr[5];
	
	bool isFull(){
		return(rear==5-1);
	}
	int rear = -1;
	int front = -1;
	bool isEmpty(){
		return(rear==-1 && front==-1);
	}
	void enqueue(int value){
		if(isFull()){
			cout<<"no place in queue"<<endl;
			return;
		}
		if(isEmpty()){
			rear=front=0;
			
		}
		else{
			rear++;
		}
		arr[rear]=value;
	}
	void dequeue(){
	
		if(isEmpty()){
			return;
		}
		if(front==rear){
			front=rear=-1;
		}
		else{
		
			front++;
		}
	}
	void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
	Queue q1;
	int option;
	int value;
	do{
	
		cout<<"1-enqueue";
		cout<<"2-dequeue";
		cout<<"enter option to do ";
		cin>>option;
		switch(option){
			case 1:
				cout<<"enter value "<<endl;
				cin>>value;
				q1.enqueue(value);
				break;
			case 2:
				cout<<"dequeue value";
				q1.dequeue();
				break;
			case 3:
				cout<<"exit"<<endl;
				
		}
		
	}while(option!=0);
	return 0;
}
