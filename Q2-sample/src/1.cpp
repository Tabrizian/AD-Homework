#include <iostream>
using namespace std;

bool can_create_change(int money) {
    if(money == 3 || money == 5 || money == 7)
        return true;
    else if(money < 3)
        return false;
    else {
        bool can7 = can_create_change(money - 7);
        bool can5 = can_create_change(money - 5);
        bool can3 = can_create_change(money - 3);

        return can7 || can5 || can3;
    }
}

int main() {
    int money;

    cin >> money;

    can_create_change(money) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    return 0;
}
