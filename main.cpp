#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* createNewNode(int data){
    Node* newptr= new Node();
    newptr->data=data;
    newptr->next= nullptr;
    newptr->prev= nullptr;
    return newptr;
}

void insertAtFront(Node* &head,int data) {
    if (head == nullptr) {
        head = createNewNode(data);
        return;
    }
    Node *newptr = createNewNode(data);
    newptr->next = head;
    head->prev = newptr;
    head = newptr;
}
void insertAtEnd(Node* &head,int data){
    if(head== nullptr){
        head=createNewNode(data);
        return;
    }
    Node* temp=head;
    while (temp->next!= nullptr){
        temp=temp->next;
    }
    Node* newptr=createNewNode(data);
    newptr->prev=temp;
    temp->next=newptr;
}
int count(Node* &head){
    if (head== nullptr){
        return 0;
    }
    int count=0;
    Node* temp=head;
    while (temp!= nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}
void insertAfterPos(Node* &head,int data,int pos){
    if (head==nullptr){
        cout<<"list is empty";
        return;
    }
    if (pos>count(head)){
        cout<<"position not found";
        return;
    }
    int i=1;
    Node* temp =head;
    while (i<pos){
        temp=temp->next;
        i++;
    }
    Node* newptr=createNewNode(data);
    newptr->next=temp->next;
    newptr->prev=temp;
    newptr->next->prev=newptr;
    temp->next=newptr;

}

void printLinkedList(Node* &head ){
    if(head==nullptr) {
        cout << "list is empty";
        return;
    }
    Node* temp=head;
    while (temp!= nullptr){
        cout<<temp->data<<"  ";
        temp=temp->next;

    }

}
void insertAfterKey(Node* &head,int data,int key){
    if(head== nullptr){
        head=createNewNode(data);
        return;
    }
    Node* temp=head;
    while (temp->data!=data){
        temp=temp->next;
    }
    Node* newptr=createNewNode(data);
    newptr->prev=temp;
    newptr->next=temp->next;
    newptr->next->prev=newptr;
    temp->next=newptr;
}
void deleteAtFront(Node* &head){
    if(head== nullptr){
        cout<<"list is empty";
    }
    Node* temp=head;
    head=temp->next;
    delete temp;
}

void deleteAtEnd(Node* &head){
    if(head== nullptr){
        cout<<"list is empty";
    }
    Node* temp=head;
    while (temp->next!= nullptr){
        temp=temp->next;
    }
    temp->prev->next= nullptr;
    delete temp;
}
void deleteFromPos(Node* &head,int pos){
    if(head== nullptr){
        cout<<"list is empty";
    }
    Node* temp=head;
    int i=1;

    while (i!=pos){
        temp=temp->next;
        i++;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    delete temp;
}

void deleteFromKey(Node* &head,int key){
    if(head== nullptr){
        cout<<"list is empty";
    }
    Node* temp=head;
    while (temp->data!=key){
        temp=temp->next;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    delete temp;
}
void search(Node* &head,int data){
    if (head== nullptr){
        cout<<"list is empty";
    }
    Node* temp=head;
    while (temp->data!=data && temp->next!= nullptr){
        temp=temp->next;
    }
    if (temp->data==data ){
        cout<<"key is found";
    }else{
        cout<<"key is not found";
    }

}
void updateFromkey(Node* &head,int data,int newdata){
    if(head== nullptr){
        cout<<"list is empty";
    }
    Node* temp=head;
    while (temp->data!=data && temp->next!= nullptr){
        temp=temp->next;
    }
    if(temp->data==data){
        temp->data=newdata;
    }else{
        cout<<"key not found";
    }

}



int main() {
    Node* head= nullptr;
    insertAtFront(head,3);
    insertAtFront(head,2);
    insertAtFront(head,1);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,7);
    cout<<count(head)<<endl;
    insertAfterPos(head,6,5);
    updateFromkey(head,3,12);
    printLinkedList(head);


    return 0;
}
