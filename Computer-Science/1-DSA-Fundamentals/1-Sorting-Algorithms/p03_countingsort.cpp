#include <iostream>
#include <vector>

using namespace std;

/* 
Counting sort is a sorting technique which works best when applied across data along a smaller range.
*/


void print(vector <int>a) {
   cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++)
   cout << a[i] << ' ';
}


vector<int> countingsort(vector<int> arr){
    //first find the maximum and minimum element of a vector

    int min = arr[0],max = arr[0];

    for(int i{1}; i < arr.size(); i++){
        if (min > arr[i]){
            min = arr[i];
        }
        else if (max < arr[i]){
            max = arr[i];
        }
    }
    //calculating the range of the data
    int range = max - min;

    //creating a vector of zeroes with size equal to the range + 1
    vector<int> frequency(range+1, 0);
    
    //looping through the initial array and saving the frequency of an element with the correct index
    for(int j{0}; j < arr.size(); j++){
        int index = arr[j] - min;
        frequency[index] += 1;                
    }
    
    //creating a new vector and storing the non-zero values of elements from the frequency vector to the new vector
    vector<int> new_vector;
    for(int k{0}; k < frequency.size(); k++)
        if (frequency[k]!=0){
            for (int i{0}; i < frequency[k]; i++){
                int ele = min + k;
                new_vector.push_back(ele);
            }
        }
        
    return new_vector; 

}

//MAIN function
int main() {
    int n = 0;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    vector<int> input;
    
    cout<<"Enter integers greater than zero"<<endl;

    for (int i{0};i<n;i++){
        int temp;
        cin>>temp;
        input.push_back(temp);
    }
   
    print(countingsort(input));

    return 0;

}
