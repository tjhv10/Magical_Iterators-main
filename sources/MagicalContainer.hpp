#ifndef MAGICAL_CONTAINER
#define MAGICAL_CONTAINER

#include <vector>
namespace ariel{
    class MagicalContainer;

    class Iterator
    {
    public:
        virtual ~Iterator() = default;
        Iterator(){};
        Iterator(const Iterator &other) = default;
        Iterator &operator=(const Iterator &other) = default;
        Iterator(Iterator &&other) = default;
        Iterator &operator=(Iterator &&other) = default;
    };

    class MagicalContainer
    {
        private:
            std::vector<int> elements;
            std::vector<int*> prElem;
        public:
            
            MagicalContainer() = default;
            void addElement(int element);
            void removeElement(int element);
            int size() const;
            std::vector<int> getElements() const;
            
            //friend class PrimeIterator;
            friend class AscendingIterator;
            //friend class SideCrossIterator;
        class AscendingIterator : public Iterator
        {
        private:
            MagicalContainer *cont;
            std::vector<int>::iterator it;
            int position;
        public:

            AscendingIterator(MagicalContainer &cont);
            AscendingIterator &begin();
            AscendingIterator &end();
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            int operator*() const;
            AscendingIterator & operator++();
        };

        class PrimeIterator : public Iterator
        {
        private:
            MagicalContainer *cont;
            std::vector<int*>::iterator it;
            int position;
            
        public:
            PrimeIterator(MagicalContainer &cont);
            static bool isPrime(int num);
            PrimeIterator &begin();
            PrimeIterator &end();
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            int operator*() const;
            PrimeIterator & operator++();
        };

        class SideCrossIterator : public Iterator
        {
        private:
            MagicalContainer *cont;
            std::vector<int>::iterator it;
            int position;
        public:
            SideCrossIterator(MagicalContainer &cont);
            SideCrossIterator &begin();
            SideCrossIterator &end();
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            int operator*() const;
            SideCrossIterator & operator++();
        };
    };
}
#endif