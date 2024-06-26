#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

Node *head=NULL;

Node* createNode(){
    Node* newNode=new Node();

    cout<<"Enter Data:";
    cin>>newNode->data;
    
    newNode->next=NULL;
    
    return newNode;
}

void addFirst(){
    Node *newNode=createNode();
    if(head==NULL){
        head=newNode;
    }else{
        Node* temp=head;
        head=newNode;
        head->next=temp;
    }
}

void addAtPos(int pos){
    if(head==NULL){
        addFirst();
    }else if(pos==1){
        addFirst();
    }else{
        int count=1;
        Node *temp=head;
       
        while(count!=(pos-1)){
            count++;
            temp=temp->next;
        }

        Node* newNode=createNode();
    
        Node* temp2=temp->next;
    
        temp->next=newNode;
        newNode->next=temp2;
    }
}

void addLast(){
    Node *newNode=createNode();
    if(head==NULL){
        head=newNode;
    }else{
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void delFirst(){
    if(head==NULL){
        cout<<"LL Empty!";
    }else{
        Node* temp=head;
        head=head->next;
        free(temp);
    }
}

void delAtPos(int pos){
    if(head==NULL){
        cout<<"LL Empty!";
        return;
    }else if(pos==1){
        delFirst();
    }else{
        Node* temp=head;
        int count=1;
        while(count!=(pos-1)){
            count++;
            temp=temp->next;
        }

        Node* temp2=temp->next->next;
        free(temp->next);
        temp->next=temp2;
    }
}

void delLast(){
    if(head==NULL){
        cout<<"LL empty!";
    }else if(head->next==NULL){
        delFirst();
    }else{
        Node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void printLL(){
    if(head==NULL){
        cout<<"LL empty!";
    }else{
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"-";
            temp=temp->next;
        }
        cout<<"X";  
    }
}

void reverseLL(){
    if(head==NULL){
        cout<<"LL Empty!";
    }else{
        Node* curr=head;
        Node* prev=NULL;
        Node* next=head;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
}

int main(){
    Node *obj=new Node();
    
    while(1){
        int ip;
        cout<<"\nEnter Function:"<<endl;
        cout<<"1. Add Node at 1st Pos."<<endl;
        cout<<"2. Add Node at Last Pos."<<endl;
        cout<<"3. Del Node from 1st Pos."<<endl;
        cout<<"4. Del Node from Last Pos."<<endl;
        cout<<"5. Add Node at Pos."<<endl;
        cout<<"6. Del Node at Pos."<<endl;
        cout<<"7. Reverse LL."<<endl;
        cout<<"8. PrintLL."<<endl;
        cout<<"9. Exit."<<endl;
        cin>>ip;

        switch(ip){
            case 1:
                addFirst();
                break;
            
            case 2:
                addLast();
                break;

            case 3:
                delFirst();
                break;
            
            case 4:
                delLast();
                break;

            case 5:{
                int pos;
                cout<<"Enter Pos:";
                cin>>pos;
                addAtPos(pos);
                break;
            }

            case 6:{
                int pos;
                cout<<"Enter Pos:";
                cin>>pos;
                delAtPos(pos);
                break;
            }

            case 7:
                reverseLL();
                break;

            case 8:
                printLL();
                break;
            
            case 9:
                exit(0);
                break;

            default:
                cout<<"Invalid IP";
                break;
        }
    }

    return 0;
}