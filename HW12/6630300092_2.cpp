#include<iostream>
using namespace std;

int heapSize = 10;
int a[16];

void buildHeap(int a[]);
void heapify(int a[], int i, int heapSize);
void exchange(int &x, int &y);
void printData(int a[]);
void heapSort(int a[]);

int getLeft(int i);
int getRight(int i);
int getParent(int i);

int main(){
    cout << "input Array: ";
    for(int i = 1; i <= 10; i++){
        cin >> a[i];
    }

    buildHeap(a);

    cout << "Heap : ";
    printData(a);

    heapSort(a);

    return 0;
}

void printData(int a[]){
    for(int i = 1; i <= 10; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void exchange(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int getLeft(int i){ return 2 * i; }
int getRight(int i){ return 2 * i + 1; }
int getParent(int i){ return i / 2; }

void buildHeap(int a[]){
    for(int i = heapSize / 2; i >= 1; i--){
        heapify(a, i, heapSize);
    }
}

void heapify(int a[], int i, int heapSize){
    int left = getLeft(i);
    int right = getRight(i);
    int largest = i;


    if(left <= heapSize && a[left] > a[largest]){
        largest = left;
    }

    if(right <= heapSize && a[right] > a[largest]){
        largest = right;
    }

    if(largest != i){
        exchange(a[i], a[largest]);
        heapify(a, largest, heapSize);
    }
}

void heapSort(int a[]){
    int heapLength = heapSize;
    int time = 1;
    buildHeap(a);

    cout<<"Heap sort"<<endl;
    for(int i = heapSize; i >= 2; i--){
        exchange(a[1], a[i]);
        cout << "#" << time << "  :";
        printData(a);
        heapLength--;
        heapify(a, 1, heapLength);
        time++;
    }
    cout << "#" << time << " :";
    printData(a);
}
