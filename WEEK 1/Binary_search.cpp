#include <iostream>
#include <fstream>
using namespace std;

int count=0;

bool binary_search(int *arr, int st, int en, int k){
    if(st>en){
        return false;
    }
    ++count;
    int mid = (st+en)/2;
    if(arr[mid]==k){
        return true;
    }
    if(arr[mid]<k){
        return binary_search(arr, mid+1, en, k);
    }
    else return binary_search(arr, st, mid-1, k);
}

int main(){
    fstream input;
    input.open("binary_search_input.txt", ios::in);
    if (!input) {
        cout << "error while opening";
        exit(1); 
    }
    int t, n, i, k;
    input >> t;
    fstream output;
    output.open("binary_search_output.txt", ios::out);
    while(t>0){
        input >> n;
        int* arr = new int[n];
        for(i=0; i<n; ++i){
            input >> arr[i];
        }
        input >> k;
        count=0;
        bool res = binary_search(arr, 0, n-1, k);
        if(res){
            output << "Present " << count << '\n';
        }
        else{
            output << "Not Present " << ccount << '\n';
        }
        --t;
    }
    input.close();
    output.close();
    return 0;
}