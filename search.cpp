// Do NOT add any other includes
#include "search.h"
#include<iostream>

//converts to lowercase
char lowerchar(char c) {
    if (c >= 'A' && c <= 'Z') {                 
        return c + 32;
    }
    return c;
}

std::string lowercase(const std::string& input) {      
    std::string result;
    for (char c : input) {
        result += lowerchar(c);
    }
    
    return result;//this converts the given input sentence in lower case
}

//constructor of sentencellnode
sentencellnode::sentencellnode(int b_code, int pg, int para, int s_no,string sen){
    book_code = b_code;
    page = pg;
    paragraph = para;
    sentence_no = s_no;
    sentence=sen;
}

//constructor of sentencell
sentencell::sentencell(){
    senhead=NULL;
}

//destructor of sentencell
sentencell::~sentencell(){
    while (senhead) {
        sentencellnode* temp = senhead;
        senhead = senhead->next;
        delete temp;
    }
    senhead = NULL;
}

//constructor of offsetdll
offsetdll:: offsetdll(){
    offhead=NULL;
}

//destructor of offsetdll
offsetdll::~offsetdll(){
    while (offhead) {
        Node* temp = offhead;
        offhead = offhead->right;
        delete temp;
    }
    offhead = NULL;
}

//get head of sentencell
sentencellnode* sentencell::getheadsentence(){
    return senhead;
}

//get head of offsetdll
Node* offsetdll::getheadoffset(){
    return offhead;
}

//insert in beginning of sentencell
sentencellnode* sentencell::sllinsertb(sentencellnode* head, int b_code, int pg, int para, int s_no,string sentence){
    sentencellnode* nayanode= new sentencellnode(b_code,pg,para,s_no,sentence);
    if(head==NULL){
        head=nayanode;
        return head;
    }
    else{
        nayanode->next=head;
        head=nayanode;
        return head;
    }
}

//insert in beginning of offsetdll
Node* offsetdll::dllinsertb(Node* head, int b_code, int pg, int para, int s_no, int off ){
    Node* nayanode=new Node(b_code,pg,para,s_no,off);
    if(head==NULL){
        head=nayanode;
        return head;
    }
    else{
        nayanode->right=head;
        head->left=nayanode;
        head=nayanode;
        return head;
    }
}

// Function to build kmp table
std::vector<int> buildKMPtable(const std::string &pattern){
    int size=pattern.size();
    std::vector<int>kmpTable(size);
    int i=1,j=0;
    while(i<size){
        if(pattern[i]==pattern[j]){
            kmpTable[i]=j+1;
            j++;
            i++;
        }
        if(pattern[i]!=pattern[j]){
            if(j==0){
                kmpTable[i]=0;
                i++;
            }
            if(j!=0){
                j=kmpTable[j-1];

            }
        }

    }
    return kmpTable;
}

void SearchEngine::KMPSearch(const std::string& text, const std::string& pattern,int b_code, int pg, int para, int s_no ) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> lps(m);
    lps=buildKMPtable(pattern);
    int i = 0; 
    int j = 0; 
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            int offset=i-j;
            offhead=dllinsertb(getheadoffset(),b_code,pg,para,s_no,offset);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

SearchEngine::SearchEngine(){
    // Implement your function here  
}

SearchEngine::~SearchEngine(){
    // Implement your function here  
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    string result=lowercase(sentence);
    senhead=sllinsertb(getheadsentence(), book_code,page,paragraph,sentence_no,result);
    return;
}

Node* SearchEngine::search(string pattern, int& n_matches){
    offhead =NULL;
    sentencellnode* temp=getheadsentence();
    while(temp->next!=NULL){
        KMPSearch(temp->sentence,pattern, temp->book_code,temp->page,temp->paragraph,temp->sentence_no);
        temp=temp->next;
    }
    Node* temp2=getheadoffset();
    if(temp2==NULL){
        n_matches=0;
        return getheadoffset();
    }
    n_matches=1;
    while(temp2->right!=NULL){
        n_matches++;
        temp2=temp2->right;
    }
    return getheadoffset();
}
