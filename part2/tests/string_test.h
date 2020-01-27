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
            testStringCompareSameValue();
            testStringCompare();
            testStringCompareEmptyVal();
            testStringCompareOneEmptyVal();
            testConcatEmpty();
            testConcatOneValEmpty();
            testConcatBothValidValues();
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
            t_true(str->size() == 0);

            delete str;
            OK("StringTest.testLengthEmpty");
        }

        void testLengthFull() {
            String* str = new String("HELLO AARON");
            t_true(str->size() == 11);

            delete str;
            OK("StringTest.testLengthFull");
        }

        void testSelfEqual() {
            String* str = new String("HELLO AARON");
            t_true(str->hash() == str->hash());
            t_true(str->equals(str));

            delete str;
            OK("StringTest.testSelfEqual");
        }

        void testEqual() {
            String* str0 = new String("HELLO AARON");
            String* str1 = new String("HELLO AARON");
            t_true(str0->hash() == str1->hash());
            t_true(str0->equals(str1));
            t_true(str1->equals(str0));

            delete str0;
            delete str1;
            OK("StringTest.testEqual");
        }

        void testNotEqual() {
            String* str0 = new String("HELLO AARON");
            String* str1 = new String("BYE AARON");
            t_false(str0->equals(str1));
            t_false(str1->equals(str0));

            delete str0;
            delete str1;
            OK("StringTest.testNotEqual");
        }

        void testStringCompareSameValue() {
            String* str0 = new String("AAA");
            String* str1 = new String("AAA");
            t_true(str0->compare(str1) == 0);
            t_true(str1->compare(str0) == 0);

            delete str0;
            delete str1;
            OK("StringTest.testStringCompareSameValue");
        }

        void testStringCompare() {
            String* str0 = new String("AAA");
            String* str1 = new String("BBB");
            t_true(str0->compare(str1) < 0);
            t_true(str1->compare(str0) > 0);

            delete str0;
            delete str1;
            OK("StringTest.testStringCompare");
        }

        void testStringCompareEmptyVal() {
            String* str0 = new String("");
            String* str1 = new String("");
            t_true(str0->compare(str1) == 0);
            t_true(str1->compare(str0) == 0);

            delete str0;
            delete str1;
            OK("StringTest.testStringCompareEmptyVal");
        }

        void testStringCompareOneEmptyVal() {
            String* str0 = new String("AAA");
            String* str1 = new String("");
            t_true(str0->compare(str1) > 0);
            t_true(str1->compare(str0) < 0);

            delete str0;
            delete str1;
            OK("StringTest.testStringCompareOneEmptyVal");
        }

        void testConcatEmpty() {
            String* str0 = new String("");
            String* str1 = new String("");
            String* strConcat1 = str0->concat(str1);
            t_true(strConcat1->compare(str1) == 0);
            t_true(strConcat1->compare(str0) == 0);

            delete str0;
            delete str1;
            delete strConcat1;
            OK("StringTest.testConcatEmpty");
        }

        void testConcatOneValEmpty() {
            String* str0 = new String("");
            String* str1 = new String("AAA");
            String* strConcat1 = str0->concat(str1);
            String* expected = new String("AAA");
            t_true(expected->compare(strConcat1) == 0);

            delete str0;
            delete str1;
            delete strConcat1;
            delete expected;
            OK("StringTest.testConcatOneValEmpty");
        }

        void testConcatBothValidValues() {
            String* str0 = new String("AAA");
            String* str1 = new String("BBB");
            String* strConcat1 = str0->concat(str1);
            String* expected = new String("AAABBB");
            t_true(expected->compare(strConcat1) == 0);

            delete str0;
            delete str1;
            delete strConcat1;
            delete expected;
            OK("StringTest.testConcatOneValEmpty");
        }

};