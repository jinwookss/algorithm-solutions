#include <iostream>
#include <map>

using namespace std;

int main() {

    int M, N;
    cin >> N >> M;

    int eachMin = 1001;
    int bundleMin = 1001;
    for (int i=0; i<M; i++) {
        int each, bundle;
        cin >> bundle >> each;

        if (each < eachMin) {
            eachMin = each;
        }

        if (bundle < bundleMin) {
            bundleMin = bundle;
        }
    }

    int price;
    if (N < 6) {
        price = eachMin * N < bundleMin ? eachMin * N : bundleMin;
    } else {
        if (eachMin * 6 <= bundleMin) {
            price = N * eachMin;
        } else {
            price = (N / 6) * bundleMin;
            if (N % 6 * eachMin < bundleMin) {
                price += N % 6 * eachMin;
            } else {
                price += bundleMin;
            }
        }
    }

    cout << price << endl;
   
    return 0;
}