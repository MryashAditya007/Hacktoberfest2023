#!/bin/python3

import math
import os
import random
import re
import sys

#
# This solution uses python's built-in sum function.
# https://docs.python.org/3/library/functions.html?highlight=sum#sum
#

def simpleArraySum(ar):
    return sum(ar)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ar_count = int(input().strip())

    ar = list(map(int, input().rstrip().split()))

    result = simpleArraySum(ar)

    fptr.write(str(result) + '\n')

    fptr.close()
