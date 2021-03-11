#include <iostream>
#include <vector>

using namespace std;

/*
Selection sort is a sorting algorithm which calculates the minimum of the array from a specified index,removes it from the array
and adds it to the beginning of another array. The process is continued till all the array elements are exhausted.
*/


//function to print the elements of a vector
void printarr(vector<int> arr){
    for(int i{0};i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


//function to calculate the minimum of a vector
int min(vector<int> arr){
    int minim = arr[0];
    int ind = 0;
    for(int i{1};i<arr.size();i++){
        if (minim>arr[i]){
            minim = arr[i];
            ind = i;        
        }
    }

    return ind;
}


//selection sort function
vector<int> selectionsort(vector<int> arr){
    vector<int> sortedvec;
    int n = arr.size();

    while(n>0){

        int mins = min(arr);
        sortedvec.push_back(arr[mins]);

        arr.erase(arr.begin()+mins);
        n = arr.size();
    }

    return sortedvec;
}


int main(){
    cout<<"Selection sort"<<endl;
    cout<<"Enter the number of unsorted elements"<<endl;
    int n;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the array elements separated with spaces"<<endl;

    for(int i{0};i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    vector<int> retvec = selectionsort(arr);
    printarr(retvec);

    return 0;
}