

#include<stdio.h>
#include<stdlib.h>


void print();
struct node {

	int data;
	struct node* next;

};
	

struct list {
	
	struct node* head;;
	struct node* tail;;

}ll;

void push_front (int x) {

	if(ll.head == NULL){
	
		struct node* n = (struct node *)malloc(sizeof(struct node));
		ll.head = n;
		n->data = x;
		ll.tail = ll.head;
		n->next = NULL;
		
	}else{
		struct node* n = (struct node *)malloc(sizeof(struct node));
		n->next = ll.head;
		ll.head = n;
		n->data = x;

	}



}

void push_back(int x) {

	if(ll.head == NULL){
	
		struct node* n = (struct node *)malloc(sizeof(struct node));
		ll.tail = ll.head = n;
		n->data = x;
		n->next = NULL;
	}else{
	
		struct node* n = (struct node *)malloc(sizeof(struct node));
		ll.tail->next = n;
		ll.tail = n;
		
		n->data = x;
		n->next = NULL;
	}
}

struct node* search(int x ) {

	if(x < 0) {
	
		puts("invalid ");
		return 0;
	}

	struct node* temp = ll.head;
	int y = 0;
	while(y < x && temp != NULL) {
	
		temp = temp->next;
		y++;
	}

	return temp;

}

void insert(int x,int data) {

	if(x < 0 ) {
	
		puts("invalid ");
		return;
	}else if(x == 1){

	struct node* temp = search(x);
	struct node* n = (struct node *)malloc(sizeof(struct node));

	n->next = temp->next;
	temp->next = n;
	n->data = data;


	printf("%d\n",temp->data);
	print();

	}else{
	
	struct node* temp = search(x-1);
	struct node* n = (struct node *)malloc(sizeof(struct node));

	n->next = temp->next;
	temp->next = n;
	n->data = data;


	printf("%d\n",temp->data);
	print();
	
	}


}

void pop_back() {

	if(ll.head == NULL){
		
		return;
	}

	struct node* temp = ll.head;

	while((temp->next)->next != NULL) {
	
		temp = temp->next;
	}

	free(ll.tail);

	ll.tail = temp;
	temp->next = NULL;

	printf("%d\n",temp->data);
	print();

}

void pop_front() {

	if(ll.head == NULL){
		
		return;
	}

	struct node* temp = ll.head->next;
	
	free(ll.head);
	ll.head = temp;

	print();

}

void node_count() {

	int count = 0;
	struct node* temp = ll.head ;
	while(temp != NULL) {
	
		count += 1 ;
		temp = temp->next ;
	}
	
	printf("%d\n",count);


}


void erase_ind(int x ) {


	struct node* temp = ll.head;
	struct node* temp1 = NULL;
	int y = 0;

	if(x < 0) {
	
		puts("invalid ");
		return;
	}else if(x = 0) {
		ll.head = ll.head->next;
		free(temp);
		return;

	}

	
	while(y < x-1 && temp != NULL) {
	
		temp = temp->next;
		y++;
	}

	temp1 = temp->next->next;
	free(temp->next);
	temp->next = temp1;

	print();

}


void erase_val(int x ) {


	struct node* temp = ll.head;
	struct node* temp1 = NULL;
	//int y = 0;
	
	if(x < 0) {
	
		puts("invalid ");
		return;
	}else if(ll.head->data == x) {
		
		ll.head = ll.head->next;
		free(temp);
		return;

	}

		
	while(temp->data != x && temp != NULL) {
		
		temp1 = temp;
		temp = temp->next;
	//	y++;
	}
	
	// printf("%d\n",temp1->data);
	temp1->next = temp->next;
	free(temp);

	print();

}

void reverse() {

	struct node* temp = ll.head; 
	struct node* temp1 = temp->next;
	struct node* temp2 = temp1->next;

	while(temp1 != ll.tail) {
	
		temp1->next = temp;
		temp = temp1;
		temp1 = temp2;
		temp2 = temp2->next;
	
	
	}	

	ll.tail->next = temp;
	ll.tail = ll.head;
	ll.head = temp1;
	ll.tail->next = NULL;

	print();
}

/*void reverse() {

	struct node* pre = NULL;
	struct node* curr = ll.head;
	struct node* temp = NULL;

	while(curr != ll.tail) {

	pre = curr;
	curr = curr->next;
	temp = curr->next;
	curr->next = pre;
	curr = temp;


	}

	ll.tail = ll.head;
	ll.head = curr;
	ll.tail->next = NULL;


	print();
	


}*/

void print() {

	struct node* temp = ll.head; 
	while(temp != NULL){
	
		printf("%d -> ",temp->data);
		temp = temp->next;

	}

	printf("NULL \n");
}

void main(){
	
	push_front(1);
	push_back(2);
	push_back(3);
	push_front(4);

	print();
	erase_val(4);
	print();
	/*printf("%d\n",search(2)->data);
	
	insert(2,3);
	pop_back();
	pop_front();
	
	node_count();*/
	/*erase_ind(2);
	erase_val(3);
	erase_val(1);*/

	reverse();

}


	
