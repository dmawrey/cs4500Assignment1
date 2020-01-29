#pragma once

#include "test_util.h"
#include "test_template.h"

#include "../src/object.h"
#include "../src/string.h"
#include "../src/array.h"

class ArrayTest : public Test_template {

    public:

        virtual void run() {
            // OBJECT LIST

            testConstructorInitsToNullptrObj();
            getAndsetWorkObj();
            pushBackObj();
            setReplacesObjectObj();
            indexOfFindsObjectObj();
            indexOfReturnsSizeWhenMissingObj();
            equalsWorksInOrderObj();
            equalsWorksOutOfOrderObj();

            // STRING LIST

            testConstructorInitsToNullptrStr();
            getAndsetWorkStr();
            pushBackStr();
            setReplacesObjectStr();
            indexOfFindsObjectStr();
            indexOfReturnsSizeWhenMissingStr();
            equalsWorksInOrderStr();
            equalsWorksOutOfOrderStr();

            // Int LIST

            getAndsetWorkInt();
            pushBackInt();
            setReplacesObjectInt();
            indexOfFindsObjectInt();
            indexOfReturnsSizeWhenMissingInt();
            equalsWorksInOrderInt();
            equalsWorksOutOfOrderInt();

            // Float LIST

            getAndsetWorkFloat();
            pushBackFloat();
            setReplacesObjectFloat();
            indexOfFindsObjectFloat();
            indexOfReturnsSizeWhenMissingFloat();
            equalsWorksInOrderFloat();
            equalsWorksOutOfOrderFloat();

            // Bool LIST

            getAndsetWorkBool();
            pushBackBool();
            setReplacesObjectBool();
            indexOfFindsObjectBool();
            indexOfReturnsSizeWhenMissingBool();
            equalsWorksInOrderBool();
            equalsWorksOutOfOrderBool();
        }

        // OBJECT LIST

       void testConstructorInitsToNullptrObj() {
            ObjectArray* arr = new ObjectArray();
            for (int i = 0; i < 5; i++) { t_true(arr->get(i) == nullptr); }

            delete arr;
            OK("ArrayTest.testConstructorInitsToNullptrObj");
       }

        void getAndsetWorkObj() {
            ObjectArray* arr = new ObjectArray();
            String* str = new String("HI");

            arr->push_back(str);

            t_true(arr->get(0)->equals(str));
            t_true(str->equals(arr->get(0)));
            t_true(str == arr->get(0));

            delete arr;
            delete str;
            OK("ArrayTest.getAndsetWorkObj");
        }

        void pushBackObj() {
            ObjectArray* arr = new ObjectArray();
            String* str = new String("HI");

            arr->push_back(str);

            t_true(arr->get(0)->equals(str));
            t_true(str->equals(arr->get(0)));
            t_true(str == arr->get(0));
            t_true(arr->size == 1);

            delete arr;
            delete str;
            OK("ArrayTest.pushBackObj");
        }

        void setReplacesObjectObj() {
            ObjectArray* arr = new ObjectArray();
            String* str = new String("HI");

            arr->push_back(str);
            arr->set(0, arr);

            t_true(arr->get(0)->equals(arr));
            t_true(arr->equals(arr->get(0)));
            t_true(arr == arr->get(0));

            delete arr;
            delete str;
            OK("ArrayTest.setReplacesObjectObj");
        }

        void indexOfFindsObjectObj() {
            ObjectArray* arr = new ObjectArray();
            String* str = new String("HI");

            arr->push_back(str);

            t_true(arr->indexOf(str) == 0);

            delete arr;
            delete str;
            OK("ArrayTest.indexOfFindsObjectObj");
        }

        void indexOfReturnsSizeWhenMissingObj() {
            ObjectArray* arr = new ObjectArray();
            String* str = new String("HI");

            t_true(arr->indexOf(str) == arr->size());

            delete arr;
            delete str;
            OK("ArrayTest.indexOfReturnsSizeWhenMissingObj");
        }

        void equalsWorksInOrderObj() {
            ObjectArray* arr0 = new ObjectArray();
            ObjectArray* arr1 = new ObjectArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            arr0->push_back(str0);
            arr0->push_back(str1);
            
            arr1->push_back(str0);
            arr1->push_back(str1);
            
            t_true(arr0->equals(arr1));
            t_true(arr1->equals(arr0));
            t_true(arr1->hash() == arr0->hash());

            delete arr0;
            delete arr1;
            delete str0;
            delete str1;

            OK("ArrayTest.equalsWorksInOrderObj");
        }

        void equalsWorksOutOfOrderObj() {
            ObjectArray* arr0 = new ObjectArray();
            ObjectArray* arr1 = new ObjectArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            arr0->push_back(str0);
            arr0->push_back(str1);

            arr1->push_back(str1);
            arr1->push_back(str0);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;
            delete str0;
            delete str1;

            OK("ArrayTest.equalsWorksInOrderObj");
        }

        // String

