import Foundation
 
/*

 Given an array of numbers and target, return indices of the two numbers such that they add up to target.

 https://leetcode.com/problems/two-sum/

*/

var arrayOfNumbers = [42, 5, 11, 7, 2, 4]
let sumOfNumbers = 16

// Simple solution using loop
func solutionUsingLoop() {
    for i in 0..<(arrayOfNumbers.count - 1) {
        for j in (i+1)..<(arrayOfNumbers.count) where (sumOfNumbers == (arrayOfNumbers[i] + arrayOfNumbers[j])) {
            print(arrayOfNumbers[i], arrayOfNumbers[j])
        }
    }
}

/// Two pointer solution
func solutionUsingTowPointer() {
    arrayOfNumbers.sort()
    print(arrayOfNumbers)
    var l = 0
    var r = (arrayOfNumbers.count - 1)
    while (l < r) {
        if (arrayOfNumbers[l] + arrayOfNumbers[r] == sumOfNumbers) {
            print(arrayOfNumbers[l], arrayOfNumbers[r])
            break
        } else if (arrayOfNumbers[l] + arrayOfNumbers[r] < sumOfNumbers) {
            l+=1
        } else {
            r-=1
        }
    }
}

/// Hashing method
func solutionUsingHashing() {
    print(arrayOfNumbers)
    var setData = Set<Int>()
    for i in 0..<(arrayOfNumbers.count - 1) {
        let temp = sumOfNumbers - arrayOfNumbers[i]
        if (setData.contains(temp)) {
            print(arrayOfNumbers[i] , temp)
        }
        setData.insert(arrayOfNumbers[i])
    }
}

solutionUsingLoop()
solutionUsingTowPointer()
solutionUsingHashing()

