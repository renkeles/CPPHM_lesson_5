#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <string>


template <class Container>
void printContainer(Container& container, std::string name = "Container: \t", int rowOrCol = 0) {
    if (rowOrCol > 1 || rowOrCol < 0) return;
    if(rowOrCol == 0){
        std::cout << name << ": \t";
        for(auto it{container.begin()}; it != container.end(); ++it){
            std::cout << *it << " ";
        }
    }else if(rowOrCol == 1){
        std::cout << name << ":" << std::endl;
        for(auto it{container.begin()}; it != container.end(); ++it){
            std::cout << *it << std::endl;
        }
    }

    std::cout << std::endl;
}

template <class T>
void printUniqueWords(const T &begin, const T &end, std::string name){
    std::cout << name << ": \t";
    std::set<std::string> words;
    for(auto it{begin}; it != end; ++it){
        words.insert(*it);
    }
    printContainer(words, "Unique Words: ");
}

void task_1(){
    std::vector<std::string> vec {"present","foamy","sun","gray","encourage","sun","gray"};
    std::list<std::string> l {"present","foamy","sun","gray","encourage","sun","gray"};
    std::deque<std::string> deq {"present","foamy","sun","gray","encourage","sun","gray"};
    std::set<std::string> s {"present","foamy","sun","gray","encourage","sun","gray"};
    std::array<std::string, 7> arr;
    arr[0] = "present"; arr[1] = "foamy"; arr[2] = "sun"; arr[3] = "gray"; arr[4] = "encourage";
    arr[5] = "sun"; arr[6] = "gray";

    printUniqueWords(vec.begin(), vec.end(), "Vector");
    printUniqueWords(l.begin(), l.end(), "List");
    printUniqueWords(deq.begin(), deq.end(), "Deque");
    printUniqueWords(arr.begin(), arr.end(), "Array");
    printUniqueWords(s.begin(), s.end(), "Set");
}

int main() {

    //task_1();
    std::string tmp;
    std::multiset<std::string> ms;

    while(getline(std::cin, tmp)){
        if(tmp.empty()) break;
        ms.insert(tmp);
    }

    printContainer(ms, "Listing", 1);


    return 0;
}
