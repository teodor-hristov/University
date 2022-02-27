#include "../homework3/interface.h"

using std::string;

WordsMultiset::WordsMultiset(const size_t size)
{
	hashTable = HashTable(size);
}

void WordsMultiset::add(const std::string& word, size_t times)
{
	size_t tempTimes = times;

	while (tempTimes) {
		hashTable.insertElement(word);
		tempTimes--;
	}
}

void WordsMultiset::remove(const std::string& word)
{
	hashTable.removeElement(word);
}

size_t WordsMultiset::getWords()
{
	return hashTable.getWordCount();
}

void WordsMultiset::addUnique(const std::string& word)
{
	if (!hashTable.elementExists(word))
		hashTable.insertElement(word);
}

bool WordsMultiset::contains(const std::string& word) const
{
	return hashTable.elementExists(word);
}

size_t WordsMultiset::countOf(const std::string& word) const
{
	return hashTable.elementCount(word);
}

size_t WordsMultiset::countOfUniqueWords() const
{
	return hashTable.countOfUniqueWords();
}

std::multiset<std::string> WordsMultiset::words() const
{
	return hashTable.words();
}

void WordsMultiset::print()
{
	hashTable.printTable();
}

ComparisonReport Comparator::compare(std::istream& a, std::istream& b)
{
	string s;
	if (!a.good() || !b.good())
		throw std::invalid_argument("Bad stream!");

	/*Get size of istream a and b*/
	a.seekg(0, a.end);
	size_t aSize = a.tellg();
	a.seekg(0, a.beg);

	b.seekg(0, b.end);
	size_t bSize = b.tellg();
	b.seekg(0, b.beg);
	
	/*Get max size*/
	const size_t maxSize = std::max(bSize, aSize) / 5000 > 0 ?
		std::max(bSize, aSize) / 5000 > 0 : HASHTABLE_DEFAULT_SIZE;

	ComparisonReport result;
	result.commonWords = WordsMultiset(maxSize > UPPER_BOUND ? UPPER_BOUND : maxSize);
	result.uniqueWords[0] = WordsMultiset(maxSize > UPPER_BOUND ? UPPER_BOUND : maxSize);
	result.uniqueWords[1] = WordsMultiset(maxSize > UPPER_BOUND ? UPPER_BOUND : maxSize);

	while (getline(a, s, ' ')) {
		if (s != "" || s != " ")
			result.uniqueWords[0].add(s);
	}

	while (getline(b, s, ' ')) {
		if (s != "" || s != " ")
			if (result.uniqueWords[0].contains(s)) {
				result.commonWords.add(s);
				result.uniqueWords[0].remove(s);
				continue;
			}

		result.uniqueWords[1].add(s);
	}

	return result;
}
