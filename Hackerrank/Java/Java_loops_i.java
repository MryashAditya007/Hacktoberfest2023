import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

// https://www.hackerrank.com/challenges/java-loops-i/problem?isFullScreen=true

public class Java_loops_i {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bufferedReader.readLine().trim());
        multiples(N);
        bufferedReader.close();
    }
    static void multiples(int x){
        for(int i=1; i<=10; i++){
            System.out.println(x +" x " +i +" = " +(x*i));
        }
    }
}