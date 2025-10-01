class Solution {
    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return true; // An empty string is considered a valid palindrome
        }

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Move left pointer past non-alphanumeric characters
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }

            // Move right pointer past non-alphanumeric characters
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }

            // If pointers haven't crossed and both point to alphanumeric characters
            if (left < right) {
                char charLeft = Character.toLowerCase(s.charAt(left));
                char charRight = Character.toLowerCase(s.charAt(right));

                // Compare the characters
                if (charLeft != charRight) {
                    return false; // Mismatch found, not a palindrome
                }

                // Move pointers inward for the next comparison
                left++;
                right--;
            }
        }

        // If the loop completes, all alphanumeric characters matched
        return true;
    }
}