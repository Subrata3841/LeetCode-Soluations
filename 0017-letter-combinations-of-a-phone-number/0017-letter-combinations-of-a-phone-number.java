// class Solution {
//     public List<String> letterCombinations(String digits) {
//         if (digits.isEmpty()) return new ArrayList<>();  
//         return padMap("", digits);
//     }
//     private ArrayList<String> padMap(String p, String unprocess){
//         if(unprocess.isEmpty()){
//             ArrayList<String> list = new ArrayList<>();
//             list.add(p);
//             return list;
//         }
//         int digit = unprocess.charAt(0) - '0';
//         ArrayList<String> list = new ArrayList<>();

//         for(int i=(digit - 1)* 3; i< digit*3;i++){
//             char ch = (char) ('a' + i);
//             list.addAll(padMap(p + ch, unprocess.substring(1)));
//         }
//         return list;
//     }
// }


class Solution {
    public List<String> letterCombinations(String digits) {
        // If the input is empty, immediately return an empty answer array
        if (digits.length() == 0) {
            return new ArrayList<>();
        }

        // Mapping the digits to their corresponding letters
        String[] mapping = new String[]{
            "",    // 0
            "",    // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };

        
        List<String> result = new ArrayList<>();
        backtrack(result, mapping, digits, 0, new StringBuilder());
        return result;
    }

    // Use backtrack function to generate all possible combinations
    private void backtrack(List<String> res, String[] mapping, String digits, int index, StringBuilder combination){
        if(index == digits.length()){
            res.add(combination.toString());
            return;
        }
        int digit = digits.charAt(index) - '0';
        String letters = mapping[digit];

        for(char letter: letters.toCharArray()){
            combination.append(letter);
            backtrack(res, mapping, digits, index + 1, combination);
            combination.deleteCharAt(combination.length() - 1);
        }
    }
   
}