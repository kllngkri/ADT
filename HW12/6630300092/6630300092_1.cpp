#include<iostream>
using namespace std;


int heapSize = 10;
int a[16];


void buildHeap(int a[]);
void heapify(int a[],int i);
void exchange(int &x,int &y);
void printData(int a[]);

int getLeft(int i);
int getRight(int i);
int getParent(int i);

int main(){

    cout<<"input : ";

    for(int i = 1;i<=10;i++){
        cin>>a[i];
    }

    buildHeap(a);

    cout<<"output : ";
    printData(a);


    return 0;
}

void printData(int a[]){
    for(int i = 1;i<=10;i++){
        cout<<a[i]<<" ";
    }
}

void exchange(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}

int getLeft(int i){return 2*i;}
int getRight(int i){return 2*i+1;}
int getParent(int i){return i/2;}

void buildHeap(int a[]){
    for(int i = heapSize/2;i>=1;i--){
        heapify(a,i);
    }
}
void heapify(int a[],int i){
    int left = getLeft(i);
    int right = getRight(i);
    int lagest;

    if(a[i] > a[left]){
        lagest = i;
    }else
        lagest = left;

    if(a[lagest] < a[right])
        lagest = right;

    if(lagest != i){
        exchange(a[i],a[lagest]);
        heapify(a,lagest);
    }

}

