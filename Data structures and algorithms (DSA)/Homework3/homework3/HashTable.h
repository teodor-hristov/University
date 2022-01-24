#pragma once
#include <iostream>
#include <list>
#include <stdexcept>
#include <functional>
#include <set>

/*Optimization parameters*/
const size_t UPPER_BOUND = 1 << 20;
const size_t HASHTABLE_DEFAULT_SIZE = 501;
const size_t DEFAULT_WORD_SIZE = 5;

using std::list;
using std::string;
using std::hash;
using std::multiset;

class HashTable {
private:
	size_t buckets;
	hash<string> h;
	list<string>* tables;
	size_t uniqueWords;
	size_t wordsCount;
public:
	HashTable();
	HashTable(const size_t buckets);

	HashTable(const HashTable& other);
	HashTable& operator=(const HashTable& other);

	~HashTable();

	size_t mapValueToKey(const string value) const;
	bool elementExists(const string elment) const;

	size_t elementCount(const string element) const;
	size_t countOfUniqueWords() const;
	std::multiset<std::string> words() const;

	size_t getWordCount();
	void printTable() const;

	void insertElement(const string element);
	void removeElement(const string element);
};