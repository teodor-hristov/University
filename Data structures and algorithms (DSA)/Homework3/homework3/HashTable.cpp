#include "HashTable.h"

using std::cout;
using std::endl;
using std::string;
using std::hash;

HashTable::HashTable()
	: HashTable(HASHTABLE_DEFAULT_SIZE)
{}

HashTable::HashTable(const size_t buckets)
{
	if (buckets < 0) {
		throw std::invalid_argument("Buckets can't be negative.");
	}

	this->wordsCount = 0;
	this->uniqueWords = 0;
	this->buckets = buckets;
	this->tables = new list<string>[buckets];
	if (this->tables == nullptr) {
		throw std::bad_alloc();
	}
}

HashTable::HashTable(const HashTable& other)
{
	this->buckets = other.buckets;
	this->h = other.h;
	this->uniqueWords = other.uniqueWords;
	this->wordsCount = other.wordsCount;

	this->tables = new list<string>[buckets];

	for (size_t i = 0; i < buckets; i++)
	{
		this->tables[i] = other.tables[i];
	}
}

HashTable& HashTable::operator=(const HashTable& other)
{
	if (this == &other)
		return *this;

	this->buckets = other.buckets;
	this->h = other.h;
	this->uniqueWords = other.uniqueWords;
	this->wordsCount = other.wordsCount;

	delete[] this->tables;
	this->tables = new list<string>[buckets];

	for (size_t i = 0; i < buckets; i++)
	{
		this->tables[i] = other.tables[i];
	}

	return *this;
}

HashTable::~HashTable()
{
	delete[] this->tables;
}

size_t HashTable::mapValueToKey(const string value) const
{
	return (this->h(value) % buckets);
}

bool HashTable::elementExists(const string element) const
{
	if (this->tables[mapValueToKey(element)].empty())
		return false;

	for (auto table : tables[mapValueToKey(element)])
	{
		if (table == element) return true;
	}

	return false;
}

size_t HashTable::elementCount(const string element) const
{
	size_t res = 0;
	list<string> wantedTable = tables[mapValueToKey(element)];
	for (auto tableElement : wantedTable)
	{
		if (element == tableElement) {
			++res;
		}
	}

	return res;
}

size_t HashTable::countOfUniqueWords() const
{
	return uniqueWords;
}

std::multiset<std::string> HashTable::words() const
{
	std::multiset<std::string> res;

	for (size_t i = 0; i < buckets; i++)
	{
		for (auto element : tables[i])
		{
			res.insert(element);
		}
	}

	return res;
}

size_t HashTable::getWordCount()
{
	return wordsCount;
}

void HashTable::printTable() const
{
	for (size_t i = 0; i < buckets; i++)
	{
		if (!tables[i].empty()) {
			cout << "Bucket[" << i << "]: ";
			for (auto table : tables[i])
			{
				cout << table.c_str() << " ";
			}

			cout << endl;
		}
	}
}

void HashTable::insertElement(const string element)
{
	list<string>* wantedTable = &tables[mapValueToKey(element)];
	uniqueWords++;
	wordsCount++;

	for (auto x : *wantedTable)
	{
		if (x == element) {
			uniqueWords--;
			break;
		}
	}

	wantedTable->push_back(element);
}

void HashTable::removeElement(const string element)
{
	list<string>* wantedTable = &tables[mapValueToKey(element)];

	/*Clear only one element*/
	for (list<string>::iterator i = wantedTable->begin(); i != wantedTable->end(); i++)
	{
		if (*i == element) {
			wantedTable->erase(i);
			break;
		}
	}

	wordsCount--;
	uniqueWords--;

	/*Restore uniqueElements in case there are more than one words*/
	for (auto x : *wantedTable)
	{
		if (x == element) {
			uniqueWords++;
			break;
		}
	}
}
