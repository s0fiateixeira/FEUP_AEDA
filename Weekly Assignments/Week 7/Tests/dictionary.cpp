#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"
#include "bst.h"

using namespace std;

BST<WordMeaning> Dictionary::getWords() const {
    return words;
}

bool WordMeaning::operator < (const WordMeaning &wm1) const {
    return (getWord() < wm1.getWord());
}

void Dictionary::readDictionary(ifstream &f)
{
    while (!f.eof())
    {
        string word, meaning;
        getline(f, word);
        getline(f, meaning);
        words.insert(WordMeaning(word, meaning));
    }
}

string Dictionary::searchFor(string word) const
{
    BSTItrIn<WordMeaning> it(words);
    BSTItrIn<WordMeaning> previous_it(words);
    while (!it.isAtEnd())
    {
        if (it.retrieve().getWord() == word)
            return it.retrieve().getMeaning();
        else if (it.retrieve().getWord() > word)
            throw WordInexistent(previous_it.retrieve(), it.retrieve());
        else
        {
            previous_it = it;
            it.advance();
        }
    }
    throw WordInexistent(previous_it.retrieve(), WordMeaning("", ""));
}

bool Dictionary::correct(string word, string newMeaning)
{
    BSTItrIn<WordMeaning> it(words);
    while (!it.isAtEnd())
    {
        if (it.retrieve().getWord() == word)
        {
            words.remove(it.retrieve());
            words.insert(WordMeaning(word, newMeaning));
            return true;
        }
        else if (it.retrieve().getWord() > word)
        {
            words.remove(it.retrieve());
            words.insert(WordMeaning(word, newMeaning));
            return false;
        }
        else it.advance();
    }
}

void Dictionary::print() const
{
    BSTItrIn<WordMeaning> it(words);
    while(!it.isAtEnd())
    {
        cout << it.retrieve().getWord() << "\n" << it.retrieve().getMeaning() << endl;
        it.advance();
    }
}
