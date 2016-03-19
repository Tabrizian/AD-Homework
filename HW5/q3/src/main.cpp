#include <iostream>
using namespace std;

struct data{
    int width;
    int heigth;
};

int largest_seq_dp(struct data *arr, int size){
    int *calculated_data = new int[size];
    for(int i = 0; i < size; i++){
        calculated_data[i] = 1;
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            if(arr[i].width >= arr[j].width && arr[i].heigth >= arr[j].heigth){
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
        cin>>arr[i].width>>arr[i].heigth;
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
