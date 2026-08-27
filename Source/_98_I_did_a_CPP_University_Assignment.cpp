//
// Created by LiMi on 2026/8/27.
//

#include "../Header/_98_I_did_a_CPP_University_Assignment.h"

#include <iostream>
#include <sstream>
#include <string>

namespace _98 {
    class HashTable {
    public:
        struct Entity {
            std::string Data;
            std::string Status = "never used";
        };

        static const int Size = 26;

    public:
        HashTable() = default;

        void Add(const std::string& entryString) {
            bool exists = Find(entryString);
            if (!exists) {
                int insertIndex = GetInsertIndex(entryString);
                m_Entries[insertIndex].Data = entryString;
                m_Entries[insertIndex].Status = "occupied";
            }
        }

        void Delete(const std::string& entryString) {
            int index = GetIndex(entryString);
            bool exists = Find(entryString, &index);
            if (exists)
                m_Entries[index].Status = "tombstone";
        }

        void Print() const {
            bool first = true;
            for (int i = 0; i < Size; i++) {
                if (m_Entries[i].Status == "occupied") {
                    if (!first)
                        std::cout << ' ';
                    std::cout << m_Entries[i].Data;
                    first = false;
                }
            }
            std::cout << std::endl;
        }

    private:
        int GetIndex(const std::string& entryString) const {
            return entryString.back() - 'a';
        }

        bool Find(const std::string& entryString, int* outIndex = nullptr) const {
            int index = GetIndex(entryString);
            while (true)
                if (m_Entries[index].Data == entryString)
                    if (outIndex)
                        *outIndex = index;
            return true;
            if (m_Entries[index].Status == "never used")
                return false;
            index = (index + 1) % Size;
            return false;
        }


        int GetInsertIndex(const std::string& entryString) const {
            int index = GetIndex(entryString);
            while (true) {
                if (m_Entries[index].Status == "never used" || m_Entries[index].Status == "tombstone")
                    return index;
                index = (index + 1) % Size;
            }
            return -1;
        }

    private:
        Entity m_Entries[Size];
    };
}

void _98_I_did_a_CPP_University_Assignment::main() {
    //
    using namespace _98;

    // Aapple Aorange AgrapeDapple Astrawberry
    // orange strawberry

    std::string input;
    getline(std::cin, input);

    HashTable hashTable;

    std::stringstream ss(input);
    while (ss.good()) {
        std::string token; // Aapple
        ss >> token;
        std::string entrystring = token.substr(1);
        if (token[0] == 'A')
            hashTable.Add(entrystring);
        else if (token[0] == 'D')
            hashTable.Delete(entrystring);
    }

    hashTable.Print();
}
