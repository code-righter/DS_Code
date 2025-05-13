#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
Definition - the rear of the queue is connected to the front
Properties - Array of fixed size is used. 
             Two pointer keeps maintains the posistion of data
             
Application - CPU Scheduling in OS, Playing fixed-sized playlist,*/

class CircularQueue{
public:
    int front, rear, size;
    const int capacity = 5;
    int arr[20];

    CircularQueue(){
        rear = -1;
        front = -1;
        size = 0;
    }

    void enqueue(int val){
        if(isFull()) {
            cout<<"Queue is already full !!!"<<endl;
            return ;
        }
        
        // elements are pushed from rear 
        rear = (rear+1) % capacity;
        arr[rear] = val;
        size++;

        // here edge case is at the start 
        if(front == -1) front = rear;

        cout<<val<<" enqueued successfully"<<endl;
        return ;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is already empty !!!"<<endl;
            return ;
        }
        cout<<arr[front]<<endl;
        front = (front+1)%capacity;
        size--;

        // here edge case is at last
        if(size == 0){
            front = -1;
            rear = -1;
        }
        cout<<"queued successfully";
        return ;
    }

    bool isFull(){
        if(size == capacity) return true;
        else return false;
    }

    bool isEmpty(){
        if(size == 0) return true;
        else return false;
    }

    int getSize(){
        return size;
    }

    void printElements(){
        if(isEmpty()) {
            cout<<"Queue is empty !!"<<endl;
            return;
        }

        int f = front, r = rear;
        for(int i=0;i<size;i++){
            int idx = (front+i)%capacity;
            cout<<arr[idx]<<" ";
        }
        cout<<endl;
    }

};

void reverseStack() {
    cout << "Enter 5 elements to push into the stack:" << endl;
    stack<int> st;
    queue<int> q;

    int count = 5;
    int ele;

    
    for (int i = 0; i < count; i++) {
        cin >> ele;
        st.push(ele);
    }

    
    while (!st.empty()) {
        cout<<st.top()<<" ";
        q.push(st.top());
        st.pop();
    }

    cout<<"Reversed Stack is: "<<endl;
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    // cout << "Reversed stack is:" << endl;
    while (!st.empty()) {
        st.pop();
    }
    cout << endl;
}

int main(){

    int choice;
    CircularQueue q;
    int en;

    do
    {
           
        cout<<"\n\nCircular Queue Implementation"<<endl;
        cout<<"Enter the number against the choice"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. isFull"<<endl;
        cout<<"4. isEmpty"<<endl;
        cout<<"5. get size"<<endl;
        cout<<"6. print elements"<<endl;
        cout<<"7. reverse a stack using queue"<<endl;
        cout<<"8. Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the element to eneque :"<<endl;
            cin>>en;
            q.enqueue(en);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            if(q.isFull() == true) cout<<"Queue is full"<<endl;
            else cout<<"Queue is not full"<<endl; 
            break;
        
        case 4:
            if(q.isEmpty() == true) cout<<"queue is empty"<<endl;
            else cout<<"Queue is not empty"<<endl;
            break;
        
        case 5:
            cout<<"Size of the queue is "<<q.getSize()<<endl;
            break;

        case 6:
            q.printElements();
            break;

        case 7:
            reverseStack();
            break;

        case 8:
            cout<<"Exiting"<<endl;
            choice = 8;

        default:
            cout<<"Invalid Choice!!"<<endl;
            break;
        }
        
    } while (choice != 8);

    return 0;
}
