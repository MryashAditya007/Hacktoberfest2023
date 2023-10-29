import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        int[] arrayOfNumbers = {42, 5, 11, 7, 2, 4};
        int sumOfNumbers = 16;

        // Simple solution using loops
        solutionUsingLoop(arrayOfNumbers, sumOfNumbers);

        // Two pointer solution
        solutionUsingTwoPointer(arrayOfNumbers, sumOfNumbers);

        // Hashing method
        solutionUsingHashing(arrayOfNumbers, sumOfNumbers);
    }

    // Simple solution using loops
    public static void solutionUsingLoop(int[] arrayOfNumbers, int sumOfNumbers) {
        for (int i = 0; i < arrayOfNumbers.length - 1; i++) {
            for (int j = i + 1; j < arrayOfNumbers.length; j++) {
                if (sumOfNumbers == arrayOfNumbers[i] + arrayOfNumbers[j]) {
                    System.out.println(arrayOfNumbers[i] + " " + arrayOfNumbers[j]);
                }
            }
        }
    }

    // Two pointer solution
    public static void solutionUsingTwoPointer(int[] arrayOfNumbers, int sumOfNumbers) {
        Arrays.sort(arrayOfNumbers);
        int l = 0;
        int r = arrayOfNumbers.length - 1;
        while (l < r) {
            if (arrayOfNumbers[l] + arrayOfNumbers[r] == sumOfNumbers) {
                System.out.println(arrayOfNumbers[l] + " " + arrayOfNumbers[r]);
                break;
            } else if (arrayOfNumbers[l] + arrayOfNumbers[r] < sumOfNumbers) {
                l++;
            } else {
                r--;
            }
        }
    }

    // Hashing method
    public static void solutionUsingHashing(int[] arrayOfNumbers, int sumOfNumbers) {
        Set<Integer> dataSet = new HashSet<>();
        for (int i = 0; i < arrayOfNumbers.length; i++) {
            int temp = sumOfNumbers - arrayOfNumbers[i];
            if (dataSet.contains(temp)) {
                System.out.println(arrayOfNumbers[i] + " " + temp);
            }
            dataSet.add(arrayOfNumbers[i]);
        }
    }
}
