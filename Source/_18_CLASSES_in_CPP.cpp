//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_18_CLASSES_in_CPP.h"


class Player {
public:
    int x, y, speed;

    void Move(int in_x,int in_y) {
        x += in_x * speed;
        y += in_y * speed;
    }
};


void _18_CLASSES_in_CPP::main() {
    Player p = Player();
    p.Move(1,0);

    //C++它不会强制限定你的编程风格
    //简而言之，类就是用来把数据与功能打包整合的工具
}
