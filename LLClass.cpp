#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int val){
            this->val = val;
            next = NULL;
        }
};

class LinkedList{
    public:
        Node* head;
        Node* tail;
        int size;
        LinkedList(){
            head = NULL;
            tail =NULL;
            size=0;
        }
        void insertAtTail(int val){
            Node* temp = new Node(val);
            if(size>0){
                tail->next = temp;
                tail = temp;
            }
            else{
                head = temp;
                tail = temp;
            }
            size++;
        }
        void insertAtHead(int val){
            Node* temp = new Node(val);
            if(size>0){
                temp ->next = head;
                head = temp;
            }
            else{
                head = temp;
                tail = temp;
            }            
            size++;
        }
        void insertAt(int idx, int val){
            if(idx<0||idx>size) cout<<"Invalid"<<endl;
            else if(idx ==0||size==0 ) insertAtHead(val);
            else if(idx == size) insertAtTail(val); //size is not yet updated, so idx==size!
            else{
                Node* temp = new Node(val);//Just have to link this with (idx)th Node and link temp with (idx+1)th Node
                int count = 1;
                Node* t = new Node(0);
                t = head;
                while(count<idx){
                    t = t->next;
                    count++;
                }
                temp->next = t->next;
                t->next = temp;
                size++;
            }

        }
        int getElement(int idx){
            if(idx<0||idx>=size) {
                cout<<"Invalid"<<endl;
                return -99999;
            }
            else if(idx==0) return head->val;
            else if(idx == size-1) return tail->val;
            else{
                Node* temp = new Node(0);
                temp = head;
                int count =0;
                while(count<idx){
                    temp = temp->next;
                    count++;
                }
                return temp->val;
            }
        }
        void deleteAtHead(){
            if(size==0){ cout<<"List already empty!" <<endl; return;}
            else if(size==1) head = tail= NULL;
            else{
                head = head->next;
            }
            size--;
        }
        void deleteAtTail(){
            if(size==0){ cout<<"List already empty!" <<endl; return; }
            else if(size==1) head = tail = NULL;
            else{
                Node* temp = new Node(0);
                temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                temp->next = NULL;
                tail = temp;
            }
            size--;
        }
        void deleteAt(int idx){
            if(size==0) cout<<"List already empty!" <<endl;
            else if(size==1) head = tail = NULL;
            else{
                if(idx ==0) deleteAtHead();
                else if(idx == size-1) deleteAtTail();
                else{
                    Node* temp = new Node(0);
                    temp = head;
                    int count =1;
                    while(count<idx){
                        temp = temp->next;
                        count++;
                    }
                    temp->next = temp->next->next;
                    size--;
                }
            }
        }
        void display(){
            Node* temp = new Node(0);
            temp = head;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp  = temp->next;
            }
            cout<<endl;
        }
        
};

int main(){
    LinkedList ll;
    ll.insertAtTail(10);
    ll.insertAtTail(20);
    //ll.display();
    ll.insertAtTail(30);
    //ll.display();
    ll.insertAtHead(100);
    ll.display();
    ll.insertAt(2,44);
    ll.display();
    ll.insertAt(5,99);
    ll.display();
    ll.insertAt(5,78);
    ll.display();
    //cout<<ll.getElement(4)<<endl;
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAt(3);
    ll.display();


}