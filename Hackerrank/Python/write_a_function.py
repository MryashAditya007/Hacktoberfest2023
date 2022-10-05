# https://www.hackerrank.com/challenges/write-a-function/problem
def is_leap(year):
    if (year%4==0) and (year%100!=0) or (year%400==0):
        return True
    else:
        return False
