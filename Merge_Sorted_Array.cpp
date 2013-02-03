class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int temp[m+n+1];
        int left_counter, right_counter, temp_counter;
        
        left_counter = right_counter = 0;
        temp_counter = 0;
        
        while (left_counter < m && right_counter < n)
        {
            if(A[left_counter] <= B[right_counter])
            {
                temp[temp_counter] = A[left_counter];
                left_counter++;
                temp_counter++;
            }
            else
            {
                temp[temp_counter] = B[right_counter];
                right_counter++;
                temp_counter++;                
            }
        }
        
        while(left_counter < m)
        {
            temp[temp_counter] = A[left_counter];
            temp_counter++;
            left_counter++;
        }
        while(right_counter < n)
        {
            temp[temp_counter] = B[right_counter];
            temp_counter++;
            right_counter++;
        }       
        
        for(int i = 0; i < temp_counter; i++)
            A[i] = temp[i];
    }
};
