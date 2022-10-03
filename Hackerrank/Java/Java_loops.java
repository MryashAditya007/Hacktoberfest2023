import java.util.*;
import java.io.*;

// https://www.hackerrank.com/challenges/java-loops/problem?isFullScreen=true
class Java_loops{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            printSeries(a,b,n);
        }
        in.close();
    }
    static void printSeries(int a, int b, int n){
        
        int sum = a;
            for (int j = 0; j < n; j++) {
                sum += b * Math.pow(2, j);
                System.out.print(sum + " ");
            }
        System.out.println();
    }
}