//
// Created by vsensu on 2/17/2020.
//

#ifndef GENERICPROGRAMMINGANDDESIGNPATTERNSAPPLIED_1_4_H
#define GENERICPROGRAMMINGANDDESIGNPATTERNSAPPLIED_1_4_H

#include "common.h"

#include <iostream>

namespace _1_4 {
    template<class T>
    class Widget {
    public:
        void Fun() { std::cout << "main template" << std::endl; }
    };

    template<>
    void Widget<char>::Fun() {
        std::cout << "specialization" << std::endl;
    }

    template<class T, class U>
    class Gadget {
    public:
        void Fun() { std::cout << "main template" << std::endl; }
    };

// Compile error, 因为member function的 explicit specialization无partial specialization机制
//template <class U> void Gadget<char, U>::Fun()
//{
//
//}
}

template<>
void Part<1, 4>::Run() {
    using namespace _1_4;
    Widget<int> widget_int;
    widget_int.Fun();
    Widget<char> widget_char;
    widget_char.Fun();
    Gadget<int, char> gadget;
    gadget.Fun();
}

#endif //GENERICPROGRAMMINGANDDESIGNPATTERNSAPPLIED_1_4_H
