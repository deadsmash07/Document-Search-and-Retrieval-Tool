Document Processing Tool
This is a project for the course COL106: Data Structures and Algorithms, Semester-I 2023–2024 at IIT Delhi1. The goal of this project is to create a natural language-based question answering system that can process a given corpus of documents and answer any query posed by the user2.

Motivation
The motivation behind this project is to learn and apply the concepts of data structures and algorithms to a real-world problem. The problem of document processing is relevant and challenging in the field of natural language processing, as it involves handling large amounts of text data, performing efficient search and retrieval operations, and providing accurate and relevant answers to the user.

Problem Statement
The problem statement of this project is as follows:

Given a corpus of documents, create a dictionary that stores the word counts of each word in the document3.
Given a pattern, perform a pattern search on the document and return all the offsets where the pattern is present4. The pattern can start and end in the middle of words5.
Given a query, answer the query using the dictionary and the pattern search. The query can be either a count query or a search query.
Expected Outcomes
The expected outcomes of this project are as follows:

A working and robust document processing tool that can handle any corpus of documents and any query from the user.
A report that documents the design and implementation details of the project, the test cases and the results, and the analysis and evaluation of the performance of the project.
A presentation that showcases the project and demonstrates its functionality and features.
Installation
To install the dependencies and libraries required for the project, follow these steps:

Make sure you have the latest version of g++ compiler installed on your system. You can check the version by running the following command:
g++ --version

Make sure you have the data structures library installed on your system. You can download the library from [here] and follow the instructions to install it.
Make sure you have any other external packages that are needed for the project installed on your system. For example, if you are using any natural language processing or machine learning libraries, you need to install them as well.
Usage
To compile the project, run the following command:

g++ -o main dict.cpp search.cpp main.cpp

To run the project, run the following command:

./main <corpus_file> <query_file> <output_file>

where <corpus_file> is the name of the file containing the corpus of documents, <query_file> is the name of the file containing the queries, and <output_file> is the name of the file where the output will be written.

The format of the corpus file is as follows:

<book_code>
<page_number>
<paragraph_number>
<sentence_number>
<sentence>

The format of the query file is as follows:

<query_type>
<query>

where <query_type> can be either count or search, and <query> is the word or pattern to be queried.

The format of the output file is as follows:

For count queries, the output is the word count of the query word.

For search queries, the output is a list of matches, each containing the book code, page number, paragraph number, sentence number, and starting offset of the match.
