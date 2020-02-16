//
// Created by vsensu on 2/17/2020.
//

#ifndef GENERICPROGRAMMINGANDDESIGNPATTERNSAPPLIED_1_5_H
#define GENERICPROGRAMMINGANDDESIGNPATTERNSAPPLIED_1_5_H

#include "common.h"

#include <iostream>

namespace _1_5 {
    template<class T>
    struct OpNewCreator {
        static T *Create() {
            return new T;
        }
    };

    template<class T>
    struct MallocCreator {
        static T *Create() {
            void *buf = std::malloc(sizeof(T));
            if (!buf) return 0;
            return new(buf) T;
        }
    };

    template<class T>
    struct PrototypeCreator {
        PrototypeCreator(T *pObj = 0) : pPrototype_(pObj) {}

        T *Create() {
            return pPrototype_ ? pPrototype_->Clone() : 0;
        }

        T *GetPrototype() { return pPrototype_; }

        void SetPrototype(T *pObj) { pPrototype_ = pObj; }

    private:
        T *pPrototype_;
    };

    // Library code
    template<class CreationPolicy>
    class WidgetManager : public CreationPolicy {
        // ...
    };

    struct Widget {};

    //Application code
    typedef WidgetManager<OpNewCreator<Widget>> MyWidgetMgr;

    // Library code
    template <template <class Created> class CreationPolicy = OpNewCreator> class GoodWidgetManager : public CreationPolicy<Widget>{
        // ...

        class Gagdet {};

    public:
        void DoSomething()
        {
            Gagdet *pw = CreationPolicy<Gagdet>().Create();
            std::cout << "do something" << std::endl;
            // ...
        }
    };

    //Application code
    typedef GoodWidgetManager<OpNewCreator> MyGoodWidgetMgr;
}

template<>
void Part<1, 5>::Run() {
    using namespace _1_5;
    MyGoodWidgetMgr mgr;
    mgr.DoSomething();
}

#endif //GENERICPROGRAMMINGANDDESIGNPATTERNSAPPLIED_1_5_H
