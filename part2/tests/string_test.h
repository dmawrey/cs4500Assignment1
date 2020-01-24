#pragma once

#include <string.h>

#include "test_util.h"
#include "test_template.h"

#include "../src/string.h"

class StringTest : public Test_template {

    public:

        virtual void run() {
            testNotEqual();
            testSelfEqual();
            testEqual();
            testLengthEmpty();
            testLengthFull();
            testStringMakesCopy();
        }

        void testStringMakesCopy() {
            const char* contents = "STRING CONTENTS";
            String* str = new String(contents);
            t_true(str->value() != contents);
            t_true(strcmp(contents, str->value()) == 0);

            delete str;
            OK("StringTest.testStringMakesCopy");
        }

        void testLengthEmpty() {
            String* str = new String("");
            t_true(str->length() == 0);

            delete str;
            OK("StringTest.testLengthEmpty");
        }

        void testLengthFull() {
            String* str = new String("HELLO AARON");
            t_true(str->length() == 11);

            delete str;
            OK("StringTest.testLengthFull");
        }

        void testSelfEqual() {
            String* str = new String("HELLO AARON");
            t_true(str->hash() == str->hash());
            t_true(str->equal(str));

            delete str;
            OK("StringTest.testSelfEqual");
        }

        void testEqual() {
            String* str0 = new String("HELLO AARON");
            String* str1 = new String("HELLO AARON");
            t_true(str0->hash() == str1->hash());
            t_true(str0->equal(str1));
            t_true(str1->equal(str0));

            delete str0;
            delete str1;
            OK("StringTest.testEqual");
        }

        void testNotEqual() {
            String* str0 = new String("HELLO AARON");
            String* str1 = new String("BYE AARON");
            t_false(str0->equal(str1));
            t_false(str1->equal(str0));

            delete str0;
            delete str1;
            OK("StringTest.testNotEqual");
        }

};