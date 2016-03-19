#include <iostream>
#include <limits>
using namespace std;

int max(int num1, int num2){
    int max_num = num1;
    if(num2 > num1)
        max_num = num2;
    return max_num;
}

int largest_seq(int *arr, int index){
    if(index == 0) {
        return 1;
    }

    int current_max = 1;

    for(int i = 0;i < index; i++){
        if(arr[i] <= arr[index]){
            int number = largest_seq(arr, i);
            number++;
            if(number > current_max)
                current_max = number;
        }
    }
    return current_max;
}

int main(){

    int arr[]={3, 4, -1, 0, 6, 2, 3};

    cout<<largest_seq(arr, 6)<<endl;

    return 0;
}
