//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_27_Virtual_Functions_in_CPP.h"

#include <iostream>
#include <ostream>
#include <string>

namespace _27 {
    class Entity {
    public:
         virtual std::string GetName() {
            //虚函数登场
            return "Entity";
        }
    };

    class Player : public Entity {
        std::string GetName() override {
            //虚函数登场
            return "Player";
        }
    };
}


void PrintName(_27::Entity *player) {
    std::cout << player->GetName() << std::endl;
}

void _27_Virtual_Functions_in_CPP::main() {
    _27::Entity *e = new _27::Entity();
    _27::Player *player = new _27::Player();

    PrintName(e);
    PrintName(player);

    delete e;
    delete player;
}
