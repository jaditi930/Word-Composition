# Word Composition

## Overview
This C++ program is designed to find the longest and second longest compounded words from a list of words provided in an input file. It utilizes a trie data structure for efficient word storage and searching. The program also measures and displays the execution time for processing the input.

## Code Overview

The code consists of two main classes:

1. `TrieNode`: This class represents a node in a trie. Each node has an array of 26 children, one for each lowercase English alphabet letter, and a boolean flag to indicate whether the node marks the end of a word.

2. `Trie`: This class represents the trie data structure. It provides functions to insert a word into the trie and search for a word.

The program proceeds as follows:

1. It reads the input file containing a list of words (separated by newlines) based on user choice (`Input_01.txt` or `Input_02.txt`).

2. The words are stored in a vector and then inserted into the trie for efficient searching.

3. It iterates over the list of words, and for each word, it checks if the word is compounded. A word is considered compounded if it can be formed by concatenating other words from the list.

4. The program identifies and keeps track of the longest and second longest compounded words found.

5. After processing the entire list, it displays the longest compounded word and the second longest compounded word. It also provides the execution time for processing the input.

## Execution Steps

1. Clone the github repository as follows:
     ```bash
   git clone https://github.com/jaditi930/Impledge-Coding-Assesment
   ```
2. Compile and run the program using a C++ compiler (e.g., g++).

   ```bash
   g++ -o Impledge Coding Assesment Word_Composition.cpp
   ./Word_Composition
   ```

3. Upon running the program, you will be prompted to choose an input file. Enter `1` to execute `Input_01.txt` or `2` to execute `Input_02.txt`.

4. The program will process the input, identify the longest and second longest compounded words, and display the results, along with the time taken to process the chosen input file.

5. Review the output to see the longest and second longest compounded words.