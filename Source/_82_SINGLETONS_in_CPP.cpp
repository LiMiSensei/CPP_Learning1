//
// Created by LiMi on 2026/8/26.
//

#include "../Header/_82_SINGLETONS_in_CPP.h"

namespace _82 {
    class Singleton {
        //最经典的单例
    public:
        Singleton(const Singleton&) = delete; //删除拷贝函数

        static Singleton& Get() {
            static Singleton instance; //本质就是在外部声明static instance
            return instance;
        }

    public:
        void Function() {
        }

        //将实例封装
        static float Float() { return Get().Float(); }

    private:
        float IFloat() { return m_Member; };

        Singleton() {
        }; //阻止外部创建实例
        float m_Member = 0.0f;
        static Singleton s_Instance;
    };
}

namespace RandomClass {
    static float s_Instance = 0.0f;
    static float Float() { return s_Instance; };
}

void _82_SINGLETONS_in_CPP::main() {
    //而是要着重讲解一个设计模式 那就是著名的单例模式
    //单例本质上就是一个类的唯一实例，全局共享使用
    //也就是说，这种类或结构体在整个程序中只允许存在一个实例
    //当我们需要操作全局数据集并希望反复重用时，单例模式就极具价值
    //单例模式的典型应用示例包括随机数生成器类
    _82::Singleton& instance = _82::Singleton::Get();
    //_82::Singleton instance = _82::Singleton::Get();//删除拷贝模式后只能&引用
    instance.Function();
    auto random = _82::Singleton::Float();
}
