// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class TrieNode{
    public:
    bool isEndofWord;
    char character;
    int count;
    TrieNode* children[55];
    TrieNode();
    ~TrieNode();
};

class Dict {
private:
    TrieNode* root;
    // You can add attributes/helper functions here

public: 
    void printDFS (TrieNode* root,std::string& word ,std::ofstream& out);
    TrieNode* getcount(string word);
    TrieNode* insertintotrie(string word);
    TrieNode* getroot();
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};