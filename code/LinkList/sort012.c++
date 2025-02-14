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

Node* segregate(Node* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        Node* temp = head;
        
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);
        Node* zeroHead = zero;
        Node* oneHead = one;
        Node* twoHead = two;
        
        
        while(temp != NULL){
            if(temp->data == 0){
                zero->next = temp;
                zero = temp;
            }
            else if(temp->data == 1){
               one->next = temp;
                one = temp;
            }
            else if(temp->data == 2){
                two->next = temp;
                two = temp;
            }
               temp = temp->next; 
        }
        
        zero->next = (oneHead->next) ?(oneHead->next) : (twoHead->next);
        one->next = twoHead->next;
        two->next=NULL;

        Node* headNode= zeroHead->next;
        delete oneHead;
        delete twoHead;
        delete zeroHead;
        return headNode;
    }

int main(){
    cout<<"Hello World!!!" << endl;

    int arr[8] = {0,2,1,2,0,1,0,2};
    Node* head = dLL(arr,8);
   head= segregate(head);
    print(head);

}


