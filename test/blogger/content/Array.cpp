// Array

#include<iostream>
#include<stdio.h>
int main()
{	int arr[] = {1,2,3,4,5}
	cout << *(arr+2);
	return 0;
}

// Pointer Implmentation
int main()
{	
	int *ptr = new int[5];
	ptr[0]=1, ptr[1]=2, ptr[2]=3;
	cout << *(arr+2);
	return 0;
}


 /* 

 Array Advantage 
 	- Cache Friendliness
 	- Random Access
 		Both of these are contingous memory location of elements


 Disadvantage
 	- Insertion and Deletion is expensive
 	- search is expensive if not sorted
 	- These Operation takes O(n) time.
 	- wastage of space- Because we need to preallocate memory.
 		Even with Vector. array list etc, as they too pre-allocate memory


Operations
	Search -> Sorted O(log n)
	Insert  O(n)
	Delete  O(n)
	Reverse  O(n)
	Rotate  O(n)
	Merge.  O(n)
*/
// Reverse 

#include<iostream>
#include<stdio.h>

void reverse(int arr[], int n){
    int l=0, r = n-1;
    while (l<r){
        std::swap(arr[l], arr[r]);
        l++;
        r--;
    }
    std::cout << arr[0];
}
int main(){
    int arr[]= {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, n);
    return 0;
}


/*
	Given an array and an number d, rotate the array counter clock wise
*/

void rotate(int arr[], int n, int d){
	int temp[d];
	for(int i=0; i<d;++i)
		temp[i]=arr[i];
	for(int i=d; i<n;i++){
		arr[i-d] = arr[i];
	}
	for(int j=0; i<d;j++){
		arr[j+n-d] = arr[i];
	}
}

Time Complexity -> O(n);

---- Using Reversal
void rotate(int arr[], int n, int d){
	reverse(arr, 0, d-1);
	reverse(arr, d-1, n-1);
	reverse(arr, 0, n-1);
}

// Binary Search --> Return -1 if not present, if present return index



#include<iostream>
#include<stdio.h>

int binary_search(int arr[], int start, int end, int n){
    int mid = (start+end)/2;
    std::cout<<"\n"<< mid << "\n mid value =" << arr[mid] << "\n";
    if (start > end)
        return -1;
    if (arr[mid] == n){
        std::cout<< "amar";
        return mid;
    }
    if (n < arr[mid]){
        std::cout<< "mid is less";
        return binary_search(arr, 0, mid-1, n);
    }
    else if( n > arr[mid]){
        std::cout<< "mid is more";
        return binary_search(arr, mid+1, end, n);
    }
    return -1;
}
int main(){
    int arr[]= {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    return binary_search(arr, 0, n, 9);
}




/*
	Given sorted array, with repeated elements, and number of x, count the number of occurences of x in sorted array
	https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/


	lower_bound() -> Returns iteration(in case of SR container likle versio set) to the first element that is greater than or equal to the passed element
	in case of C Style array, it returns pointers if all elements are smaller, then ...


	upper bound() => iterator to the first greater element.
*/

int count(int arr[], int n){
	int *low = lower_bound(arr, arr+n, x);
	// OT handle case {1,1,3 -> All Elements are smaller}
	if((low==arr+n) ||
	 arr[low] !=x) // TO handle case {1,3,4} where there is greater element but no equal
		return 0;
	int *high = upper_bound(arr, arr+n, x);
		return high-low;
}

/*
	Given a sorted and roated array, (rotated by some point), find elements find the index at which element is present else return -1

	https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

	in log(n)
*/


SORTING ALGO
	- Counting Sort ( Study at Home)
	- Buble sort
		-> Compare Adjacenet element and swap
		-> O(n^2)
		-> Only Compares Adjacent Elements on Worst case. 
		-> Best case based on Implementation min O(n)
		-> Best case for Sorted Array
	- Insertion Sort
		-> O(n^2) worst case
		-> Commons used by humans for manual Purpose
		-> Best for small Array
	- selection sort
		-> O(n^2)
		-> Does min swaps compared to popular algo
	- quick sort
		-> Worst Case which array is sorted
		-> O(n^2)
		-> Avg is O(nlogn)
		-> works practically well die to cache Friendliness
		-> worst case happen when a corner elelment is aleays picked as PIVOT
		-> Divide and Conquer
	- merge sort
		-> Space Required
		-> Used in External Sorting
		-> Works in O(n log n)
		-> Divide and Conquer




-------------- Questions -------


int square_root(int l, int r, int n){
    if ((n==0) || (n==1))
        return n;
    int mid = (l+r)/2;
    std::cout << mid << "\n";
    if((mid*mid == n) || (mid * mid < n && (mid+1 * mid+1) > n))
        return mid;
    if(mid*mid < n){
        return square_root(mid+1, r, n);
    } else {
        return square_root(1, mid-1, n);
    }
    
}




/*
Find the row with max. number of 1s

input {
		{0,0,0,1},
		{0,1,1,1},
		{1,1,1,1},
		{0,0,0,0}
	  }
*/
int max = 0, result = 0;
for(int i=0; i<row_max; ++i){
	int count = first_count_of_1s(arr, 0, C-1);
	if (count > max){
		max= count;
		result = i;
	}
}

int first_count_of_1s(arr, int l, int r){
	int mid = (l+r)/2;
	if ((mid==0 || arr[mid-0) && arr[mid] == 1)
		return mid;
	else if (arr[mid] ==0)
		return first_count_of_1s(arr, mid+1, r)
	else
		return first_count_of_1s(arr, l, mid-1)
	end
}


Other Solution ->
int row_with_max_1s_new(int arr[], int R, int C){
	int max_row_index = 0;
	int j = first_count_of_1s(arr[0], 0, C-1);
	if(j==-1)
		j = C-1;

	for(int i=1; i <R;++i){
		while(j>=0 && arr[i][j] == 1){
			j=j-1;
			max_row_index = 1;
		}
	}
	return max_row_index;
}


/*
Guess the number puzzple. System gives range of numbers like 4..34
You need to use min. times of attempts to find the number.

Ans: Binary Search
*/




/*

AGGRCOW - Aggresive Cow

int positions[5] = {1,4,3,8,9}

int n=5; of of stalls
int c = 3; // No. of Cows

*/


int is_possible(int distance, int positions[], int n, int c){
	int cows = 1;
	int current_pos = positions[0];
	for(int i=1; i<n; ++i){
		if(positions[i] - current_pos >= distance){
			current_pos = positions[i];
			cows ++;
			if cow==c
				return 1;
		}
	}
	return 0;
}

//We can select distance with Binary Search
int find_largent_min_dist(int positions[], int n, int c){
	int first=0;
	int last=positions[n-1];
	int ans=-1;

	while(last > first){
		int mid=(first+last)/2;
		if(is_possible(mid, positions, n,c) == 1){
			ans = max(ans, mid);
		} else
		last = mid ;
	}
}