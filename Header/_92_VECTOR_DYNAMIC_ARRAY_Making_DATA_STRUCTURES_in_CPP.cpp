//
// Created by LiMi on 2026/8/27.
//

#include "_92_VECTOR_DYNAMIC_ARRAY_Making_DATA_STRUCTURES_in_CPP.h"

#include <iostream>
#include <string>

namespace _92 {
    template<typename T>
    class Vector {
    private:
        void ReAlloc(size_t newCapacity) {
            // 1. allocate a new block of memory
            // 2. copy/move old elements into new block
            // 3.delete
            T *newBlock = (T *) ::operator new(newCapacity * sizeof(T));

            if (newCapacity < m_Size)
                m_Size = newCapacity;

            for (size_t i = 0; i < m_Size; i++)
                newBlock[i] = std::move(m_Data[i]);

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

    //=============================================================================
    struct Vector3 {
        float x = 0.0f, y = 0.0f, z = 0.0f;
        int *m_MemoryBlock = nullptr;

        Vector3() {
            m_MemoryBlock = new int[5];
        }

        Vector3(float scalar)
            : x(scalar), y(scalar), z(scalar) {
        }

        Vector3(float x, float y, float z)
            : x(x), y(y), z(z) {
        }

        Vector3(const Vector3 &other) = delete;

        Vector3(Vector3 &&other) {
            m_MemoryBlock = other.m_MemoryBlock;
            other.m_MemoryBlock = nullptr;
            std::cout << "Move\n";
        }

        ~Vector3() {
            std::cout << "Destructor\n";
            delete[] m_MemoryBlock;
        }

        Vector3 &operator=(const Vector3 &other) = delete;

        /*std::cout << "Copy\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }*/
        Vector3 &operator=(Vector3 &&other) {
            std::cout << "Move\n";
            m_MemoryBlock = other.m_MemoryBlock;
            other.m_MemoryBlock = nullptr;
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }

        // ✅ 添加这行，解决编译错误
        friend std::ostream &operator<<(std::ostream &os, const Vector3 &v) {
            os << "Vector3(" << v.x << ", " << v.y << ", " << v.z << ")";
            return os;
        }
    };


    template<typename T>
    void PrintVector(const Vector<T> &vector) {
        for (size_t i = 0; i < vector.Size(); i++)
            std::cout << vector[i] << std::endl;

        std::cout << "-------------------------------------------------------------------\n";
    }
}

void _92_VECTOR_DYNAMIC_ARRAY_Making_DATA_STRUCTURES_in_CPP::main() {
    //因此，向量扩容和堆内存分配这些操作确实会影响性能
    // 所以这种情况下，一定要选择移动而非复制
    using namespace _92;


    {
        Vector<Vector3> vector;
        vector.EmplaceBack(1.0f);
        vector.EmplaceBack(1, 2, 3);
        vector.EmplaceBack(3, 1, 5);
        vector.EmplaceBack();
        PrintVector(vector);
        vector.PopBack();
        vector.PopBack();
        PrintVector(vector);
        vector.EmplaceBack(1, 2, 3);
        vector.EmplaceBack(1, 2, 3);
        PrintVector(vector);

        vector.Clear();
        PrintVector(vector);
        vector.EmplaceBack(1, 2, 3);
        vector.EmplaceBack(1, 2, 3);
        PrintVector(vector);
    }
}
