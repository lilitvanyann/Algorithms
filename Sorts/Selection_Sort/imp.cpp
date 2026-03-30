#include <iostream>
#include <vector>
using namespace std;

void Selection(vector <int>&arr) {
 int n = arr.size();
 for (int i = 0; i < n - 1; ++i)
 {
  int m = i;
  for (int j = i+1; j < n; ++j)
   if (arr[j] < arr[m])
    m = j;
  swap(arr[i], arr[m]);
 }
}

int main()
{
 int n; cin >> n;
 vector <int> arr(n);

 for (int l = 0; l < n; ++l)
  cin >> arr[l];

 Selection(arr);

 for (int f = 0; f < n; ++f)
  cout << arr[f];

}
