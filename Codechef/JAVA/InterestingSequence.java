import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc = new Scanner(System.in);
	    int t = sc.nextInt();
	    while(t-->0){
	        int k = sc.nextInt();
	        int count = 0;
	        while(k%2==0){
	                count++;
	                k=k/2;
	        }
	            System.out.println(count);
	    }
	}
}
