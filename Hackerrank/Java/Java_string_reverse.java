import java.io.*;
import java.util.*;

//https://www.hackerrank.com/challenges/java-string-reverse/problem?isFullScreen=true

public class Java_string_reverse {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        isPalindrome(A);   
        if(isPalindrome(A)){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
    
    static boolean isPalindrome(String str){
      //initialize an empty string
        String reverse = "";
        
        for(int i = str.length()-1; i>=0; i--){
          //last Character of str will be first Character of reverse
            reverse = reverse + str.charAt(i);
        }
        //if both str and reverse are same return true
        if(str.toLowerCase().equals(reverse.toLowerCase())){
            return true;
        }
        
        return false;
    }
}



