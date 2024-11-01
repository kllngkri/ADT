#include<iostream>

using namespace std;

int heapSize = 10;
int a[16];

void buildHeap(int a[]);
void heapify(int a[], int i, int heapSize);
void exchange(int &x, int &y);
void printData(int a[]);
void heapSort(int a[]);
void inputArray();
void Heap_insert(int key);
int Heap_Exact_Max(int a[]);

int getLeft(int i);
int getRight(int i);
int getParent(int i);

int main(){
    int choose;

    do{
        cout << "========================\n"
                "          MENU            \n"
                "========================\n"
                "1) Input Array\n"
                "2) Print Heap\n"
                "3) Insert Queue\n"
                "4) Service\n"
                "5) Exit\n";
        cout << "Please choose > ";
        cin >> choose;

        switch(choose){

            case 1 :
                inputArray();
                buildHeap(a);
                break;
            case 2 :
                cout<<"Heap : ";
                printData(a);
                break;
            case 3 :
                int key;
                cout<<"Inpuut : ";
                cin>>key;
                Heap_insert(key);
                cout<<"Heap : ";
                printData(a);
                break;
            case 4 :
                cout<<"Service : "<<Heap_Exact_Max(a)<<endl;
                cout<<"Heap : ";
                printData(a);
                break;



        }

    }while(choose!=5);




}
void printData(int a[]){
    for(int i = 1; i <= heapSize; i++){
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

void inputArray(){
    cout << "input Array: ";
    for(int i = 1; i <= 10; i++){
        cin >> a[i];
    }
}

void Heap_insert(int key){

    heapSize = heapSize + 1;
    int i = heapSize;
    while (i>1&&a[getParent(i)]<key){
        a[i] = a[getParent(i)];
        i = getParent(i);
        a[i] = key;
    }

}
int Heap_Exact_Max(int a[]){

    if(heapSize < 1){
        cout<<"Heap underflow";
        return -1;
    }

    int Max = a[1];
    a[1] = a[heapSize];
    heapSize -= 1;
    heapify(a,1,heapSize);
    return Max;
}


