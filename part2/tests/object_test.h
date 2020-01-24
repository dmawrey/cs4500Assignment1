#pragma once

#include "test_util.h"
#include "test_template.h"

#include "../src/object.h"

class ObjectTest : public Test_template {

    public:

        virtual void run() {
            testNotEqual();
            testEqual();
        }

        void testEqual() {
            Object* obj = new Object();
            t_true(obj->hash() == obj->hash());
            t_true(obj->equal(obj));

            delete obj;
            OK("ObjectTest.testEqual");
        }

        void testNotEqual() {
            Object* obj0 = new Object();
            Object* obj1 = new Object();
            t_false(obj0->hash() == obj1->hash());
            t_false(obj0->equal(obj1));
            t_false(obj1->equal(obj0));

            delete obj0;
            delete obj1;
            OK("ObjectTest.testNotEqual");
        }

};