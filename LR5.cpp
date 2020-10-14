#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>

void print(std::pair<int, std::string> n) 
{
	std::cout << n.first << ") = " << n.second << "; " << std::endl;
}

int main()
{
	std::cout << "Task1: " << std::endl;
	std::unordered_multimap<int, std::string> keys = { {1, "key1"}, {2, "key2"}, {3, "key3"}, {4, "key1"}, {5, "key2"}, {6, "key3"} };
	std::for_each(keys.begin(), keys.end(), print); 
	std::cout << std::endl;

	std::cout << "Task 1.1: " << std::endl;
	keys.insert(std::make_pair<int, std::string>(4, "new1"));
	keys.insert(std::make_pair<int, std::string>(4, "new2"));
	std::for_each(keys.begin(), keys.end(), print);
	std::cout << std::endl;

	std::cout << "Task 1.2: " << std::endl;
	for (auto t = keys.begin(); t != keys.end(); t++)
	{
		if (t->first == 2)
			keys.erase(t);
		break;
	}
	std::for_each(keys.begin(), keys.end(), print);
	std::cout << std::endl;

	std::cout << "Task 1.3: " << std::endl;
	std::map <int, std::string> cards;
	for (auto i : keys)
		cards.insert(std::make_pair(i.first, i.second));
	std::for_each(cards.begin(), cards.end(), print); 
	std::cout << std::endl;

	std::cout << "Task 2.1: " << std::endl;


	return 0;
}