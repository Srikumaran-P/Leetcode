
typedef struct {
    int* data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isEmptyQueue(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(Queue* queue) {
    return queue->data[queue->front];
}

// Stack implementation using two queues
typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue(100);  // Setting queue size to 100
    stack->q2 = createQueue(100);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x);  // Push to q2

    // Move all elements from q1 to q2
    while (!isEmptyQueue(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    // Swap q1 and q2
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

int myStackTop(MyStack* obj) {
    return front(obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    free(obj->q2->data);
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */
