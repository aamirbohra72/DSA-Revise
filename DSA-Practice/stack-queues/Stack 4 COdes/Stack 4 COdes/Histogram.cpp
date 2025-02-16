// 84. Largest Rectangle in Histogram
// Solved
// Hard
// Topics
// Companies
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:


// Input: heights = [2,4]
// Output: 4
 

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104


----------------------------------------------------------------------------------vscode code-=-------------
#include <iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        //left to right -> prev smaller
        for(int i=0; i<input.size(); i++) {
                int curr = input[i];

                //apka answer stack me 
                while(s.top() != -1 && input[s.top()] >= curr) {
                        s.pop();
                }

                //chotta element mil chuka h -> ans store
                ans[i] = s.top();

                //push krdo curr element ko
                s.push(i);
        }
        return ans;
}

vector<int> nextSmaller(vector<int> &input) {
  stack<int> s;
  s.push(-1);
  
  vector<int> ans(input.size());

  for(int i=input.size()-1; i>=0; i--) {
          int curr = input[i];

          //apka answer stack me 
          while(s.top() != -1 && input[s.top()] >= curr) {
                  s.pop();
          }

          //chotta element mil chuka h -> ans store
          ans[i] = s.top();

          //push krdo curr element ko
          s.push(i);
  }
  return ans;
}

int getRectangularAreaHistogram(vector<int> &height) {

        //step1: prevSmaller output
        vector<int> prev = prevSmallerElement(height);

        //step2: nextSmaller call
        vector<int> next = nextSmaller(height);

        int maxArea = INT_MIN;
        int size = height.size();

        for(int i=0; i<height.size(); i++) {
                int length = height[i];
                
                if(next[i] == -1) {
                        next[i] = size;
                }

                int width = next[i] - prev[i] - 1;

                int area = length * width;
                maxArea = max(maxArea, area);
        }

        return maxArea;
}

int main() {
  vector<int> v;
  v.push_back(2);
  v.push_back(1);
  v.push_back(5);
  v.push_back(6);
  v.push_back(2);
  v.push_back(3);

  cout << "Ans is: " << getRectangularAreaHistogram(v) << endl;
  return 0;
}

------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    
    vector<int>prevSmallerElement(vector<int>&input){
            stack<int>st;
            st.push(-1);
            vector<int>ans(input.size());

             for(int i =0; i< input.size(); i++){
                  int curr = input[i];

                  while(st.top() != -1 && input[st.top()] >= curr){
                    st.pop();
                  }
                  ans[i] = st.top();

                  st.push(i);
             }
             return ans;
        }

         vector<int>nextSmallerElement(vector<int>&input){
            stack<int>st;
            st.push(-1);
            vector<int>ans(input.size());
             for(int i = input.size() -1; i >= 0; i--){
                  int curr = input[i];

                  while(st.top() != -1 && input[st.top()] >= curr){
                    st.pop();
                  }
                  ans[i] = st.top();

                  st.push(i);
             }
             return ans;
        }
    
    int largestRectangleArea(vector<int>& heights) {

        vector<int>prev = prevSmallerElement(heights);
         vector<int>next = nextSmallerElement(heights);
        int maxArea = INT_MIN;
        int size = heights.size();

        for(int i = 0; i< heights.size(); i++){
            int length = heights[i];
        
         if(next[i] == -1){
            next[i] = size;
         }

        int  width = next[i] - prev[i] - 1;
        int Area = length * width;
         maxArea = max(maxArea, Area);
         
    }
        return maxArea;
    }   
};