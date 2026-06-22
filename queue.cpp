

#include<iostream>

template<typename T>
class queue {

size_t size_q = 0;
size_t capacity_q = 1;
T* que = NULL;

public :
queue() {
this->size_q = 0;
this->capacity_q = 1;
this->que  = new T[capacity_q];
}

queue(queue<T>&& q) {

this->que = q.que;
this->size_q = q.size_q;
this->capacity_q = q.capacity_q;
q.que = NULL;
q.size_q = 0;
q.capacity_q = 1;

}
queue(const queue<T>& que) {
this->size_q = que.size_q;
this->capacity_q = que.capacity_q;
this->que  = new T[capacity_q];

for(int x = 0; x != size_q; x++) {
	*(this->que + x) = *(que.que + x);
}

}
queue<T>& operator=(const queue<T>& que) {

if(this == &que) {
	return *this;
}

delete [] this->que;

this->size_q = que.size_q;
this->capacity_q = que.capacity_q;
this->que  = new T[capacity_q];

for(int x = 0; x != size_q; x++) {
	*(this->que + x) = *(que.que + x);
}

return *this;

}
queue<T>& operator=(queue<T>&& q) {

if(this == &q) {
	return *this;
}

delete [] this->que;

this->que = q.que;
this->size_q = q.size_q;
this->capacity_q = q.capacity_q;
q.que = NULL;
q.size_q = 0;
q.capacity_q = 1;

return *this;
}

void resize() {
	capacity_q = capacity_q*2;
	T* new_que = new T[capacity_q];
	T* temp = this->que;

for(int x = 0; x != size_q; x++) {
	*(new_que + x) = *(this->que + x);
}

this->que = new_que;
new_que = NULL;
delete [] temp;
	
}
void push(T x) {

if(size_q == capacity_q ) {
this->resize();
}
*(this->que + size_q) = x;
size_q++;

}

template<typename... U>

void emplace(U&& ...x) {
if(size_q == capacity_q) {
this->resize();

}
*(this->que + size_q) = T(std::forward<U>(x)...);
size_q++;
}

void pop() {

if(size_q == 0) {
return;
}

int x = 0;
*(this->que) = T();
while(x != size_q - 1) {
	*(this->que + x) = *(this->que + x + 1);
    x++;
}
size_q--;

}

void swap(queue<T>& queue) {
    if(this == &queue) {
        return;
    }
size_t size = queue.size_q;
size_t capacity = queue.capacity_q;
queue.size_q = this->size_q;
queue.capacity_q = this->capacity_q;
this->size_q = size;
this->capacity_q = capacity;
T* temp = this->que;
this->que = queue.que;
queue.que = temp;

}


inline __attribute__ ((always_inline)) size_t size() {
	return size_q;
}
inline __attribute__ ((always_inline)) T& front() {
	return *(this->que);
}
inline __attribute__ ((always_inline)) T& back() {
	return *(this->que + size_q - 1);
}
inline __attribute__ ((always_inline)) bool empty() {
	return size_q == 0;
}

~queue() {
	std::cout << "queue destructor " << std::endl;
	delete [] this->que; 
}
};
template<typename T>
void swap(queue<T>& q,queue<T>& q1) {
    q.swap(q1);
}

int main() {

	queue<int>q;
	q.push(0);
	q.push(0);
	q.push(0);
	q.push(0);
	q.push(0);
	q.push(0);
	q.emplace(1);
    q.pop();
    q.pop();
    q.pop();
	
    queue<int>q1;

    std::cout << q.size()  << q1.size() << std::endl;
    q.swap(q1);
    swap(q,q1);
std::cout << q.size()  << q1.size() << std::endl;
	q1 = q;
	queue<int> q2(q1);
	queue<int> q3(std::move(q2));
	queue<int> q4 = std::move(q3);
	


	return 0;
}
