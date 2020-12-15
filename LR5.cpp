/*
*   LR_5 // VARIANT_16
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <functional>
#include <set>

void print(std::pair<int, std::string> n)
{
    std::cout << n.first << " : " << n.second << "; " << std::endl;
}

void print_vec(int t)
{
    std::cout << t << " ";
}

bool negative(std::pair<int, std::string> element)
{
    if (element.first < 0)
        return true;
    else
        return false;
}

bool neg_vec (int i)
{
    if (i < 0)
        return true;
    else
        return false;
}

int main()
{
    std::cout << "Task1: " << std::endl;
    std::unordered_multimap<int, std::string> keys = { {-1, "earth"}, {2, "wind"}, {5, "fire"},
                                                       {-4, "low"}, {-1, "high"}, {6, "word"} };
    std::for_each(keys.begin(), keys.end(), print);
    std::cout << std::endl;

    std::cout << "Task 1.1: " << std::endl; // insert 2 new values with key "4"
    keys.insert(std::make_pair<int, std::string>(4, "new1"));
    keys.insert(std::make_pair<int, std::string>(4, "new2"));
    std::for_each(keys.begin(), keys.end(), print);
    std::cout << std::endl;

    std::cout << "Task 1.2: " << std::endl; // delete elements with key "2"
    for (auto t = keys.begin(); t != keys.end(); t++)
        if (t->first == 2)
            t = keys.erase(t);
    std::for_each(keys.begin(), keys.end(), print);
    std::cout << std::endl;

    std::cout << "Task 1.3: " << std::endl; // copy elements from "unordered_multimap" to "map"
    std::map <int, std::string> cards;
    for (auto i : keys)
        cards.insert(std::make_pair(i.first, i.second));
    std::for_each(cards.begin(), cards.end(), print);
    std::cout << std::endl;

    std::cout << "Task 2: " << std::endl;
    std::cout << "Task 2.1: " << std::endl; // count number of elements, which have keys with negative values
    int negative_counter = std::count_if(cards.begin(), cards.end(), negative);
    std::cout << "Number of elements, which have keys with negative values: " << negative_counter << std::endl;

    std::cout << "Task 2.2: " << std::endl; // transform all keys in "vector" by std::transform
    std::vector<int> keys_vector;
    std::transform(cards.begin(), cards.end(), std::back_inserter(keys_vector), [](const std::pair<int, std::string> i) {return i.first; });
    std::for_each(keys_vector.begin(), keys_vector.end(), print_vec);
    std::cout << std::endl;

    std::cout << "Task 3: " << std::endl;
    std::cout << "Task 3.1: " << std::endl; // find element equal "5"
    auto finder_of_5 = std::find(keys_vector.begin(), keys_vector.end(), 5);
    if (finder_of_5 == keys_vector.end())
        std::cout << "There is no one '5' in this vector" << std::endl;
    else
        std::cout << "Number 5 found." << std::endl;

    std::cout << "Task 3.2: " << std::endl; // repleace negative elements on "6"
    std::replace_if(keys_vector.begin(), keys_vector.end(), neg_vec, 6);
    std::for_each(keys_vector.begin(), keys_vector.end(), print_vec);
    std::cout << std::endl;

    std::cout << "Task 3.3: " << std::endl; // sort array from more to less
    std::sort(keys_vector.begin(), keys_vector.end(), std::greater<int>());
    std::for_each(keys_vector.begin(), keys_vector.end(), print_vec);
    std::cout << std::endl;

    std::cout << "Task 3.4" << std::endl; // copy values in unordered set of unique elements
    std::set<int> set(keys_vector.begin(), keys_vector.end());
    std::for_each(keys_vector.begin(), keys_vector.end(), print_vec);
    return 0;
}