        void testConstructorInitsToNullptrStr() {
            StringArray* arr = new StringArray();
            for (int i = 0; i < 5; i++) { t_true(arr->get(i) == nullptr); }

            delete arr;
            OK("ArrayTest.testConstructorInitsToNullptrStr");
        }

        void getAndsetWorkStr() {
            StringArray* arr = new StringArray();
            String* str = new String("HI");

            arr->push_back(str);

            t_true(arr->get(0)->equals(str));
            t_true(str->equals(arr->get(0)));
            t_true(str == arr->get(0));

            delete arr;
            delete str;
            OK("ArrayTest.getAndsetWorkStr");
        }

        void pushBackStr() {
            StringArray* arr = new StringArray();
            String* str = new String("HI");

            arr->push_back(str);

            t_true(arr->get(0)->equals(str));
            t_true(str->equals(arr->get(0)));
            t_true(str == arr->get(0));
            t_true(arr->size == 1);

            delete arr;
            delete str;
            OK("ArrayTest.pushBackStr");
        }

        void setReplacesObjectStr() {
            StringArray* arr = new StringArray();
            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            arr->push_back(str0);
            arr->set(0, str1);

            t_true(arr->get(0)->equals(str1));
            t_true(str1->equals(arr->get(0)));
            t_true(str1 == arr->get(0));

            delete arr;
            delete str0;
            delete str1;
            OK("ArrayTest.setReplacesObjectStr");
        }

        void indexOfFindsObjectStr() {
            StringArray* arr = new StringArray();
            String* str = new String("HI");

            arr->push_back(str);

            t_true(arr->indexOf(str) == 0);

            delete arr;
            delete str;
            OK("ArrayTest.indexOfFindsObjectStr");
        }

        void indexOfReturnsSizeWhenMissingStr() {
            StringArray* arr = new StringArray();
            String* str = new String("HI");

            t_true(arr->indexOf(str) == arr->size());

            delete arr;
            delete str;
            OK("ArrayTest.indexOfReturnsSizeWhenMissingStr");
        }

        void equalsWorksInOrderStr() {
            StringArray* arr0 = new StringArray();
            StringArray* arr1 = new StringArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            arr0->push_back(str0);
            arr0->push_back(str1);

            arr1->push_back(str0);
            arr1->push_back(str1);

            t_true(arr0->equals(arr1));
            t_true(arr1->equals(arr0));
            t_true(arr1->hash() == arr0->hash());

            delete arr0;
            delete arr1;
            delete str0;
            delete str1;

            OK("ArrayTest.equalsWorksInOrderStr");
        }

        void equalsWorksOutOfOrderStr() {
            StringArray* arr0 = new StringArray();
            StringArray* arr1 = new StringArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            arr0->push_back(str0);
            arr0->push_back(str1);

            arr1->push_back(str1);
            arr1->push_back(str0);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;
            delete str0;
            delete str1;

            OK("ArrayTest.equalsWorksInOrderStr");
        }


        // Int

        void getAndsetWorkInt() {
            IntArray* arr = new IntArray();
            int i1 = 5;

            arr->push_back(i1);

            t_true(i1 == arr->get(0));
            t_true(arr->get(0) == i1);

            delete arr;
            OK("ArrayTest.getAndsetWorkInt");
        }

        void pushBackInt() {
            IntArray* arr = new IntArray();
            int i1 = 5;

            arr->push_back(i1);

            t_true(i1 == arr->get(0));
            t_true(arr->get(0) == i1);
            t_true(arr->size == 1);

            delete arr;
            OK("ArrayTest.pushBackInt");
        }

        void setReplacesObjectInt() {
            IntArray* arr = new IntArray();

            int i1 = 5;
            int i2 = 10;

            arr->push_back(i1);
            arr->set(0, i2);

            t_true(arr->get(0) == i2);
            t_true(i2 == arr->get(0));

            delete arr;
            OK("ArrayTest.setReplacesObjectInt");
        }

        void indexOfFindsObjectInt() {
            IntArray* arr = new IntArray();
            int i1 = 5;

            arr->push_back(i1);

            t_true(arr->indexOf(i1) == 4);

            delete arr;
            OK("ArrayTest.indexOfFindsObjectInt");
        }

        void indexOfReturnsSizeWhenMissingInt() {
            IntArray* arr = new IntArray();
            int i1 = 5;

            t_true(arr->indexOf(i1) == arr->size());

            delete arr;
            OK("ArrayTest.indexOfReturnsSizeWhenMissingInt");
        }

        void equalsWorksInOrderInt() {
            IntArray* arr0 = new IntArray();
            IntArray* arr1 = new IntArray();

            int i1 = 5;
            int i2 = 10;

            arr0->push_back(i1);
            arr0->push_back(i2);

            arr1->push_back(i1);
            arr1->push_back(i2);

            t_true(arr0->equals(arr1));
            t_true(arr1->equals(arr0));
            t_true(arr1->hash() == arr0->hash());

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderInt");
        }

        void equalsWorksOutOfOrderInt() {
            IntArray* arr0 = new IntArray();
            IntArray* arr1 = new IntArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            int i1 = 5;
            int i2 = 10;

            arr0->push_back(i1);
            arr0->push_back(i2);

            arr1->push_back(i2);
            arr1->push_back(i1);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderInt");
        }

