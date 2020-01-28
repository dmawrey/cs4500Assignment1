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
            getAndPutWorkObj();
            pushBackObj();
            putReplacesObjectObj();
            indexOfFindsObjectObj();
            indexOfReturnsSizeWhenMissingObj();
            equalsWorksInOrderObj();
            equalsWorksInOrderDiffSizeObj();
            equalsWorksOutOfOrderObj();

            // STRING LIST

            testConstructorInitsToNullptrStr();
            getAndPutWorkStr();
            pushBackStr();
            putReplacesObjectStr();
            indexOfFindsObjectStr();
            indexOfReturnsSizeWhenMissingStr();
            equalsWorksInOrderStr();
            equalsWorksInOrderDiffSizeStr();
            equalsWorksOutOfOrderStr();

            // Int LIST

            getAndPutWorkInt();
            pushBackInt();
            putReplacesObjectInt();
            indexOfFindsObjectInt();
            indexOfReturnsSizeWhenMissingInt();
            equalsWorksInOrderInt();
            equalsWorksInOrderDiffSizeInt();
            equalsWorksOutOfOrderInt();

            // Float LIST

            getAndPutWorkFloat();
            pushBackFloat();
            putReplacesObjectFloat();
            indexOfFindsObjectFloat();
            indexOfReturnsSizeWhenMissingFloat();
            equalsWorksInOrderFloat();
            equalsWorksInOrderDiffSizeFloat();
            equalsWorksOutOfOrderFloat();

            // Bool LIST

            getAndPutWorkBool();
            pushBackBool();
            putReplacesObjectBool();
            indexOfFindsObjectBool();
            indexOfReturnsSizeWhenMissingBool();
            equalsWorksInOrderBool();
            equalsWorksInOrderDiffSizeBool();
            equalsWorksOutOfOrderBool();
        }

        // OBJECT LIST

       void testConstructorInitsToNullptrObj() {
            ObjectArray* arr = new ObjectArray();
            for (int i = 0; i < 5; i++) { t_true(arr->get(i) == nullptr); }

            delete arr;
            OK("ArrayTest.testConstructorInitsToNullptrObj");
       }

        void getAndPutWorkObj() {
            ObjectArray* arr = new ObjectArray();
            String* str = new String("HI");

            arr->put(4, str);

            t_true(arr->get(4)->equals(str));
            t_true(str->equals(arr->get(4)));
            t_true(str == arr->get(4));

            delete arr;
            delete str;
            OK("ArrayTest.getAndPutWorkObj");
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

        void putReplacesObjectObj() {
            ObjectArray* arr = new ObjectArray();
            String* str = new String("HI");

            arr->put(4, str);
            arr->put(4, arr);

            t_true(arr->get(4)->equals(arr));
            t_true(arr->equals(arr->get(4)));
            t_true(arr == arr->get(4));

            delete arr;
            delete str;
            OK("ArrayTest.putReplacesObjectObj");
        }

        void indexOfFindsObjectObj() {
            ObjectArray* arr = new ObjectArray();
            String* str = new String("HI");

            arr->put(4, str);

            t_true(arr->indexOf(str) == 4);

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

            arr0->put(1, str0);
            arr0->put(0, str1);

            arr1->put(1, str0);
            arr1->put(0, str1);

            t_true(arr0->equals(arr1));
            t_true(arr1->equals(arr0));
            t_true(arr1->hash() == arr0->hash());

            delete arr0;
            delete arr1;
            delete str0;
            delete str1;

            OK("ArrayTest.equalsWorksInOrderObj");
        }

        void equalsWorksInOrderDiffSizeObj() {
            ObjectArray* arr0 = new ObjectArray();
            ObjectArray* arr1 = new ObjectArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            arr0->put(1, str0);
            arr0->put(0, str1);

            arr1->put(1, str0);
            arr1->put(0, str1);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;
            delete str0;
            delete str1;

            OK("ArrayTest.equalsWorksInOrderDiffSizeObj");
        }

        void equalsWorksOutOfOrderObj() {
            ObjectArray* arr0 = new ObjectArray();
            ObjectArray* arr1 = new ObjectArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            arr0->put(1, str0);
            arr0->put(0, str1);

            arr1->put(0, str0);
            arr1->put(1, str1);

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

        void getAndPutWorkStr() {
            StringArray* arr = new StringArray();
            String* str = new String("HI");

            arr->put(4, str);

            t_true(arr->get(4)->equals(str));
            t_true(str->equals(arr->get(4)));
            t_true(str == arr->get(4));

            delete arr;
            delete str;
            OK("ArrayTest.getAndPutWorkStr");
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

        void putReplacesObjectStr() {
            StringArray* arr = new StringArray();
            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            arr->put(4, str0);
            arr->put(4, str1);

            t_true(arr->get(4)->equals(str1));
            t_true(str1->equals(arr->get(4)));
            t_true(str1 == arr->get(4));

            delete arr;
            delete str0;
            delete str1;
            OK("ArrayTest.putReplacesObjectStr");
        }

        void indexOfFindsObjectStr() {
            StringArray* arr = new StringArray();
            String* str = new String("HI");

            arr->put(4, str);

            t_true(arr->indexOf(str) == 4);

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

            arr0->put(1, str0);
            arr0->put(0, str1);

            arr1->put(1, str0);
            arr1->put(0, str1);

            t_true(arr0->equals(arr1));
            t_true(arr1->equals(arr0));
            t_true(arr1->hash() == arr0->hash());

            delete arr0;
            delete arr1;
            delete str0;
            delete str1;

            OK("ArrayTest.equalsWorksInOrderStr");
        }

        void equalsWorksInOrderDiffSizeStr() {
            StringArray* arr0 = new StringArray();
            StringArray* arr1 = new StringArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            arr0->put(1, str0);
            arr0->put(0, str1);

            arr1->put(1, str0);
            arr1->put(0, str1);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;
            delete str0;
            delete str1;

            OK("ArrayTest.equalsWorksInOrderDiffSizeStr");
        }

        void equalsWorksOutOfOrderStr() {
            StringArray* arr0 = new StringArray();
            StringArray* arr1 = new StringArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            arr0->put(1, str0);
            arr0->put(0, str1);

            arr1->put(0, str0);
            arr1->put(1, str1);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;
            delete str0;
            delete str1;

            OK("ArrayTest.equalsWorksInOrderStr");
        }


        // Int

        void getAndPutWorkInt() {
            IntArray* arr = new IntArray();
            int i1 = 5;

            arr->put(4, i1);

            t_true(i1 == arr->get(4));
            t_true(arr->get(4) == i1);

            delete arr;
            OK("ArrayTest.getAndPutWorkInt");
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

        void putReplacesObjectInt() {
            IntArray* arr = new IntArray();

            int i1 = 5;
            int i2 = 10;

            arr->put(4, i1);
            arr->put(4, i2);

            t_true(arr->get(4) == i2);
            t_true(i2 == arr->get(4));

            delete arr;
            OK("ArrayTest.putReplacesObjectInt");
        }

        void indexOfFindsObjectInt() {
            IntArray* arr = new IntArray();
            int i1 = 5;

            arr->put(4, i1);

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

            arr0->put(1, i1);
            arr0->put(0, i2);

            arr1->put(1, i1);
            arr1->put(0, i2);

            t_true(arr0->equals(arr1));
            t_true(arr1->equals(arr0));
            t_true(arr1->hash() == arr0->hash());

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderInt");
        }

        void equalsWorksInOrderDiffSizeInt() {
            IntArray* arr0 = new IntArray();
            IntArray* arr1 = new IntArray();

            int i1 = 5;
            int i2 = 10;

            arr0->put(1, i1);
            arr0->put(0, i2);

            arr1->put(1, i1);
            arr1->put(0, i2);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderDiffSizeInt");
        }

        void equalsWorksOutOfOrderInt() {
            IntArray* arr0 = new IntArray();
            IntArray* arr1 = new IntArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            int i1 = 5;
            int i2 = 10;

            arr0->put(1, i1);
            arr0->put(0, i2);

            arr1->put(0, i1);
            arr1->put(1, i2);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderInt");
        }

        // Float

        void getAndPutWorkFloat() {
            FloatArray* arr = new FloatArray();
            float f1 = 5.0;

            arr->put(4, f1);

            t_true(f1 == arr->get(4));
            t_true(arr->get(4) == f1);

            delete arr;
            OK("ArrayTest.getAndPutWorkFloat");
        }

        void pushBackFloat() {
            FloatArray* arr = new FloatArray();
            float f1 = 5.0;

            arr->push_back(f1);

            t_true(f1 == arr->get(4));
            t_true(arr->get(4) == f1);
            t_true(arr->size == 1);

            delete arr;
            OK("ArrayTest.pushBackFloat");
        }

        void putReplacesObjectFloat() {
            FloatArray* arr = new FloatArray();

            float f1 = 5.0;
            float f2 = 10.0;

            arr->put(4, f1);
            arr->put(4, f2);

            t_true(arr->get(4) == f2);
            t_true(f2 == arr->get(4));

            delete arr;
            OK("ArrayTest.putReplacesObjectFloat");
        }

        void indexOfFindsObjectFloat() {
            FloatArray* arr = new FloatArray();
            float f1 = 5.0;

            arr->put(4, f1);

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

            arr0->put(1, f1);
            arr0->put(0, f2);

            arr1->put(1, f1);
            arr1->put(0, f2);
            
            t_true(arr0->equals(arr1));
            t_true(arr1->equals(arr0));
            t_true(arr1->hash() == arr0->hash());

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderFloat");
        }

        void equalsWorksInOrderDiffSizeFloat() {
            FloatArray* arr0 = new FloatArray();
            FloatArray* arr1 = new FloatArray();

            float f1 = 5.0;
            float f2 = 10.0;

            arr0->put(1, f1);
            arr0->put(0, f2);

            arr1->put(1, f1);
            arr1->put(0, f2);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderDiffSizeFloat");
        }

        void equalsWorksOutOfOrderFloat() {
            FloatArray* arr0 = new FloatArray();
            FloatArray* arr1 = new FloatArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            float f1 = 5.0;
            float f2 = 10.0;

            arr0->put(1, f1);
            arr0->put(0, f2);

            arr1->put(0, f1);
            arr1->put(1, f2);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderFloat");
        }

        // Bool

        void getAndPutWorkBool() {
            BoolArray* arr = new BoolArray();
            bool b1 = true;

            arr->put(4, b1);

            t_true(b1 == arr->get(4));
            t_true(arr->get(4) == b1);

            delete arr;
            OK("ArrayTest.getAndPutWorkBool");
        }

        void pushBackBool() {
            BoolArray* arr = new BoolArray();
            bool b1 = true;

            arr->push_back(b1);

            t_true(b1 == arr->get(4));
            t_true(arr->get(4) == b1);
            t_true(arr->size == 1);

            delete arr;
            OK("ArrayTest.pushBackBool");
        }

        void putReplacesObjectBool() {
            BoolArray* arr = new BoolArray();

            bool b1 = true;
            bool b2 = false;

            arr->put(4, b1);
            arr->put(4, b2);

            t_true(arr->get(4) == b2);
            t_true(b2 == arr->get(4));

            delete arr;
            OK("ArrayTest.putReplacesObjectBool");
        }

        void indexOfFindsObjectBool() {
            BoolArray* arr = new BoolArray();
            bool b1 = true;

            arr->put(4, b1);

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

            arr0->put(1, b1);
            arr0->put(0, b2);

            arr1->put(1, b1);
            arr1->put(0, b2);
            
            t_true(arr0->equals(arr1));
            t_true(arr1->equals(arr0));
            t_true(arr1->hash() == arr0->hash());

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderBool");
        }

        void equalsWorksInOrderDiffSizeBool() {
            BoolArray* arr0 = new BoolArray();
            BoolArray* arr1 = new BoolArray();

            bool b1 = true;
            bool b2 = false;

            arr0->put(1, b1);
            arr0->put(0, b2);

            arr1->put(1, b1);
            arr1->put(0, b2);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderDiffSizeBool");
        }

        void equalsWorksOutOfOrderBool() {
            BoolArray* arr0 = new BoolArray();
            BoolArray* arr1 = new BoolArray();

            String* str0 = new String("HI");
            String* str1 = new String("BYE");

            bool b1 = true;
            bool b2 = false;

            arr0->put(1, b1);
            arr0->put(0, b2);

            arr1->put(0, b1);
            arr1->put(1, b2);

            t_false(arr0->equals(arr1));
            t_false(arr1->equals(arr0));

            delete arr0;
            delete arr1;

            OK("ArrayTest.equalsWorksInOrderBool");
        }
};