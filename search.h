// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class sentencellnode{
public: 
    sentencellnode* next;

    int book_code;
    int page;
    int paragraph;
    int sentence_no;
    string sentence;

    sentencellnode(int b_code, int pg, int para, int s_no,string sentence);
};

class sentencell{
    public:
    sentencell();
    ~sentencell();
    sentencellnode* senhead;

    sentencellnode* getheadsentence();
    sentencellnode* sllinsertb(sentencellnode* head,int b_code, int pg, int para, int s_no,string sentence);
}; 

class offsetdll{
    public:
    Node* offhead;
    offsetdll();
    ~offsetdll();
    Node* getheadoffset();
    Node* dllinsertb(Node* head,int b_code, int pg, int para, int s_no, int off);
};

class SearchEngine:public offsetdll,public sentencell {
private:

    // You can add attributes/helper functions here

public: 
    void KMPSearch(const std::string& text, const std::string& pattern,int b_code, int pg, int para, int s_no );
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
};