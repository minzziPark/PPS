/*
Source: https://leetcode.com/problems/determine-if-string-halves-are-alike/

1704. Determine if String Halves Are Alike

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
Return true if a and b are alike. Otherwise, return false.

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
*/

class Solution {
public:
    bool halvesAreAlike(string s) {
		int vowel = 0;
		bool result = false;
        string a;
		string b;
		a = s.substr(0, s.length()/2);
		b = s.substr(s.length()/2, s.length());
		for(int i=0; i<a.length(); i++){
			if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U'){
				vowel++;
			}
		}
        cout << vowel << endl;
		for(int i=0; i<b.length(); i++){
			if(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u' || b[i] == 'A' || b[i] == 'E' || b[i] == 'I' || b[i] == 'O' || b[i] == 'U'){
				vowel--;
			}
		}
        cout << vowel << endl;
		if(vowel == 0) result = true;
		return result;
    }
};