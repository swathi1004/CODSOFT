#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter a and b : ";
    cin>>a>>b;
    char op;
    cout<<"enter op (+,-,*,/): ";
    cin>>op;
    switch(op)
    {
        case '+':
        cout<<"sum of a and b is:"<<a+b<<endl;
        break;
        case '-':
        cout<<"diff of a and b is:"<<a-b<<endl;
        break;
        case '*':
        cout<<"mul of a and b is:"<<a*b<<endl;
        break;
        case '/':
       if (b != 0)
       {
          cout << "Division of a and b is: " << static_cast<double>(a) / b << endl;
       } else
       {
          cout << "Division by zero is not allowed." << endl;
       }
        break;
        defualt:
        cout<<"invalid output";
    }
    return 0;
}
