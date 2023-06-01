#include "MagicalContainer.hpp"
#include <cmath>
#include <iostream>
using namespace ariel;
using namespace std;

void MagicalContainer::addElement(int elem) {
    if(elements.size()<0)
    {
        elements.insert(elements.begin(),elem);
        return;
    }
    auto it = std::lower_bound(elements.begin(), elements.end(), elem);
    elements.insert(it,elem);
}

void MagicalContainer::removeElement(int elem) {
    elements.erase(std::remove(elements.begin(), elements.end(), elem), elements.end());
}
int MagicalContainer::size() const {
    return elements.size();
}
std::vector<int> ariel::MagicalContainer::getElements() const
{
    return elements;
}
//AscendingIterator
ariel::MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont):cont(&cont),it(cont.elements.begin()){}

MagicalContainer::AscendingIterator &ariel::MagicalContainer::AscendingIterator::begin()
{
    it = cont->elements.begin();
    position =0;
    return *this;
}
MagicalContainer::AscendingIterator &ariel::MagicalContainer::AscendingIterator::end()
{
    it = cont->elements.end();
    position = cont->elements.size();
    return *this;
}
int ariel::MagicalContainer::AscendingIterator::operator*() const
{
    return *it;
}
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    ++position;
    ++it;
    return *this;
}
bool ariel::MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return position==other.position;
}

bool ariel::MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return position!=other.position;
}

bool ariel::MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return position>other.position;
}
bool ariel::MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return position<other.position;
}
//SideCrossIterator
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont) : cont(&cont){}

MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::begin()
{
    it = cont->elements.begin();
    position =0;
    return *this;
}

MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::end()
{
    // TODO: insert return statement here
}

bool ariel::MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return position==other.position;
}

bool ariel::MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return position!=other.position;
}

bool ariel::MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return position>other.position;
}

bool ariel::MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return position<other.position;
}

int ariel::MagicalContainer::SideCrossIterator::operator*() const
{
    return *it;
}

MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator++()
{
    // TODO: insert return statement here
}

//PrimeIterator
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont) : cont(&cont){}

MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::begin()
{
    position =0;
    it = cont->elements.begin();
    while (!isPrime(*it))
    {
        ++position;
        ++it;
    }
    return *this;
}

MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::end()
{
    it = cont->elements.end();
    position = cont->elements.size();
    return *this;
}

bool ariel::MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return position==other.position;
}

bool ariel::MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return position!=other.position;
}

bool ariel::MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return position>other.position;
}

bool ariel::MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return position<other.position;
}

int ariel::MagicalContainer::PrimeIterator::operator*() const
{
    return *it;
}

MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator++()
{
    ++position;
    ++it;
    while (position!=cont->size()&&!isPrime(*it))
    {
        ++position;
        ++it;
    }
    return *this;
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