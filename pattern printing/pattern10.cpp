#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "Enter the value of n"<< endl;
    cin >> n;
    for(int i=0;i< 2*n -1;i++){
        if(i<n){
            for(int j=0;j<=i;j++){
                cout << "*";
            }
            cout << endl;
        }
        else{
            for(int j=i;j<2*n-1;j++){
                cout << "*";
            }
            cout << endl;
        }
    }
}