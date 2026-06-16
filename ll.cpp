#include<iostream>


class node {

    public :

        int data;
        node* next = NULL;

};

class linked_list {

    node* head = NULL;
    node* tail = NULL;
    
    public : 
    linked_list (){

        this->head = NULL;
        this->tail = NULL;


    }

    void push_back(int x) {

        node* n = new node();
        n->next = NULL;
        n->data = x;
        if(head == NULL) {
            head = n;
            tail = n;
            return;
        }

        tail->next = n;
        tail = n;



    }

    void push_front(int x) {
        node* n = new node();
        n->data = x;
        n->next = head;

        if(head == NULL) {
            head = n;
            tail = n;
            return;
        }

        head = n;

    }

    

    void pop_back() {

        node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }

        delete(tail);
        tail = temp;
        tail->next = NULL;
    }

    void pop_front() {

        node* temp = head->next;
        free(head);
        head = temp;

    }

    int search_ind(int x) {
        node* temp = head;
        int z = 0;

        if(x < 0 ) {
            puts("invalid");
            return 0;
        }

        while(z != x) {
            if(temp->next == NULL){
                std::cout << "NULL" << std::endl;
                return 0;
                break;
            }
            temp = temp->next;
            z++;
        }

        return temp->data;

    }

    int search_val(int x) {
        node* temp = head;
        int z = 0;

        if(x < 0 ) {
            puts("invalid");
            return 0;
        }

        while(temp->data != x ) {
            if(temp->next == NULL){
                std::cout << "NULL" << std::endl;
                return 0;
                break;
            }
            temp = temp->next;
            z++;
        }

        return z;

    }
    
    void insert(int x,int y) {

        node* n = new node();
        node* temp = head;
        node* temp1 = NULL;
        int z = 0;
        while(z != x) {

            if(temp == NULL) {
                return;
            }
            temp1 = temp;
            temp = temp->next;
            z++;
        }

        //std::cout<< temp->data << std::endl;
        //std::cout<< temp1->data << std::endl; 

        temp1->next = n;
        n->data = y;
        n->next = temp;
        
    }

    void delete_node(int x) {
        node* temp1 = NULL;
        node* temp = head;
        int z = 0;

        if(x < 0 ) {
            puts("invalid");
            return;
        }

        while(z != x) {
            if(temp->next == NULL){
                std::cout << "NULL" << std::endl;
                return;
            }
            temp1 = temp;
            temp = temp->next;
            z++;
        }

        temp1->next = temp->next;
        delete(temp);

 
    }

    void reverse() {

        node* temp = head;
        if(temp->next == NULL) {
            return;
        }else if(temp->next->next == NULL) {
            node* temp1 = temp->next;
            temp->next = NULL;
            temp1->next = head;
            head = tail;
            tail = temp1;
        }

        node* temp1 = temp->next;
        node* temp2 = temp1->next;

        while(temp2 != NULL) {
            temp1->next = temp;
            temp = temp1;
            temp1 = temp2;
            temp2 = temp2->next;
        }

        temp1->next = temp;
        head->next = NULL;
        tail = head;
        head = temp1;

    }
    
    void print() {
        node* temp = head;
        while(temp != NULL) {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }

        puts("NULL");

    }
};



int main(){

    linked_list ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(3);

    ll.print();
    ll.pop_back();
    ll.print();
    ll.pop_front();
    ll.print();
    std::cout << ll.search_ind(3) << std::endl;
    std::cout << ll.search_ind(0) << std::endl;
    std::cout << ll.search_ind(4) << std::endl;
    std::cout << ll.search_val(5) << std::endl;
    // std::cout << "done insertion " << std::endl;
    ll.insert(2,2);

    // std::cout << "done insertion " << std::endl;
    ll.print();
    ll.delete_node(2);
    ll.print();
    ll.reverse();
    ll.print();

    return 0;
}