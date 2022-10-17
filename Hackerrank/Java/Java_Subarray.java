/*
  Problem link: https://www.hackerrank.com/challenges/java-negative-subarray/problem

  Problem Statement: Given an array of  integers, find and print its number of negative subarrays on a new line.
   The sum of an array is the total sum of its elements.
    An array's sum is negative if the total sum of its elements is negative.
    An array's sum is positive if the total sum of its elements is positive.


  Input Format

  The first line contains a single integer, n, denoting the length of array .
  The second line contains 'n' space-separated integers describing each respective element, Ai, in array A.

  Constraints
   * 1 <= n <= 100
   * -ve 10^4 <= Ai <= +ve 10^4

  Output Format
  Print the number of subarrays of A having negative sums.
  
*/

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

Code Approach:
  1. Create prefixSum array for input array.
      if A = [1,2,3,4,5]
      then, prefixSum of A = [1,3,6,10,15]
  2. for each subarray, A[i-j], find the sum of the subarray.
      formula to be used to calculate the sum of subarray, A[i j]:
         prefixSum[j] - prefixSum[i-1].
           
  3. if sum < 0, increament count;

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

Code:

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();       //len of Array
        int[] arr = new int[n];
            
        //taking input
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        
        //creating a prefixSum array
        int[] prefixSum = new int[n];
        prefixSum[0] = arr[0];        
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){                   //i is the starting index of subarray.
            int sum = 0;
            for(int j=i;j<n;j++){               //j is the ending index of subarray.
                if(i==0){                       //edge case, when i = 0, i-1 == -ve integer, which is not an index of array. Hence handling it.
                    sum = prefixSum[j];         //calculating the each subarray sum in if-ese block
                }
                else{
                    sum = prefixSum[j] - prefixSum[i-1];
                }
                
                if(sum < 0){
                    cnt++;
                }
            }
        }
        
        System.out.println(cnt);
        
        
    }
}
