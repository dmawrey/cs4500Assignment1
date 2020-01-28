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

            testConstructorAllocatesCapacityObj();
            testConstructorInitsToNullptrObj();
            getAndPutWorkObj();
            putReplacesObjectObj();
            indexOfFindsObjectObj();
            indexOfReturnsSizeWhenMissingObj();
            equalsWorksInOrderObj();
            equalsWorksInOrderDiffSizeObj();
            equalsWorksOutOfOrderObj();

            // STRING LIST

            testConstructorAllocatesCapacityStr();
            testConstructorInitsToNullptrStr();
            getAndPutWorkStr();
            putReplacesObjectStr();
            indexOfFindsObjectStr();
            indexOfReturnsSizeWhenMissingStr();
            equalsWorksInOrderStr();
            equalsWorksInOrderDiffSizeStr();
            equalsWorksOutOfOrderStr();

            // Int LIST

            testConstructorAllocatesCapacityInt();
            getAndPutWorkInt();
            putReplacesObjectInt();
            indexOfFindsObjectInt();
            indexOfReturnsSizeWhenMissingInt();
            equalsWorksInOrderInt();
            equalsWorksInOrderDiffSizeInt();
            equalsWorksOutOfOrderInt();

            // Float LIST

            testConstructorAllocatesCapacityFloat();
            getAndPutWorkFloat();
            putReplacesObjectFloat();
            indexOfFindsObjectFloat();
            indexOfReturnsSizeWhenMissingFloat();
            equalsWorksInOrderFloat();
            equalsWorksInOrderDiffSizeFloat();
            equalsWorksOutOfOrderFloat();

            // Bool LIST

            testConstructorAllocatesCapacityBool();
            testConstructorInitsToNullptrBool();
            getAndPutWorkBool();
            putReplacesObjectBool();
            indexOfFindsObjectBool();
            indexOfReturnsSizeWhenMissingBool();
            equalsWorksInOrderBool();
            equalsWorksInOrderDiffSizeBool();
            equalsWorksOutOfOrderBool();
        }

        // OBJECT LIST

       void testConstructorAllocatesCapacityObj() {
            ObjectArray* arr = new ObjectArray(5);
            t_true(arr->size() == 5);

            delete arr;
            OK("ArrayTest.testConstructorAllocatesCapacityObj");
        }

       void testConstructorInitsToNullptrObj() {
            ObjectArray* arr = new ObjectArray(5);
            for (int i = 0; i < 5; i++) { t_true(arr->get(i) == nullptr); }

            delete arr;
            OK("ArrayTest.testConstructorInitsToNullptrObj");
       }

        void getAndPutWorkObj() {
            ObjectArray* arr = new ObjectArray(5);
            String* str = new String("HI");

            arr->put(4, str);

            t_true(arr->get(4)->equals(str));
            t_true(str->equals(arr->get(4)));
            t_true(str == arr->get(4));

            delete arr;
            delete str;
            OK("ArrayTest.getAndPutWorkObj");
        }

        void putReplacesObjectObj() {
            ObjectArray* arr = new ObjectArray(5);
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
            ObjectArray* arr = new ObjectArray(5);
            String* str = new String("HI");

            arr->put(4, str);

            t_true(arr->indexOf(str) == 4);

            delete arr;
            delete str;
            OK("ArrayTest.indexOfFindsObjectObj");
        }

        void indexOfReturnsSizeWhenMissingObj() {
            ObjectArray* arr = new ObjectArray(5);
            String* str = new String("HI");

            t_true(arr->indexOf(str) == arr->size());

            delete arr;
            delete str;
            OK("ArrayTest.indexOfReturnsSizeWhenMissingObj");
        }

        void equalsWorksInOrderObj() {
            ObjectArray* arr0 = new ObjectArray(2);
            ObjectArray* arr1 = new ObjectArray(2);

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
            ObjectArray* arr0 = new ObjectArray(3);
            ObjectArray* arr1 = new ObjectArray(2);

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
            ObjectArray* arr0 = new ObjectArray(2);
            ObjectArray* arr1 = new ObjectArray(2);

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

        void testConstructorAllocatesCapacityStr() {
            StringArray* arr = new StringArray(5);
            t_true(arr->size() == 5);

            delete arr;
            OK("ArrayTest.testConstructorAllocatesCapacityStr");
        }

        void testConstructorInitsToNullptrStr() {
            StringArray* arr = new StringArray(5);
            for (int i = 0; i < 5; i++) { t_true(arr->get(i) == nullptr); }

            delete arr;
            OK("ArrayTest.testConstructorInitsToNullptrStr");
        }

        void getAndPutWorkStr() {
            StringArray* arr = new StringArray(5);
            String* str = new String("HI");

            arr->put(4, str);

            t_true(arr->get(4)->equals(str));
            t_true(str->equals(arr->get(4)));
            t_true(str == arr->get(4));

            delete arr;
            delete str;
            OK("ArrayTest.getAndPutWorkStr");
        }

        void putReplacesObjectStr() {
            StringArray* arr = new StringArray(5);
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
            StringArray* arr = new StringArray(5);
            String* str = new String("HI");

            arr->put(4, str);

            t_true(arr->indexOf(str) == 4);

            delete arr;
            delete str;
            OK("ArrayTest.indexOfFindsObjectStr");
        }

        void indexOfReturnsSizeWhenMissingStr() {
            StringArray* arr = new StringArray(5);
            String* str = new String("HI");

            t_true(arr->indexOf(str) == arr->size());

            delete arr;
            delete str;
            OK("ArrayTest.indexOfReturnsSizeWhenMissingStr");
        }

        void equalsWorksInOrderStr() {
            StringArray* arr0 = new StringArray(2);
            StringArray* arr1 = new StringArray(2);

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
            StringArray* arr0 = new StringArray(3);
            StringArray* arr1 = new StringArray(2);

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
            StringArray* arr0 = new StringArray(2);
            StringArray* arr1 = new StringArray(2);

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

        void testConstructorAllocatesCapacityInt() {
            IntArray* arr = new IntArray(5);
            t_true(arr->size() == 5);

            delete arr;
            OK("ArrayTest.testConstructorAllocatesCapacityInt");
        }

        void getAndPutWorkInt() {
            IntArray* arr = new IntArray(5);
            int i1 = 5;

            arr->put(4, i1);

            t_true(i1 == arr->get(4));
            t_true(arr->get(4) == i1);

            delete arr;
            OK("ArrayTest.getAndPutWorkInt");
        }

        void putReplacesObjectInt() {
            IntArray* arr = new IntArray(5);

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
            IntArray* arr = new IntArray(5);
            int i1 = 5;

            arr->put(4, i1);

            t_true(arr->indexOf(i1) == 4);

            delete arr;
            OK("ArrayTest.indexOfFindsObjectInt");
        }

        void indexOfReturnsSizeWhenMissingInt() {
            IntArray* arr = new IntArray(5);
            int i1 = 5;

            t_true(arr->indexOf(i1) == arr->size());

            delete arr;
            OK("ArrayTest.indexOfReturnsSizeWhenMissingInt");
        }

        void equalsWorksInOrderInt() {
            IntArray* arr0 = new IntArray(2);
            IntArray* arr1 = new IntArray(2);

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
            IntArray* arr0 = new IntArray(3);
            IntArray* arr1 = new IntArray(2);

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
            IntArray* arr0 = new IntArray(2);
            IntArray* arr1 = new IntArray(2);

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

        void testConstructorAllocatesCapacityFloat() {
            FloatArray* arr = new FloatArray(5);
            t_true(arr->size() == 5);

            delete arr;
            OK("ArrayTest.testConstructorAllocatesCapacityFloat");
        }

        void getAndPutWorkFloat() {
            FloatArray* arr = new FloatArray(5);
            float f1 = 5.0;

            arr->put(4, f1);

            t_true(f1 == arr->get(4));
            t_true(arr->get(4) == f1);

            delete arr;
            OK("ArrayTest.getAndPutWorkFloat");
        }

        void putReplacesObjectFloat() {
            FloatArray* arr = new FloatArray(5);

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
            FloatArray* arr = new FloatArray(5);
            float f1 = 5.0;

            arr->put(4, f1);

            t_true(arr->indexOf(f1) == 4);

            delete arr;
            OK("ArrayTest.indexOfFindsObjectFloat");
        }

        void indexOfReturnsSizeWhenMissingFloat() {
            FloatArray* arr = new FloatArray(5);
            float f1 = 5.0;

            t_true(arr->indexOf(f1) == arr->size());

            delete arr;
            OK("ArrayTest.indexOfReturnsSizeWhenMissingFloat");
        }

        void equalsWorksInOrderFloat() {
            FloatArray* arr0 = new FloatArray(2);
            FloatArray* arr1 = new FloatArray(2);

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
            FloatArray* arr0 = new FloatArray(3);
            FloatArray* arr1 = new FloatArray(2);

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
            FloatArray* arr0 = new FloatArray(2);
            FloatArray* arr1 = new FloatArray(2);

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

        void testConstructorAllocatesCapacityBool() {
            BoolArray* arr = new BoolArray(5);
            t_true(arr->size() == 5);

            delete arr;
            OK("ArrayTest.testConstructorAllocatesCapacityBool");
        }

        void testConstructorInitsToNullptrBool() {
            BoolArray* arr = new BoolArray(5);
            for (int i = 0; i < 5; i++) { t_true(arr->get(i) == nullptr); }

            delete arr;
            OK("ArrayTest.testConstructorInitsToNullptrBool");
        }

        void getAndPutWorkBool() {
            BoolArray* arr = new BoolArray(5);
            bool b1 = true;

            arr->put(4, b1);

            t_true(b1 == arr->get(4));
            t_true(arr->get(4) == b1);

            delete arr;
            OK("ArrayTest.getAndPutWorkBool");
        }

        void putReplacesObjectBool() {
            BoolArray* arr = new BoolArray(5);

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
            BoolArray* arr = new BoolArray(5);
            bool b1 = true;

            arr->put(4, b1);

            t_true(arr->indexOf(b1) == 4);

            delete arr;
            OK("ArrayTest.indexOfFindsObjectBool");
        }

        void indexOfReturnsSizeWhenMissingBool() {
            BoolArray* arr = new BoolArray(5);
            bool b1 = true;

            t_true(arr->indexOf(b1) == arr->size());

            delete arr;
            OK("ArrayTest.indexOfReturnsSizeWhenMissingBool");
        }

        void equalsWorksInOrderBool() {
            BoolArray* arr0 = new BoolArray(2);
            BoolArray* arr1 = new BoolArray(2);

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
            BoolArray* arr0 = new BoolArray(3);
            BoolArray* arr1 = new BoolArray(2);

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
            BoolArray* arr0 = new BoolArray(2);
            BoolArray* arr1 = new BoolArray(2);

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