class Solution {
public:
    string reverseVowels(string s) {
        auto front = s.begin(), rear = s.end() - 1;        
        string Vowels = "aeiouAEIOU";
        
        while(front < rear){
            while(front < rear && Vowels.find(*front) == string::npos)
                front++;
            while(front < rear && Vowels.find(*rear) == string::npos)
                rear--;
            swap(*front++, *rear--);
        }
        
        return s;
    }
};
