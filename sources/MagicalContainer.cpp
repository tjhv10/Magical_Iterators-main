

#include "MagicalContainer.hpp"
#include <cmath>
#include <algorithm>

void MagicalContainer::addElement(int elem) {
    elements.push_back(elem);
}

void MagicalContainer::removeElement(int elem) {
    elements.erase(std::remove(elements.begin(), elements.end(), elem), elements.end());
}

int MagicalContainer::size() const {
    return elements.size();
}

AscendingIterator::AscendingIterator(MagicalContainer& cont) : cont(cont) {}

int* AscendingIterator::begin() {
    std::sort(cont.elements.begin(), cont.elements.end());
    return cont.elements.data();
}

int* AscendingIterator::end() {
    return cont.elements.data() + cont.elements.size();
}

SideCrossIterator::SideCrossIterator(MagicalContainer& cont) : cont(cont) {}

int* SideCrossIterator::begin() {
    return cont.elements.data();
}

int* SideCrossIterator::end() {
    return cont.elements.data() + cont.elements.size();
}

PrimeIterator::PrimeIterator(MagicalContainer& cont) : cont(cont) {}

int* PrimeIterator::begin() {
    std::vector<int> prime_nums;
    for (int elem : cont.elements) {
        if (isPrime(elem)) {
            prime_nums.push_back(elem);
        }
    }
    cont.elements = prime_nums;
    return cont.elements.data();
}

int* PrimeIterator::end() {
    return cont.elements.data() + cont.elements.size();
}
bool PrimeIterator::isPrime(int num) {
    if (num <= 1)
        return false;
        
    int sqrtNumber = sqrt(num);
    for (int i = 2; i <= sqrtNumber; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}