#include <iostream>
#include <vector>
using namespace std;

/*

Generating all possible subsets using bit representations.

Each subset of a set of n elements can be represented as a sequence of n bits, giving a total 
of 2^n - 1 possibilities. The ones in a bit sequence indicate that an element is present in a subset.



*/

void printarr2d(vector<vector<int>> arr){
	int n = arr.size();

	for(int i=0;i<n; i++){
        int m = arr[i].size();
		for(int j = 0; j<m; j++){
			cout << arr[i][j] << " ";

		}
		cout<<endl;
	}
}



int main(){
    cout << "Enter the number of elements ";
    int n; cin >> n;
    cout<<endl;
    vector<int> arr(n,0);

    cout << "Enter the elements" << endl;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> subsets;


    for(int i = 0; i < (1<<n); i++){
        // looping through all possible states of n bits
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) { // checking if the index of each bit matches the index of the current state
                temp.push_back(arr[j]);
                
            }
        }
        
        subsets.push_back(temp);
    }    


    printarr2d(subsets);



    return 0;
}

