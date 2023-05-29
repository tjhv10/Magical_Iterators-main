#ifndef MAGICAL_CONTAINER
#define MAGICAL_CONTAINER

#include <vector>
namespace ariel{
    class MagicalContainer;

    class Iterator
    {
    public:
        virtual int *begin() = 0;
        virtual int *end() = 0;
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

    public:
        MagicalContainer() = default;
        void addElement(int element);
        void removeElement(int element);
        int size() const;
        friend class PrimeIterator;
        friend class AscendingIterator;
        friend class SideCrossIterator;
        class AscendingIterator : public Iterator
    {
    private:
        MagicalContainer &cont;

    public:

        AscendingIterator(MagicalContainer &cont);

        int *begin() override;
        int *end() override;
    };

    class PrimeIterator : public Iterator
    {
    private:
        MagicalContainer &cont;

    public:
        PrimeIterator(MagicalContainer &cont);
        int *begin() override;
        int *end() override;
        bool isPrime(int num);
    };

    class SideCrossIterator : public Iterator
    {
    private:
        MagicalContainer &cont;

    public:
        SideCrossIterator(MagicalContainer &cont);

        int *begin() override;
        int *end() override;
    };
    };

    
}
#endif