#include <bits/stdc++.h>
using namespace std;

int main(){
    long int input;
    vector<long> nails; //vector for data nails
    vector<long> length; //vector for data after calculate the threads
    
    cin >> input;
    
    // pushing data to vector
    for(long i = 0 ; i < input ; i++){
        int t;
        cin >> t;
        nails.push_back(t);
    }
// to sort each variable, so we can do the calculation
    sort(nails.begin(), nails.end());
    
    for(long i = 0 ; i < input - 1 ; i++){
        length.push_back(nails[i+1] - nails[i]);
//        cout << length[i] << " " ;
    }
    
    if(input  > 2){
        length[1] += length[0];
       
    }
    
    for(long i = 2 ; i < input - 1 ; i++){
        length[i] += (length[i-1] < length[i-2] ? length[i-1] : length[i-2]);
//        cout << length[i] << " ";
    }

    cout << length[input-2];
    
}