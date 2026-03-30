#include <iostream>
#include <vector>
using namespace std;

void Insertion(vector <int>&arr) {
    int j;
    int n = arr.size();
    for (int i = 1; i < n ; ++i)
    {
        j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        
            {
                swap(arr[j], arr[j - 1]);
                j = j - 1;
            }
    }
}

int main()
{   
    int n; cin >> n;
    vector <int>arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    Insertion(arr);
    for (int m = 0; m < n; ++m)
        cout << arr[m]; 
    
}
