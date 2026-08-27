//
// Created by LiMi on 2026/8/27.
//

#include "_94_Writing_an_ITERATOR_in_CPP.h"

#include <iostream>
#include <ostream>
#include <vector>

namespace _94 {
    template<typename Vector>
    class VectorIterator {
    public:
        using ValueType = typename Vector::ValueType;
        using Pointer = ValueType *;
        using Reference = ValueType &;

    public:
        VectorIterator(Pointer ptr) : m_Ptr(ptr) {
        }

        VectorIterator &operator++() {
            m_Ptr++;
            return *this;
        }

        VectorIterator operator++(int) {
            VectorIterator it = *this;
            ++(*this);
            return it;
        }

        VectorIterator &operator--() {
            m_Ptr--;
            return *this;
        }

        VectorIterator operator--(int) {
            VectorIterator it = *this;
            --(*this);
            return it;
        }

        Reference operator[](int index) {
            return *(m_Ptr + index);
        }

        Reference operator->() {
            return m_Ptr;
        }

        Reference operator*() {
            return *m_Ptr;
        }

        bool operator==(const VectorIterator &other) const {
            return m_Ptr == other.m_Ptr;
        }

        bool operator!=(const VectorIterator &other) const {
            return !(*this == other);
        }

    private:
        Pointer m_Ptr;
    };

    template<typename T>
    class Vector {
    public:
        using ValueType = T;
        using Iterator = VectorIterator<Vector<T> >;

    private:
        void ReAlloc(size_t newCapacity) {
            // 1. allocate a new block of memory
            // 2. copy/move old elements into new block
            // 3.delete
            T *newBlock = (T *) ::operator new(newCapacity * sizeof(T));

            if (newCapacity < m_Size)
                m_Size = newCapacity;

            for (size_t i = 0; i < m_Size; i++)
                new(&newBlock[i]) T(std::move(newBlock[i]));

            for (size_t i = 0; i < m_Size; i++)
                m_Data[i].~T();


            Clear();

            ::operator delete(m_Data, m_Capacity * sizeof(T));
            m_Data = newBlock;
            m_Capacity = newCapacity;
        }

    private:
        T *m_Data = nullptr;

        size_t m_Size = 0;
        size_t m_Capacity = 0;

    public:
        Vector() {
            // allocate 2 elements
            ReAlloc(2);
        }

        ~Vector() {
            Clear();
            ::operator delete(m_Data, m_Capacity * sizeof(T));
            //delete[] m_Data;
        }

        void PushBack(T &&value) {
            if (m_Size >= m_Capacity)
                ReAlloc(m_Capacity + m_Capacity / 2);

            m_Data[m_Size] = std::move(value);
            m_Size++;
        }

        template<typename... Args>
        T &EmplaceBack(Args &&... args) {
            if (m_Size >= m_Capacity)
                ReAlloc(m_Capacity + m_Capacity / 2);

            new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
            // using ValueType = typename std::remove_pointer<T>::type;
            // m_Data[m_Size] = new ValueType(std::forward<Args>(args)...);
            return m_Data[m_Size++];
        }

        size_t Size() const { return m_Size; }

        Iterator begin() {
            return Iterator(m_Data);
        }

        Iterator end() {
            return Iterator(m_Data + m_Size);
        }

        void PopBack() {
            if (m_Size > 0) {
                m_Size--;
                m_Data[m_Size].~T();
            }
        }

        void Clear() {
            for (size_t i = 0; i < m_Size; i++)
                m_Data[i].~T();

            m_Size = 0;
        }

        const T &operator[](size_t index) const {
            if (index >= m_Size) {
            }
            return m_Data[index];
        }

        T &operator[](size_t index) {
            if (index >= m_Size) {
            }
            return m_Data[index];
        }
    };
}

void _94_Writing_an_ITERATOR_in_CPP::main() {
    //实现迭代器会很困难吗？ 简而言之，实现迭代器并不算特别困难
    //但具体实现完全取决于你要选代的数据类型
    //所以迭代器说白了就是维护个指针 遍历时只需不断移动指针就行
    //我觉得有必要简单讨论下如何提升C++水平
    //根据我的经验，开发者终将领悟：阅读他人代码才是最佳学习途径


    /*std::vector<int> values = {1, 2, 3, 4, 5};
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i] << std::endl;
    }

    for (int value: values)
        std::cout << value << std::endl;

    for (std::vector<int>::iterator it = values.begin();
         it != values.end(); it++) {
        std::cout << *it << std::endl;
    }*/
    using namespace _94;

    Vector<std::string> values;
    values.EmplaceBack("1");
    values.EmplaceBack("2");
    values.EmplaceBack("3");
    values.EmplaceBack("4");
    values.EmplaceBack("5");


    std::cout << "Not using iterators:\n";
    for (int i = 0; i < values.Size();i++) {
        std::cout << values[i] << std::endl;
    }

    std::cout << "Range-based for loop:In";
    for (auto &value: values) {
        std::cout << value << std::endl;
    }


    std::cout << "Iterator:\n";
    for (Vector<std::string>::Iterator it = values.begin();
         it != values.end(); it++) {
        std::cout << *it << std::endl;
    }


    std::cin.get();
}
