#include <iostream>
using namespace std;

struct data{
    int index;
    int info;
};

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
            } else {
                if(calculated_data[j] > calculated_data[i])
                    calculated_data[i] = calculated_data[j];
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

    cout<<n - largest_seq_dp(arr, n)<<endl;

    return 0;
}
