#include <iostream>
#include <cstdlib>
using namespace std;

struct data{
    int width;
    int heigth;
};

int max(int *arr, int size){
    int current = arr[0];
    for(int i = 1; i < size ;i++){
        if(arr[i] > current)
            current = arr[i];
    }
    return current;
}

int largest_seq_dp(struct data *arr, int size){
    int *calculated_data = new int[size];
    for(int i = 0; i < size; i++){
        calculated_data[i] = 1;
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            if(arr[i].heigth >= arr[j].heigth){
                int temp = calculated_data[j] + 1;
                if(temp > calculated_data[i]){
                    calculated_data[i] = temp;
                }
            }
        }
    }

    return max(calculated_data,size);
}

void get_input(struct data *arr, int size){
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i].width>>arr[i].heigth;
    }
}

int compare_data(const void *i1, const void *i2){
    struct data a = *((struct data *) i1);
    struct data b = *((struct data *) i2);

    if(a.width > b.width)
        return 1;
    else if(a.width < b.width)
        return -1;
    else if(a.heigth > b.heigth)
        return 1;
    else if(a.heigth < b.heigth)
        return -1;
    else
        return 0;
}

int main(){

    int n;

    cin>>n;
    struct data *arr = new struct data[n];
    get_input(arr,n);
    qsort(arr, n, sizeof(struct data), compare_data);

    cout<<largest_seq_dp(arr, n)<<endl;

    return 0;
}
