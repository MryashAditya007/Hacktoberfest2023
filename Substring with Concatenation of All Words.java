import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SubstringConcatenation {

    public static List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) {
            return result;
        }

        int wordLength = words[0].length();
        int totalWords = words.length;
        int windowSize = wordLength * totalWords;
        Map<String, Integer> wordCountMap = new HashMap<>();

        for (String word : words) {
            wordCountMap.put(word, wordCountMap.getOrDefault(word, 0) + 1);
        }

        for (int i = 0; i < wordLength; i++) {
            int left = i;
            int right = i;
            Map<String, Integer> currentWordCountMap = new HashMap<>();

            while (right + wordLength <= s.length()) {
                String word = s.substring(right, right + wordLength);
                right += wordLength;

                if (wordCountMap.containsKey(word)) {
                    currentWordCountMap.put(word, currentWordCountMap.getOrDefault(word, 0) + 1);

                    while (currentWordCountMap.get(word) > wordCountMap.get(word)) {
                        String leftWord = s.substring(left, left + wordLength);
                        currentWordCountMap.put(leftWord, currentWordCountMap.get(leftWord) - 1);
                        left += wordLength;
                    }

                    if (right - left == windowSize) {
                        result.add(left);
                        String leftWord = s.substring(left, left + wordLength);
                        currentWordCountMap.put(leftWord, currentWordCountMap.get(leftWord) - 1);
                        left += wordLength;
                    }
                } else {
                    currentWordCountMap.clear();
                    left = right;
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        String s = "barfoothefoobarman";
        String[] words = {"foo", "bar"};
        List<Integer> result = findSubstring(s, words);

        System.out.println("Indices of substrings: " + result);
    }
}
