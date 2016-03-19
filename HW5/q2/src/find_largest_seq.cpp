#include <iostream>
#include <limits>
#include <cstdio>
#include <cstdlib>
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

int data_compare(const void *i1,const void *i2){
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
    int *calculated_data = new int[size];
    for(int i = 0; i < size; i++){
        calculated_data[i] = 1;
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            if(arr[i].info >= arr[j].info){
                int temp = calculated_data[j] + 1;
                if(temp > calculated_data[i]){
                    calculated_data[i] = temp;
                }
            }
        }
    }

    return calculated_data[size - 1];
}

void get_input(struct data *arr, int size){
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i].index>>arr[i].info;
    }
}

int main(){

    int n;

    cin>>n;
    struct data *arr = new struct data[n];
    get_input(arr,n);

    qsort(arr, n, sizeof(struct data),data_compare);
    cout<<n - largest_seq_dp(arr, n)<<endl;

    return 0;
}
