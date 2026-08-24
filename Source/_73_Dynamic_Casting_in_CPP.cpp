//
// Created by LiMi on 2026/8/25.
//

#include "../Header/_73_Dynamic_Casting_in_CPP.h"

namespace _73 {
    class Entity {
    public:
        virtual void PrintName() = 0;
    };

    class Player : public Entity {
    public:
        void PrintName() override {

        }
    };

    class Enemy : public Entity {
    public:
        void PrintName() override {

        }
    };
}

void _73_Dynamic_Casting_in_CPP::maain() {
    using namespace _73;
    //今天我们要讲的是动态类型转换
    //毕竟动态类型转换需要执行额外的操作
    //我需要实现两种类型转换：向上转型（基类）或向下转型（派生类）
    //但向下转型的情况就比较复杂了 若强行用dynamic_cast将其转为玩家类型，转换就会失败
    //dynamic_cast会返回空指针，也就是返回零值
    //这样我们就能进行验证或执行其他操作 这样我们就能用它来验证对象是否属于特定类型
    //这样我们就能用它来验证对象是否属于特定类型 也就是说，我可以试着对这个实体对象进行动态类型转换
    // 把它转成玩家类型，再看看返回值是否为null


    //Player* player = new Player();

    Entity* enemy = new Enemy();
    Entity* player2 = new Player();

    Player* p0 = (Player *) enemy; //但这里存在风险，因为E1实际上是个敌方单位
    if (p0) {
        //因此，在追求极致优化或编写高性能代码时，最好避免使用这种机制
    }
    Player* p1 = dynamic_cast<Player *>(player2); //基类中必须存在virtual
    //按F10单步执行，可以看到返回值为null，说明强制转换失败了
}
