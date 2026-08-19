//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_28_Interfaces_in_CPP_Pure_Virtual_Functions.h"

#include <iostream>
#include <ostream>
#include <string>

namespace _28 {
    class IEntity {
    public:
        virtual  std::string GetName() = 0;//要求子类实现 =0
    };

    class Player : public IEntity {
    public:
        std::string GetName() override {
            return "Player";
        };
    };
}

void _28_Interfaces_in_CPP_Pure_Virtual_Functions::main() {
    //句纯虚函数。而要求派生类必须实现该功能
    _28::IEntity *e = new _28::Player();
    _28::Player *p = new _28::Player();


    std::cout << e->GetName() << std::endl;
    std::cout << p->GetName() << std::endl;
}
