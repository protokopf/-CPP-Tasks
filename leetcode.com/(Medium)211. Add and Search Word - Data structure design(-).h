#include <string>
#include <vector>


using namespace std;

/*Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.*/

class WordDictionary {

	vector<string> words;

	bool findParrentInWord(string patt, string word)
	{
		for (int i = 0; i < word.size(); ++i)
		{
			if (word[i] == patt[0] || patt[i] == '.')
			{
				bool br = false;
				for (int j = 1; j < patt.size(); ++j)
					if ((word[i + j] != patt[i + j]) && patt[i + j] != '.')
					{
						br = true;
						break;
					}
				if (br) continue;
				return true;
			}
		}
		return false;
	}

public:
	// Adds a word into the data structure.
	void addWord(string word) {
		words.push_back(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) 
	{
		for (auto w : words)
			if (findParrentInWord(word, w))
				return true;
		return false;
	}
};