        // Float

        void getAndsetWorkFloat() {
            FloatArray* arr = new FloatArray();
            float f1 = 5.0;

            arr->push_back(f1);

            t_true(f1 == arr->get(0));
            t_true(arr->get(0) == f1);

            delete arr;
            OK("ArrayTest.getAndsetWorkFloat");
        }

        void pushBackFloat() {
            FloatArray* arr = new FloatArray();
            float f1 = 5.0;

            arr->push_back(f1);

            t_true(f1 == arr->get(0));
            t_true(arr->get(0) == f1);
            t_true(arr->size == 1);

            delete arr;
            OK("ArrayTest.pushBackFloat");
        }

        void setReplacesObjectFloat() {
            FloatArray* arr = new FloatArray();

            float f1 = 5.0;
            float f2 = 10.0;

            arr->push_back(f1);
            arr->set(0, f2);

            t_true(arr->get(0) == f2);
            t_true(f2 == arr->get(0));

            delete arr;
            OK("ArrayTest.setReplacesObjectFloat");
        }

        void indexOfFindsObjectFloat() {
            FloatArray* arr = new FloatArray();
            float f1 = 5.0;

            arr->push_back(f1);

            t_true(arr->indexOf(f1) == 4);

            delete arr;
            OK("ArrayTest.indexOfFindsObjectFloat");
        }

        void indexOfReturnsSizeWhenMissingFloat() {
            FloatArray* arr = new FloatArray();
            float f1 = 5.0;

            t_true(arr->indexOf(f1) == arr->size());

            delete arr;
            OK("ArrayTest.indexOfReturnsSizeWhenMissingFloat");
        }

        void equalsWorksInOrderFloat() {
            FloatArray* arr0 = new FloatArray();
            FloatArray* arr1 = new FloatArray();

            float f1 = 5.0;
            float f2 = 10.0;

            arr0->push_back(f1);
            arr0->push_back(f2);

            arr1->push_back(f1);
            arr1->push_back(f2);
            
            t_true(arr0->equals(arr1));
            t_true(arr1->equals(arr0));
            t_true(arr1->hash() == arr0->hash());

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderFloat");
        }

        void equalsWorksOutOfOrderFloat() {
            FloatArray* arr0 = new FloatArray();
            FloatArray* arr1 = new FloatArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            float f1 = 5.0;
            float f2 = 10.0;

            arr0->push_back(f1);
            arr0->push_back(f2);

            arr1->push_back(f2);
            arr1->push_back(f1);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderFloat");
        }

        // Bool

        void getAndsetWorkBool() {
            BoolArray* arr = new BoolArray();
            bool b1 = true;

            arr->push_back(b1);

            t_true(b1 == arr->get(0));
            t_true(arr->get(0) == b1);

            delete arr;
            OK("ArrayTest.getAndsetWorkBool");
        }

        void pushBackBool() {
            BoolArray* arr = new BoolArray();
            bool b1 = true;

            arr->push_back(b1);

            t_true(b1 == arr->get(0));
            t_true(arr->get(0) == b1);
            t_true(arr->size == 1);

            delete arr;
            OK("ArrayTest.pushBackBool");
        }

        void setReplacesObjectBool() {
            BoolArray* arr = new BoolArray();

            bool b1 = true;
            bool b2 = false;

            arr->push_back(b1);
            arr->set(0, b2);

            t_true(arr->get(0) == b2);
            t_true(b2 == arr->get(0));

            delete arr;
            OK("ArrayTest.setReplacesObjectBool");
        }

        void indexOfFindsObjectBool() {
            BoolArray* arr = new BoolArray();
            bool b1 = true;

            arr->push_back(b1);

            t_true(arr->indexOf(b1) == 4);

            delete arr;
            OK("ArrayTest.indexOfFindsObjectBool");
        }

        void indexOfReturnsSizeWhenMissingBool() {
            BoolArray* arr = new BoolArray();
            bool b1 = true;

            t_true(arr->indexOf(b1) == arr->size());

            delete arr;
            OK("ArrayTest.indexOfReturnsSizeWhenMissingBool");
        }

        void equalsWorksInOrderBool() {
            BoolArray* arr0 = new BoolArray();
            BoolArray* arr1 = new BoolArray();

            bool b1 = true;
            bool b2 = false;

            arr0->push_back(b1);
            arr0->push_back(b2);

            arr1->push_back(b1);
            arr1->push_back(b2);
            
            t_true(arr0->equals(arr1));
            t_true(arr1->equals(arr0));
            t_true(arr1->hash() == arr0->hash());

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderBool");
        }

        void equalsWorksOutOfOrderBool() {
            BoolArray* arr0 = new BoolArray();
            BoolArray* arr1 = new BoolArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            bool b1 = true;
            bool b2 = false;

            arr0->push_back(b1);
            arr0->push_back(b2);

            arr1->push_back(b2);
            arr1->push_back(b1);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderBool");
        }
};