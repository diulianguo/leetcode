#include<iostream>
#include<set>
using namespace std;

class WordDictionary {
private:
    string dic;
public:

    // Adds a word into the data structure.
    void addWord(string word)
    {
        dic += word;
    }

    bool find(string t)
    {
        int len = t.size();
        for (int i = 0; i<dic.size(); i++){
            if (dic.substr(i, len) == t)
                return true;
        }
        return false;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word)
    {
        set<char> wordmap;
        int len = word.size();
        for (int i = 0; i < len; i++){
            if (!wordmap.count(word[i])){
                wordmap.insert(word[i]);
            }
        }
        for (int i = 0; i < len; i++){
            if (word[i] == '.'){
                for (auto it = wordmap.begin(); it != wordmap.end(); it++){
                    
                }
            }
        }
    }
};

//int main()
//{
//     WordDictionary wordDictionary;
//     wordDictionary.addWord("word");
//     cout << wordDictionary.search("wor") << endl;
//     return 0;
//}