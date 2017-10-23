//heap priority queue

#include<iostream>
#include<string>
#include<cassert>

using namespace std;

#define INIT_HEAP_SIZE 64

struct Heap {
    private:
        int size;
        int max_size;
        int *array;
        int heapType;
        void percolateDown (int idx);
    public:
        Heap () {
            array = new int [INIT_HEAP_SIZE];
            max_size = INIT_HEAP_SIZE - 1;
            size = -1;
            heapType = 1; //max heap
        }
        ~Heap () {
            delete array;
        }
        int getParent (int idx) {
            //no parent for root
            if (idx > size || idx == 0) return -1;
            return (idx - 1) / 2;
        }
        int getLeftChild (int idx) {
            if (2 * idx + 1 > size) return -1;
            return 2 * idx + 1;
        }
        int getRightChild (int idx) {
            if (2 * idx + 2 > size) return -1;
            return 2 * idx + 2;
        }
        int getMax () {
            return array[0];
        }
        void insert (int num);
        void del ();
        void print () {
            cout << "HEAP ->" << endl;
            for (int i = 0; i <= size; i++)
                cout << array[i] << " ";
            cout << endl;
        }
        //TODO
        void resizeHeap(){}
};

//add element to the end of the array
//Then percolate up
void Heap::insert(int num) {
    if (size >= max_size) {
        resizeHeap();
    }

    size++;
    array[size] = num;

    //swap element with parent
    int childIdx = size;
    int parentIdx = getParent(size);
    //loop until we reach the root
    /*while (parentIdx == -1  || array[parentIdx] < array[childIdx]) {
        int parent = array[parentIdx];
        array[parentIdx] = array[childIdx];
        array[childIdx] = parent;
        childIdx = parentIdx;
        parentIdx = getParent(childIdx);
    }*/

    //another way
    //loop until we reach the root
    while (parentIdx != -1  && array[parentIdx] < num) {
        array[childIdx] = array[parentIdx];
        childIdx = parentIdx;
        parentIdx = getParent(parentIdx);
    }
    array[childIdx] = num;
    print();
}

void Heap::percolateDown (int idx) {
    if (idx > size) return;
    int leftChild = array[getLeftChild(idx)];
    int rightChild = array[getRightChild(idx)];
    int currNode = array[idx];

    //swap smaller parent with larger of the 2 children
    int swapChildIdx;
    int swapChild;
    if (leftChild > rightChild) {
        swapChild = leftChild;
        swapChildIdx = getLeftChild(idx);
    }
    else {
        swapChild = rightChild;
        swapChildIdx = getRightChild(idx);
    }

    //swap
    if (swapChild > currNode) {
        int tmp = swapChild;
        array[swapChildIdx] = currNode;
        array[idx] = tmp;
    }
    else {
        //child is smaller or equal to parent. Stop recurring
        return;
    }
    percolateDown(swapChildIdx);
}

//swap last element with the first element then percolate down
void Heap::del() {
    if (size == -1) return;
    array[0] = array[size];
    size--;
    percolateDown(0);
    print();
}

int main () {
    Heap H;
    H.insert(31);
    H.insert(10);
    H.insert(16);
    H.insert(12);
    H.del();
    H.del();
    H.del();
    H.del();
    H.insert(31);
    H.insert(10);
    H.insert(16);
    H.insert(9);
    H.insert(8);
    H.insert(14);
    H.insert(12);
    H.insert(3);
    H.insert(1);
    H.insert(5);
    H.insert(7);
    H.insert(19);
    H.del();
    H.del();
    return 0;
}
