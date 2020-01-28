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
};