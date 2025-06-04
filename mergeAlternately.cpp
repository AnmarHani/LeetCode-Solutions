class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString = "";

        int aLength = word1.length(), bLength = word2.length();  
        int a = 0, b = 0;

        int eitherWordOneOrTwo = 1;

        while(a < aLength && b < bLength) {
            if(eitherWordOneOrTwo == 1) {
                mergedString += word1[a];
                a++;
                eitherWordOneOrTwo = 2;
            }
            else {
                mergedString += word2[b];
                b++;
                eitherWordOneOrTwo = 1;
            }
        }

        while(a < aLength) {
            mergedString += word1[a];
            a++;
        }

        while(b < bLength) {
            mergedString += word2[b];
            b++;
        }

        return mergedString;
    }
};

// string mergedString = "";

// int smallerSize =
//     word1.length() <= word2.length() ? word1.length() : word2.length();

// for (size_t i = 0; i < smallerSize; i++) {
//     mergedString += word1[i];
//     mergedString += word2[i];
// }

// if (word2.length() > word1.length())
//     mergedString +=
//         word2.substr(smallerSize); // smallerSize until end.

// else
//     mergedString += word1.substr(smallerSize);

// return mergedString;
