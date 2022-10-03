import java.io.*;
import java.util.*;

// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true


public class Sparse_arrays {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        HashMap<String,Integer> hm = new HashMap<>();
        for(int i = 0; i < N; ++i) {
            String input = sc.next();
            if(hm.get(input) == null) hm.put(input,1);
            else {
                int val = hm.get(input);
                hm.put(input,++val);
            }
        }

        int Q = sc.nextInt();
        while(Q-->0) {
            String query = sc.next();
            if(hm.get(query) == null) System.out.println(0);
            else System.out.println(hm.get(query));
        }
    }
}