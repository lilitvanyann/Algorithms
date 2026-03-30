#include <iostream>
using namespace std;

void bubble(int arr[],int n){
    
    int temp;
    for(int i=0;i<n-1;++i)  //1
    {    
        bool swapped=false;
            for(int j=1;j<n-i;++j)  //2

                if(arr[j]<arr[j-1])
                {   
                    temp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;
                    swapped=true;
                }
                
            if(!swapped)  //3
            break;      
            
    }
    
    for(int k=0;k<n;++k)
    cout<<arr[k];
}

int main(){
    int arr[10];
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    cin>>arr[i];
    bubble(arr,n);
}
