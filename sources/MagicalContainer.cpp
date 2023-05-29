

#include "MagicalContainer.hpp"
#include <cmath>
#include <algorithm>
using namespace ariel;

void MagicalContainer::addElement(int elem) {
    elements.push_back(elem);
}

void MagicalContainer::removeElement(int elem) {
    elements.erase(std::remove(elements.begin(), elements.end(), elem), elements.end());
}

int MagicalContainer::size() const {
    return elements.size();
}


ariel::MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont):cont(cont){}

int* MagicalContainer::AscendingIterator::begin()
{
    std::sort(cont.elements.begin(), cont.elements.end());
    return cont.elements.data();
}

int* MagicalContainer::AscendingIterator::end() {
    return cont.elements.data() + cont.elements.size();
}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont) : cont(cont) {}

int* MagicalContainer::SideCrossIterator::begin() {
    return cont.elements.data();
}

int* MagicalContainer::SideCrossIterator::end() {
    return cont.elements.data() + cont.elements.size();
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont) : cont(cont) {}

int* MagicalContainer::PrimeIterator::begin() {
    std::sort(cont.elements.begin(), cont.elements.end());
    std::vector<int> prime_nums;
    for (int elem : cont.elements) {
        if (isPrime(elem)) {
            prime_nums.push_back(elem);
        }
    }
    cont.elements = prime_nums;
    return cont.elements.data();
}

int* MagicalContainer::PrimeIterator::end() {
    return cont.elements.data() + cont.elements.size();
}
bool MagicalContainer::PrimeIterator::isPrime(int num) {
    if (num <= 1)
        return false;
        
    int sqrtNumber = sqrt(num);
    for (int i = 2; i <= sqrtNumber; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}