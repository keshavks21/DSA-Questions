#include <iostream>
using namespace std;

//Create Node
class Node{
    public:
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
    Node(int data){
       this->data = data;
       next = nullptr;
    }
};

//Creating LinkList
Node* linkLst(int arr[],int n){

Node* head = new Node(arr[0]);
Node* temp = head;
for(int i =1 ; i<n ; i++){
Node* moveNxt = new Node(arr[i]);
temp->next = moveNxt;
temp = moveNxt;
}
return head;
}

//Insertion

    //At Start
    Node* insertAtStart(Node* head, int el){
    Node* newNode = new Node(el,head);
    return newNode;
    };

    //At End
    Node* insertAtEnd(Node* head, int el){
    Node* newNode = new Node(el);
    Node* temp = head;
    if(temp == NULL){
        head = newNode;
    }
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next =  newNode;
    return head;
    };

    //At Any Position
    Node* insertAtAnyPos(Node* head, int el,int pos){
    Node* newNode = new Node(el);
    Node* temp = head;
    int count =0;
    if(temp == NULL){
        if(pos ==1)return new Node(el);
        else return NULL;
    }
    if(pos == 1) {
    newNode->next = temp;
    return newNode;
    }
    while(temp!=NULL){
    count++;
    if(count == pos-1){
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }else
    temp = temp->next;
    }
    return head;
    };

    // At Position Before Value
    Node* insertByVal(Node* head, int el,int val){
    Node* newNode = new Node(el);
    Node* temp = head;
    if(temp == NULL){
       return temp;
    }
    if(temp->data == val) {
    newNode->next = temp;
    return newNode;
    }
    while(temp->next!=NULL){

    if(temp->next->data == val){
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
    temp = temp->next;
    }
    return head;
    };


//Deletion

    //Delete from head
    Node* deleteHead(Node* head){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    //Delete from end
    Node* deleteEnd(Node* head){
        Node* temp = head;
        if(head == NULL || temp->next == NULL) return NULL;
     
        while(temp->next->next != NULL){
            temp= temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        return head;
    }

    //Delete At Any Position
    Node* deleteAtAnyPos(Node* head,int pos){
    Node* temp = head;
    int count =0;
    if(temp == NULL){
        return NULL;
    }
    if( pos == 1){
        head = temp->next;
        delete temp;
        return head;
    }
   
    while(temp->next!=NULL){
    count++;
    if(count == pos-1){
        Node* del = temp->next;
        temp->next= temp->next->next;
        delete del;
    }else
    temp = temp->next;
    }
    return head;
    };

    //Delete At Position Before Value
    Node* deleteBeforeVal(Node* head,int val){
    Node* temp = head;
    Node* tempPrv = temp;
    if(temp == NULL){
        return NULL;
    }
    if( temp->data == val){
        return head;
    }
    if( temp->next->data == val){
        head = temp->next;
        delete temp;
        return head;
    }
    while(temp->next!=NULL){
    if(temp->next->data == val){
        Node* del = temp;
        tempPrv->next= temp->next;
        delete del;
        return head;
    }else
    tempPrv = temp;
    temp = temp->next;
    }
    return head;
    };

    //Delete At Position By Value
    Node* deleteByVal(Node* head,int val){
    Node* temp = head;
    if(temp == NULL){
        return NULL;
    }
    if( temp->data == val){
        head = temp->next;
        delete temp;
        return head;
    }
    while(temp->next!=NULL){
    if(temp->next->data == val){
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;
    }else
    temp = temp->next;
    }
    return head;
    };


int main(){
    cout<<"Hello World!!!" << endl;

    int arr[5] = {2,4,5,1,6};
    Node* head = linkLst(arr,5);
    
    // Node* head1 = insertAtEnd(head, 8);
    // Node* head1 = insertAtStart(head, 8);
    // Node* head1 = insertAtAnyPos(head, 8,5);
    // Node* head1 = insertByVal(head, 8,7);

    // Node* head1 = deleteHead(head);
    // Node* head1 = deleteEnd(head);
    // Node* head1 = deleteAtAnyPos(head,4);
    // Node* head1 = deleteBeforeVal(head,1);
    Node* head1 = deleteByVal(head,5);

    Node* temp = head1;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
    }

}