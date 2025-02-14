#include <iostream>
using namespace std;

//Create Node
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data, Node* next,Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data){
       this->data = data;
       next = nullptr;
       back = nullptr;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
    }
}

//Creating LinkList
Node* dLL(int arr[],int n){

Node* head = new Node(arr[0]);
Node* prev = head;
for(int i =1 ; i<n ; i++){
Node* temp = new Node(arr[i],nullptr,prev);
prev->next = temp;
prev = temp;
}
return head;
}

Node* oddEven(Node* head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while(even !=NULL && even->next !=NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main(){
    cout<<"Hello World!!!" << endl;

    int arr[8] = {7,6,1,8,5,7,9,6};
    Node* head = dLL(arr,8);
   head= oddEven(head);
    print(head);

}
