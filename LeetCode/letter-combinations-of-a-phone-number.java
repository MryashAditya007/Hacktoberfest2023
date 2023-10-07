
/* You can find this problem on 
    https://leetcode.com/problems/letter-combinations-of-a-phone-number/ 
    */

class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if(digits.equals(""))
        return res;
        return letters(digits);
    }
    String arr[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    List<String> letters(String digits)
    {
        if(digits.length() == 0)
        {
            List<String> res = new ArrayList<>();
            res.add("");
            return res;
        }

        List<String> rems = letters(digits.substring(1));
        char c= digits.charAt(0);
        String seq = arr[c-49];
        List<String> res = new ArrayList<>();
        for(int i=0; i<seq.length(); i++)
        {
            for(String s: rems)
            {
                res.add(seq.charAt(i)+s);
            }
        }
        return res;
    }
}