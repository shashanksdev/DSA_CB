#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node*next;
    node(int d){
        data=d;
        next=NULL;
    }    
};

void insertAtHead(node*&head,int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    node*temp=new node(data);
    temp->next=head;
    head=temp;
}

node* takeInput(){
    int d;
    cin>>d;

    node*head=NULL;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

void printLL(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

void moveLastToFront(node*&head){
    node*temp=head;
    //traverse pointer to end of LL
    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    //Break the second last node 
    temp->next->next=head;
    head=temp->next;
    temp->next=NULL;
}


int main(){
    node*head=NULL;

    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);

    printLL(head);

    moveLastToFront(head);

    printLL(head);
}