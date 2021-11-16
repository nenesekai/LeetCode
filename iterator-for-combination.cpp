#include <iostream>
#include <list>

class CombinationIterator {

    std::list<std::string> combinations;

public:
    CombinationIterator(std::string characters, int combinationLength) {
        
    }
    
    std::string next() {
        
    }
    
    bool hasNext() {
        
    }

};

int main()
{
    CombinationIterator* itr = new CombinationIterator("abc", 2);

    std::cout << itr->next() << std::endl;
    std::cout << itr->hasNext() ? "True" : "False" << std::endl;
    std::cout << itr->next() << std::endl;
    std::cout << itr->hasNext() ? "True" : "False" << std::endl;
    std::cout << itr->next() << std::endl;
    std::cout << itr->hasNext() ? "True" : "False" << std::endl;

    return 0;
}