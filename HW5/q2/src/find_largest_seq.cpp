#include <iostream>
#include <limits>
#include <cstdio>
using namespace std;

struct data{
    int index;
    int info;
};

int max(int num1, int num2){
    int max_num = num1;
    if(num2 > num1)
        max_num = num2;
    return max_num;
}

int data_compare(struct data data1,struct data data2){
    if()
}

int largest_seq_recursive(struct data *arr, int index){
    if(index == 0) {
        return 1;
    }

    int current_max = 1;

    for(int i = 0;i < index; i++){
        if(arr[i].info <= arr[index].info){
            int number = largest_seq(arr, i);
            number++;
            if(number > current_max)
                current_max = number;
        }
    }
    return current_max;
}

int largest_seq_dp(struct data *arr, int size){

}

int main(){

    int arr[]={3, 4, -1, 0, 6, 2, 3};

    cout<<largest_seq(arr, 6)<<endl;

    return 0;
}
