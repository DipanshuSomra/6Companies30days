// You are playing the Bulls and Cows game with your friend.

// You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
// Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

// The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

 

// Example 1:

// Input: secret = "1807", guess = "7810"
// Output: "1A3B"
// Explanation: Bulls are connected with a '|' and cows are underlined:
// "1807"
//   |
// "7810"


class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        map<char,int> mp;
        string ans = "";
        int n = secret.size();

      //if same string found on the same position count bulls++
      //else map secret code++
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
            else
                mp[secret[i]]++;
        
        }

      //now check whether the guess code is found in the map if found cows++ and map--
      //before that check whether they are coming on same posi or not
        for(int i = 0; i < n; i++){
            if(secret[i] != guess[i]){
                if(mp[guess[i]] > 0){
                    cows++;
                    mp[guess[i]]--;
                }
            }
        }
        ans = to_string(bulls) + "A" + to_string(cows)+ "B";
        return ans;

    }
};
