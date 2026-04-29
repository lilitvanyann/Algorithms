
#include <iostream>
#include <vector>
using namespace std;

class MyStack {
private:
    int Max_size;
    vector<int> stack;
    
public:
    MyStack(int max_s) {
        Max_size = max_s;
    }   
    
    bool empty(){
        return stack.empty();
    }
    
    int size(){
        return stack.size();
    }
    
    void push(int val){
        if(stack.size()>=Max_size){
            cout<<"Stack Overflow\n";
            return;
        }
        else
            { 
                cout<<" element added : "<<val<<endl;
                stack.push_back(val);
            }
    }
    
    void pop(){
        if(empty()){
            cout<<"Stack Underflow\n";
        }else{
            int val=stack.back();
            stack.pop_back();
            cout<<" element deleted : "<<val<<endl;
        }
    }
    
    void TopElement(){
        if(empty()){
            cout<<"stack is empty"<<endl;
        }else{
            int val=stack.back();
            cout<<"The top value is : "<<val<<endl;
        }
        
    }
};


int main(){
MyStack Stack(5);//Max_size
Stack.push(20);
Stack.push(10);
Stack.push(5);
Stack.push(6);
Stack.push(1);
Stack.push(8);//Stack overflow
Stack.pop();
Stack.pop();

Stack.TopElement();

}
