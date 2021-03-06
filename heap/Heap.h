class Heap{
	int capacity, size, *arr;
public:
    Heap(int capacity);
    int parent(int index);
    int left(int index);
    int right(int index);
    int getMin();
    void extractMin();
    void insert(int value);
    void print();
    void swap(int &a, int &b);
    void decreaseKey(int index, int new_value);
    void minHeapify(int index);
    void deleteKey(int i);
    void heapify(int a[], int size);

};
