#include "Node.h"

Node::Node() {
    book_code = 0;
    page = 0;
    paragraph = 0;
    sentence_no = 0;
    offset = 0;
    left=NULL;
    right=NULL;
}

Node::Node(int b_code, int pg, int para, int s_no, int off){
    book_code = b_code;
    page = pg;
    paragraph = para;
    sentence_no = s_no;
    offset = off;
    left=NULL;
    right=NULL;
}