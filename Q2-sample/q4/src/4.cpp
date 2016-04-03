#include <iostream>
using namespace std;

int max_value(int *value, int *weight, int begin, int end, int max_weight, int *mask){
    if(begin == end){
        if(weight[begin] <= max_weight && max_weight >= 0)
            return value[begin];
        else
            return 0;
    } else {
        int current_max_value = 0;
        for(int i = begin; i < end; i++){

            if(max_weight > 0) {
                int *mask2 = new int[end - begin];
                for(int j = 0;j < end -begin; j++)
                    mask2[j] = mask[j];
                int value_without = max_value(value, weight, i + 1, end, max_weight,mask2);
                int value_with = max_value(value, weight, i + 1, end, max_weight - weight[i],mask2) + value[i];

                if(value_with > current_max_value){
                    current_max_value = value_with;
                    max_weight = max_weight - weight[i];
                }

                else if(value_without > current_max_value){
                    current_max_value = value_without;
                    mask[i] = 0;
                }
            }

        }

        return current_max_value;
    }
}

int main() {

    int *value;
    int *weight;
    int *mask;

    int n;
    int max_weight;

    cin >> max_weight;
    cin >> n;

    value = new int[n];
    weight = new int[n];
    mask = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }

    for(int i = 0; i < n; i++) {
        mask[i] = 1;
    }
    cout << max_value(value, weight, 0, n, max_weight, mask) << endl;

    cout << "MASK: " << endl;
    for(int i = 0; i < n; i++) {
        if(mask[i] != 0)
            cout << i + 1 << " ";
    }
    return 0;
}
