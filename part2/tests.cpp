#include "tests/object_test.h"
#include "tests/string_test.h"
#include "tests/array_test.h"

int main() {
    ObjectTest objectTest;
    StringTest stringTest;
    ArrayTest arrayTest;

    objectTest.run();
    stringTest.run();
    arrayTest.run();
}