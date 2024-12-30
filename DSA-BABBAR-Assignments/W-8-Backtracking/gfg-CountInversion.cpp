// Count Inversions
// Difficulty: MediumAccuracy: 16.93%Submissions: 610K+Points: 4
// Given an array of integers arr[]. Find the Inversion Count in the array.
// Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
// Input: arr[] = [2, 3, 4, 5, 6]
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.
// Input: arr[] = [10, 10, 10]
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104


//{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;


// } Driver Code Ends
class Solution {
  public:
     long mergeSort(vector<int>&arr, vector<int>&temp, int start , int end){
         if(start >= end) return 0;
         int mid = start + (end - start)/2;
         long c = 0;
         c += mergeSort(arr, temp, start, mid);
         c += mergeSort(arr, temp, mid+1, end);
         c += merge(arr, temp, start, mid, end);
         return  c;
     }
     
     long merge(vector<int>&arr, vector<int>&temp, int start, int mid, int end){
         int i = start, j = mid + 1, k =start;
         long c = 0;
         while(i<=mid && j<=end){
             if(arr[i] <= arr[j]){
                 temp[k++] = arr[i++];
             }else{
                 temp[k++] = arr[j++];
                 c += mid - i + 1;
             }
         }
     
     
     while(i <= mid)
         temp[k++] = arr[i++];
         while(j <= end)
             temp[k++] = arr[j++];
             
             while(start <= end){
                 arr[start] = temp[start];               //actual array me insert kardo
                 start++; 
             }
         
         return c;
     }
     
     
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        long c = 0;            //Inversion count
        vector<int>temp(arr.size(), 0);
        c = mergeSort(arr, temp, 0, arr.size() - 1);
        return c;
    }
};

//{ Driver Code Starts.

// int main() {

//     int T;
//     cin >> T;
//     cin.ignore();
//     while (T--) {
//         int n;
//         vector<int> a;
//         string input;
//         getline(cin, input);
//         stringstream ss(input);
//         int num;
//         while (ss >> num)
//             a.push_back(num);
//         Solution obj;
//         cout << obj.inversionCount(a) << endl;
//         cout << "~" << endl;
//     }

//     return 0;
// }

// } Driver Code Ends