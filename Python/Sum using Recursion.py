def sum(n):

   # Base Case
   if n <= 1:
       return n
   
   # Recursive Call
   else:
       return n + sum(n-1)


num = int(input("Enter a Natural Number"))
if num < 0:
   print("Please Enter a Natural Number Only")
else:
   print("The required sum is",sum(num))
