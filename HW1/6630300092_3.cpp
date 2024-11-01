//#include <iostream>
//using namespace std;
//
//void print_array(int array[],int size)
//{
//    for(int i = 0 ; i < size;i++)
//        cout<< array[i] << " " ;
//    cout << endl;
//}
//
//int main(){
//int score[] = {10,20,30,40,50,60,70,80,90,100};
//    int start = 0;
//    int size = (sizeof(score) / sizeof(score[0]));
//    int end = size - 1;
//    int end_point = size / 2;
//    int temp;
//    cout<< "Original array : ";
//    print_array(score, size);
//    while (true){
//       temp = score[start];
//       score[start] = score[end];
//       score[end] = temp;
//       start++;
//       end--;
//        if (start == end_point || end == end_point)break;
//    }
//    cout << "Reverse array : ";
//    print_array(score, size);
//}
//
