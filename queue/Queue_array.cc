#include<iostream>

using namespace std;

struct Queue{
	int front, rear,size, capacity;
	int* array;
};

struct Queue* createQueue(int capacity){
	struct Queue* queue = new Queue();
	queue->array = new int[capacity]();
	queue->front = 0;
	queue->capacity = capacity;
	queue->rear = queue->capacity - 1;
	queue->size = 0;
	return queue;
}

int isEmpty(struct Queue* queue){
	if(queue->size == 0)
		return 1;
	else
		return 0;
}

int isFull(struct Queue* queue){
	if(queue->size == queue->capacity)
		return 1;
	else
		return 0;
}


void enQueue(struct Queue* queue, int value){
	if(isFull(queue)){
		cout << "Queue is full\n";
		return ;
	}
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = value;
	queue->size = queue->size + 1;
	//cout <<"Queuing done\n";
}

int deQueue(struct Queue* queue){
	if(isEmpty(queue)){
		cout << "Queue is empty\n";
		return -1;
	}
	int value = queue->array[queue->front];
	queue->front = queue->front + 1;
	queue->size = queue->size - 1;
	return value;
}

void traverse(struct Queue* queue){
	int temp_front = queue->front;
	int temp_rear = queue->rear;
	//cout << queue->size << endl;
	//cout << temp_front << "    " << temp_rear << endl;
	while(temp_front != temp_rear){
		cout << queue->array[temp_front] << endl;
		temp_front = (temp_front + 1)%queue->capacity;
	}
	cout << queue->array[temp_front] << endl;
}

int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->rear];
}


int main(){
	struct Queue* queue = createQueue(10);
	enQueue(queue,1);
	enQueue(queue,2);
	enQueue(queue,3);
	enQueue(queue,4);
	cout << front(queue) << "   " << rear(queue) << endl;	
	//deQueue(queue);	
	traverse(queue);
	return 1;
}
		
