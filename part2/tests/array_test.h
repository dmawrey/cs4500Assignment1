#pragma once

#include "../array.h"
#include "../object.h"
#include "../string.h"
#include "test_template.h"
#include "test_util.h"

class ArrayTest : public Test_template {
 public:
  static const int _stressTestVal = 10000;

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
    arrayStressTestStr();

    // Int LIST

    getAndsetWorkInt();
    pushBackInt();
    setReplacesObjectInt();
    indexOfFindsObjectInt();
    indexOfReturnsSizeWhenMissingInt();
    equalsWorksInOrderInt();
    equalsWorksOutOfOrderInt();
    arrayStressTestInt();

    // Float LIST

    getAndsetWorkFloat();
    pushBackFloat();
    setReplacesObjectFloat();
    indexOfFindsObjectFloat();
    indexOfReturnsSizeWhenMissingFloat();
    equalsWorksInOrderFloat();
    equalsWorksOutOfOrderFloat();
    arrayStressTestFloat();

    // Bool LIST

    getAndsetWorkBool();
    pushBackBool();
    setReplacesObjectBool();
    indexOfFindsObjectBool();
    indexOfReturnsSizeWhenMissingBool();
    equalsWorksInOrderBool();
    equalsWorksOutOfOrderBool();
    arrayStressTestBool();
  }

  // OBJECT LIST

  void testConstructorInitsToNullptrObj() {
    ObjectArray* arr = new ObjectArray();
    for (int i = 0; i < 5; i++) {
      t_true(arr->get(i) == nullptr);
    }

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
    t_true(arr->size() == 1);

    delete arr;
    delete str;
    OK("ArrayTest.pushBackObj");
  }

  void setReplacesObjectObj() {
    ObjectArray* arr = new ObjectArray();
    // fix miswritten test
    String* str1 = new String("HI");
    String* str2 = new String("BYE");

    arr->push_back(str1);
    arr->set(0, str2);

    t_true(arr->get(0)->equals(str2));
    t_true(str2->equals(arr->get(0)));

    delete arr;
    delete str1;
    delete str2;
    // end fix
    OK("ArrayTest.setReplacesObjectObj");
  }

  void indexOfFindsObjectObj() {
    ObjectArray* arr = new ObjectArray();
    String* str = new String("HI");

    arr->push_back(str);

    t_true(arr->index_of(str) == 0);

    delete arr;
    delete str;
    OK("ArrayTest.indexOfFindsObjectObj");
  }

  void indexOfReturnsSizeWhenMissingObj() {
    ObjectArray* arr = new ObjectArray();
    String* str = new String("HI");

    t_true(arr->index_of(str) == arr->size());

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
    for (int i = 0; i < 5; i++) {
      t_true(arr->get(i) == nullptr);
    }

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
    t_true(arr->size() == 1);

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

    t_true(arr->index_of(str) == 0);

    delete arr;
    delete str;
    OK("ArrayTest.indexOfFindsObjectStr");
  }

  void indexOfReturnsSizeWhenMissingStr() {
    StringArray* arr = new StringArray();
    String* str = new String("HI");

    t_true(arr->index_of(str) == arr->size());

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

  void arrayStressTestStr() {
    StringArray* arr0 = new StringArray();

    // Testing push_back
    char buffer[100];
    for (int i = 0; i < _stressTestVal; i++) {
      sprintf(buffer, "test%i", i);
      String* currStr = new String(buffer);
      arr0->push_back(currStr);
    }

    // Testing get
    t_true(arr0->size() == _stressTestVal);
    arr0->get(38);
    t_true(strcmp(arr0->get(38)->value(), "test38") == 0);

    // Testing set
    String* test38 = arr0->get(38);
    String* replace38 = new String("replace38");
    arr0->set(38, replace38);
    t_true(strcmp(arr0->get(38)->value(), "replace38") == 0);
    t_true(arr0->get(38)->hash() == replace38->hash());

    // Testing index_of
    t_true(arr0->index_of(test38) >= arr0->size());
    t_true(arr0->index_of(replace38) == 38);

    delete test38;
    for (int i = 0; i < _stressTestVal; i++) {
      delete arr0->get(i);
    }
    delete arr0;
    OK("ArrayTest.arrayStressTestStr");
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
    t_true(arr->size() == 1);

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

    // fix miswritten test
    arr->push_back(1);
    arr->push_back(2);
    arr->push_back(3);
    arr->push_back(4);
    // end fix
    arr->push_back(i1);

    t_true(arr->index_of(i1) == 4);

    delete arr;
    OK("ArrayTest.indexOfFindsObjectInt");
  }

  void indexOfReturnsSizeWhenMissingInt() {
    IntArray* arr = new IntArray();
    int i1 = 5;

    t_true(arr->index_of(i1) == arr->size());

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

  void arrayStressTestInt() {
    IntArray* arr0 = new IntArray();

    // Testing push_back
    for (int i = 0; i < _stressTestVal; i++) {
      arr0->push_back(i);
    }

    // Testing get
    t_true(arr0->size() == _stressTestVal);
    t_true(arr0->get(38) == 38);

    // Testing set
    arr0->set(38, 100038);
    t_true(arr0->get(38) == 100038);

    // Testing index_of
    t_true(arr0->index_of(38) == arr0->size());
    t_true(arr0->index_of(100038) == 38);

    delete arr0;
    OK("ArrayTest.arrayStressTestInt");
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
    t_true(arr->size() == 1);

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

    // fixed miswritten test
    arr->push_back(1);
    arr->push_back(2);
    arr->push_back(3);
    arr->push_back(4);
    // end fix
    arr->push_back(f1);

    t_true(arr->index_of(f1) == 4);

    delete arr;
    OK("ArrayTest.indexOfFindsObjectFloat");
  }

  void indexOfReturnsSizeWhenMissingFloat() {
    FloatArray* arr = new FloatArray();
    float f1 = 5.0;

    t_true(arr->index_of(f1) == arr->size());

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

  void arrayStressTestFloat() {
    FloatArray* arr0 = new FloatArray();

    // Testing push_back
    for (float i = 0.0; i < _stressTestVal; i++) {
      arr0->push_back(i);
    }

    // Testing get
    t_true(arr0->size() == _stressTestVal);
    t_true(arr0->get(38) == 38.0);

    // Testing set
    arr0->set(38, 100038.0);
    t_true(arr0->get(38) == 100038.0);

    // Testing index_of
    t_true(arr0->index_of(38.0) == arr0->size());
    t_true(arr0->index_of(100038.0) == 38);

    delete arr0;
    OK("ArrayTest.arrayStressTestFloat");
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
    t_true(arr->size() == 1);

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

    // fix miswritten test
    arr->push_back(false);
    arr->push_back(false);
    arr->push_back(false);
    arr->push_back(false);
    // end fix
    arr->push_back(b1);

    t_true(arr->index_of(b1) == 4);

    delete arr;
    OK("ArrayTest.indexOfFindsObjectBool");
  }

  void indexOfReturnsSizeWhenMissingBool() {
    BoolArray* arr = new BoolArray();
    bool b1 = true;

    t_true(arr->index_of(b1) == arr->size());

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

  void arrayStressTestBool() {
    BoolArray* arr0 = new BoolArray();

    // Testing push_back
    for (int i = 0; i < _stressTestVal; i++) {
      arr0->push_back(true);
    }

    // Testing get
    t_true(arr0->size() == _stressTestVal);
    t_true(arr0->get(38) == true);

    // Testing set
    arr0->set(38, false);
    t_true(arr0->get(38) == false);

    // Testing index_of
    t_true(arr0->index_of(true) == 0);
    t_true(arr0->index_of(false) == 38);

    delete arr0;

    OK("ArrayTest.arrayStressTestBool");
  }
};
