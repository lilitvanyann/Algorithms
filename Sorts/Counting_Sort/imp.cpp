#include <iostream>
#include <vector>
using namespace std;

void Counting(vector <int>&arr) {
    vector <int>temp;
    int n = arr.size();
    int max = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > max)
            max = arr[i];

    vector <int>count(max+1,0);

    for (int i = 0; i < n; ++i)
        count[arr[i]]++;

    int index = 0;

    for (int i = 0; i < max+1; ++i)
        while (count[i] > 0)
        {
            arr[index] = i;
            index++;
            count[i]--;
        }
}

int main()
{
    int n; cin >> n;
    vector <int>arr(n);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    Counting(arr);

    for (int i = 0; i < n; ++i)
        cout <<arr[i];

}
