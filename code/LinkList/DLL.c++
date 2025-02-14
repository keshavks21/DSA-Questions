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

//Deletion 

    //Delete head Node
    Node* deleteHead(Node* head){
        Node* prev = head;
        if(head == NULL || head->next == NULL) return NULL;
       
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;
        prev->back = nullptr;
        delete prev;
        return head;
    }

    //Delete end Node
    Node* deleteEnd(Node* head){
        Node* tail = head;
        if(head == NULL || head->next == NULL) return NULL;
       
       while(tail->next != NULL){
            tail = tail->next;
       }
        Node* prev = tail->back;
        prev->next= nullptr;
        tail->back = nullptr;
        delete tail;
        return head;
    }

    //Delete Node At Positon
    Node* deleteAtPos(Node* head,int pos){
      
      int count =0;
        Node* temp = head;
        if(head == NULL) return NULL;
       
       while(temp != NULL){
        count++;
        if(count == pos) break;
        temp = temp->next;
       }
            Node* prev = temp->back;
            Node* front = temp->next;

            if(prev == nullptr){
              return deleteHead(head);
            }
            
           if(front == nullptr){
            return deleteEnd(head);
           }

            prev->next = front;
            front->back = prev;
            delete temp; 
       

    //    while(temp != NULL){
    //     count++;
    //     if(count == pos){

    //         if(pos ==1){
    //           return deleteHead(head);
    //         }
    //          if(temp->next == NULL){
    //             return deleteEnd(head);
    //         }
            
    //         Node* prev = temp->back;
    //         Node* front = temp->next;

    //         prev->next = front;
    //         front->back = prev;
    //         // delete temp; 

    //     }else{
    //         temp = temp->next;
    //     }
    //    }
       
       
        return head;
    }

    //delete by value
    void deleteByVal(Node* node){

        Node* prev = node->back;
        Node* front = node->next;

        if(front == NULL){
            prev->next = nullptr;
            node->back =nullptr;
            free(node);
            return;
        }

        prev->next = front;
        front->back = prev;
        node->next =nullptr;
        node->back =nullptr;
        free(node);
      
        return;
    }

    //Insertion
      //insert before head
        Node* insertBfHead(Node* head , int val){
            Node* newNode = new Node(val, head,nullptr);
            head->back = newNode;
            return newNode;
        }
      //insert before tails;
        Node* insertBfEnd(Node* head , int val){
            Node* tail = head;
            if(tail->next == NULL){
                return insertBfHead(head,val);
            }

            while(tail->next != NULL){
                tail= tail->next;
            }
            Node* newNode = new Node(val,tail,tail->back);
            tail->back->next = newNode;
            tail->back = newNode;
            return head;
        }

        //insert before position 
        Node* inserBfPos(Node* head , int pos, int val){
            Node* temp =head;
            int count =0;

            while(temp !=NULL){
                count++;
                if(count == pos){
             Node* prev = temp->back;
            if(prev == NULL) return insertBfHead(head,val);
            Node* newNode = new Node(val,temp, prev);
            temp->back->next= newNode;
            temp->back = newNode;
             return head; 
                }
                else
                temp = temp->next;
            }
           
            return head;    
        }

        //insert before node 
        void inserBfNode(Node* node, int val){
            Node* temp =node;
            Node* newNode = new Node(val,temp,temp->back);
            temp->back->next = newNode;
            temp->back = newNode;    
        }

int main(){
    cout<<"Hello World!!!" << endl;

    int arr[5] = {7,6,1,8,5};
    Node* head = dLL(arr,5);

//    head = deleteHead(head);
    // deleteEnd(head);
    // deleteAtPos(head,2);
    // deleteByVal(head->next->next);
//    head = insertBfHead(head,3);
//    head = insertBfEnd(head,1);
//    head = inserBfPos(head,5,3);
   inserBfNode(head->next->next->next->next,9);
    print(head);

}