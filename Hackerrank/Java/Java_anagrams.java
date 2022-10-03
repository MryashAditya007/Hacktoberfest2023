import java.util.Scanner;

// https://www.hackerrank.com/challenges/java-anagrams/problem?isFullScreen=true

public class Java_anagrams {

    static boolean isAnagram(String a, String b) {
      //if length is same perform the check
        if(a.length() == b.length()){
            int[] a1 = new int[256];
            int[] a2 = new int[256];
            for (int i = 0; i < a.length(); i++) {
              //taking ASCII value of char
                a1[(int) a.toLowerCase().charAt(i)] += 1;
                a2[(int) b.toLowerCase().charAt(i)] += 1;
            }
            for (int i = 0; i < 256; i++) {
                if (a1[i] != a2[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}