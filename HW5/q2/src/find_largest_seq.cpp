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

int data_compare(void *i1,void *i2){
    struct data a = *((struct data *)i1);
    struct data b = *((struct data *)i2);

    return (a.info > b.info) ? 1 : (a.info == b.info) ? 0 : -1;
}

int largest_seq_recursive(struct data *arr, int index){
    if(index == 0) {
        return 1;
    }

    int current_max = 1;

    for(int i = 0;i < index; i++){
        if(arr[i].info <= arr[index].info){
            int number = largest_seq_recursive(arr, i);
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

    struct data arr[]={{1,6}, {2,5}, {3,4}};

    cout<<largest_seq_recursive(arr, 6)<<endl;

    return 0;
}
