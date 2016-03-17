#include <iostream>
using namespace std;

int max(int num1, int num2){
    int max_num = num1;
    if(num2 > num1)
        max_num = num2;
    return max_num;
}

int largest_seq(int *arr, int index, int &max_num){
    if(index == 0)
        return 1;

    int max_length = 1;
    int i = 0;
    int current_max = 1;
    int max_num_in_seq;

    for(i = 0;i < index; i++){
        int number = largest_seq(arr, i, max_num_in_seq);
        if(arr[index+1]>= max_num_in_seq){
            number++;
            max_num_in_seq = arr[index+1];
        }
        current_max = max(number, current_max);
    }

    max_num = max_num_in_seq;
    return current_max;
}

int main(){
    int arr[]={3, 4, -1, 0, 6, 2, 3};
    int max_num;
    cout<<largest_seq(arr, 5, max_num)<<endl;

    return 0;
}
