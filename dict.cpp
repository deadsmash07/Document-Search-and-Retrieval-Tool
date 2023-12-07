// Do NOT add any other includes
#include "dict.h"
#include<iostream>

char lowerchar(char c) {
    if (c >= 'A' && c <= 'Z') {                 
        return c + 32;
    }
    return c;
}

bool isAlphabet(char c){        //isme lowercase hi jayega
    if(c>= 'a' && c<='z'){
        return true;
    }
    return false;
}

bool isDigit(char c){
    if(c>= '0' && c<='9'){
        return true;
    }
    return false;
}

bool isSymbol1(char c){
    if(c>= '#' && c<='&'){
        return true;
    }
    return false;
}

bool isSymbol2(char c){
    if(c== '*' || c=='+'){
        return true;
    }
    return false;
}

bool isSymbol47(char c){
    if(c=='/'){
        return true;
    }
    return false;
}

bool isSymbol92(char c){
    int asciiValue = static_cast<int>(c);
    if(asciiValue==92){
        return true;
    }
    return false;
}

bool isSymbol3(char c){
    if(c>= '<' && c<='>'){
        return true;
    }
    return false;
}

bool isSymbol4(char c){
    if(c>= '^' && c<='`'){
        return true;
    }
    return false;
}

bool isSymbol5(char c){
    if(c>= '{' && c<='~'){
        return true;
    }
    return false;
}

std::string lowercase(const std::string& input) {       //input me sentence
    std::string result;
    for (char c : input) {
        result += lowerchar(c);
    }
    
    return result;//this converts the given input sentence in lower case
}



TrieNode::TrieNode(){
    count=0;
    character = '\0'; 
    isEndofWord=false;  
    for (int i = 0; i < 55; i++){
        this->children[i] = NULL;
    }
}

TrieNode::~TrieNode(){
    for (int i = 0; i < 55; i++) {
        if (this->children[i] != nullptr) {
            delete this->children[i];
        }
    }
}

Dict::Dict(){           //is a trie
    root=NULL;
}      

Dict::~Dict(){
    if (root) {
        delete root;
    }
}

TrieNode* Dict::getroot(){
    return root;
}

TrieNode* Dict::insertintotrie(string word){
    if (root== NULL){
        root = new TrieNode(); 
    }
    TrieNode* current=root;
    for (int i = 0; i < word.length(); i++){
        int index;
        if(isAlphabet(word[i])){
            index = word[i] - 'a';
        }
        else if(isDigit(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index = asciiValue-15 ;
        }
        else if(isSymbol1(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-9;
        }
        else if(isSymbol2(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-12;
        }
        else if(isSymbol47(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-15;
        }
        else if(isSymbol3(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-17;
        }
        else if(isSymbol92(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-46;
        }
        else if(isSymbol4(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-47;
        }
        else if(isSymbol5(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-73;
        }
        else{
            index=54;
        }
        if (!current->children[index]){          //if nullptr
            current->children[index] = new TrieNode();
            current->children[index]->character=word[i];
        } 
        current = current->children[index];
    }
    current->isEndofWord = true;
    (current->count)++;
    return root;
}

bool isSeparator(char c){
    int asciiValue = static_cast<int>(c);
    if(asciiValue==46 || asciiValue==44 || asciiValue==45 || asciiValue==58 || asciiValue==33 || asciiValue==34 || asciiValue==39 || asciiValue==40 || asciiValue==41 || asciiValue==63 || asciiValue==91 ||asciiValue==93 || asciiValue==59 || asciiValue==64 || asciiValue==32 || asciiValue==13 ){
        return true;
    }
    return false;
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    std::string lcsentence=lowercase(sentence);
    std::string word="";
    for(int i=0; i<sentence.size();i++){
        int asciiValue = static_cast<int>(lcsentence[i]);
        //have to deal with case "Hello! world" this can be a sentence but i have to only store hello and world
        //sepators to separate the words from the sentence and to put them in trie
        if(isSeparator(lcsentence[i]) ){
            //adding extra condition to check if the word is not empty
            if(word!=""){
                root=insertintotrie(word);//check this later
                word="";
            }//inserting the word into trie          
        }
        else{
            if(i==lcsentence.size()-1){
                word+=lcsentence[i];
                root=insertintotrie(word);
                return;
            }
            word+=lcsentence[i];
        } 
    } 
    return;
}

TrieNode* Dict::getcount(string word){
    TrieNode* current=getroot();
    for (int i = 0; i < word.length(); i++){   
        int index;
        if(isAlphabet(word[i])){
            index = word[i] - 'a';
        }
        else if(isDigit(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index = asciiValue-15 ;
        }
        else if(isSymbol1(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-9;
        }
        else if(isSymbol2(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-12;
        }
        else if(isSymbol47(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-15;
        }
        else if(isSymbol3(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-17;
        }
        else if(isSymbol92(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-46;
        }
        else if(isSymbol4(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-47;
        }
        else if(isSymbol5(word[i])){
            int asciiValue = static_cast<int>(word[i]);
            index=asciiValue-73;
        }
        else{
            index=54;
        }
        if (!current->children[index]){
            return NULL;
        }
        current= current->children[index];
    }
    if(current->isEndofWord){
        return current;
    }
    else{
        return NULL;
    }
}

int Dict::get_word_count(string word){
    if(getcount(word)){
        return getcount(word)->count;
    }
    return -1;
}

void Dict::printDFS(TrieNode* root, std::string& word, std::ofstream& out) {
    if (getroot() == NULL){
        return;
    }
    TrieNode* current = root;
    if (current->isEndofWord) {
        out << word << ", " << get_word_count(word) << std::endl;
    }
    for (int i = 0; i < 55; i++) {
        if (current->children[i]) {
            word += current->children[i]->character;
            printDFS(root->children[i], word, out);
            word.pop_back();
        }
    }
}

void Dict::dump_dictionary(string filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    std::string word = "";
    printDFS(getroot(), word, out);
    out.close();
}
