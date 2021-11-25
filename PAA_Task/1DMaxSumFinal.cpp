#include<iostream>

using namespace std;

int MaxSum(int arr[], int size){
	
	int max_so_far = arr[0];
	int max_end_here = arr[0];
	
	for(int i = 1; i < size; i++){
		
		max_end_here = max(max_end_here + arr[i], arr[i]);
		max_so_far = max(max_so_far, max_end_here); 
	}
		return max_so_far;
}

int main(){
	int arr[] = {-2,-3, 4,-1,-2,1,5,-3};
	//int arr[] =  {-2, -3, -4, -1, -2, -1, -5, -3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << MaxSum(arr,n);
	return 0;
}

//https://backtobackswe.com/platform/content/max-contiguous-subarray-sum/solutions//





