#include <iostream>
using namespace std;

int can_create_change(int money, int chosen) {
    if(money == 0)
        return 1;
    else if(money < 0)
        return 0;
    else {
        int num = 0;
        switch(chosen){
            case 7:
                num += can_create_change(money - 7, 7);
            case 5:
                num += can_create_change(money - 5, 5);
            case 3:
                num += can_create_change(money - 3, 3);
        }

        return num;
    }
}

int main() {
    int money;

    cin >> money;

    cout << can_create_change(money - 3, 3) + can_create_change(money - 5, 5)
        + can_create_change(money - 7, 7);
    return 0;
}
