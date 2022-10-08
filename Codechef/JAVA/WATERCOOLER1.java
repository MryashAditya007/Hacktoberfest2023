/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		     Scanner sc=new Scanner(System.in);
	       int T=sc.nextInt(),X,Y,M;
			for(int i=1;i<=T;i++){
			    X=sc.nextInt();
			    Y=sc.nextInt();
			    M=sc.nextInt();
			    if(X*M<Y)
			        System.out.println("YES");
			    else
			        System.out.println("NO");
			}
	}
}
