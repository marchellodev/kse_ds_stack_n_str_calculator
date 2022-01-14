#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int prices[] = {40, 30, 50};

// int adding(int x[]) {
//     int to_pay = 0;
//     for (int i = 0; i<sizeof(x) ; i++) {
//         to_pay += x[i];
//     }
//     return to_pay;
// }

// using accumulate, we may calc. a sum of an array
    int total = accumulate(begin(prices), end(prices), 0, plus<int>());

    cout << total << endl;
}