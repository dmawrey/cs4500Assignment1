#pragma once

#include "object.h"

/**
 * An array of objects with a dynamic size
 */
class ObjectArray: public Object {
    public:

        /**
         * Creates a new object array. All of the elements in the array are initialized to nullptr.
         * @param size The capacity of the array. Should be > 0, otherwise the program will exit.
         */
        ObjectArray() : Object() {}

        virtual ~ObjectArray() {}

        /**
         * Push back the given object onto the array
         */
        virtual void push_back(Object* obj) {}

        /**
         * Provides a hash of this array. If this array is equal to another array, the hash codes should be equal
         * @return The hash code of the array
         */
        virtual size_t hash() {}

        /**
         * Returns true if this array is equal to another object. If the object is an array they are equal if it has
         * the same elements in the same order as this array.
         * @param other The object to compare this object to
         * @return true if the other object is equal to this object; false otherwise
         */
        virtual bool equals(Object* other) {}

        /**
         * @return The size of the array
         */
        size_t size() {}

        /**
         * Returns the element at the given index. Indices are bound checked.
         * @param i The index of the element to return
         * @return The element at i
         */
        Object* get(size_t i) {};

        /**
         * Sets the object at the given index. Indices are bound checked.
         * @param obj The object that should be
         * @param i
         */
        void put(size_t i, Object* obj) {}

        /**
         * Returns the first occurrence of the given object in the array using the object's equal() method.
         * If the object is not found, size() is returned.
         * @param obj The object to find in the array
         * @return The first index of the object. size() if not found
         */
        size_t index_of(Object* obj) {}

};

/**
 * An array of strings with a dynamic size
 */
class StringArray: public Object {
    public:

        // NOTE: StringArray can be implementing using ObjectArray for code reuse

        /**
         * Creates a new object array. All of the elements in the array are initialized to nullptr.
         * @param size The capacity of the array. Should be > 0, otherwise the program will exit.
         */
        StringArray() : Object() {}

        virtual ~StringArray() {}

        /**
         * Push back the given string onto the array
         */
        virtual void push_back(String* obj) {}

        /**
         * Provides a hash of this array. If this array is equal to another array, the hash codes should be equal
         * @return The hash code of the array
         */
        virtual size_t hash() {}

        /**
         * Returns true if this array is equal to another object. If the object is an array they are equal if it has
         * the same elements in the same order as this array.
         * @param other The object to compare this object to
         * @return true if the other object is equal to this object; false otherwise
         */
        virtual bool equals(Object* other) {}

        /**
         * @return The size of the array
         */
        size_t size() {}

        /**
         * Returns the element at the given index. Indices are bound checked.
         * @param i The index of the element to return
         * @return The element at i
         */
        Object* get(size_t i) {};

        /**
         * Sets the object at the given index. Indices are bound checked.
         * @param givenString The object that should be placed in the array
         * @param i
         */
        void put(size_t i, String* givenString) {}

        /**
         * Returns the first occurrence of the given object in the array using the object's equal() method.
         * If the object is not found, size() is returned.
         * @param givenString The object to find in the array
         * @return The first index of the object. size() if not found
         */
        size_t index_of(String* givenString) {}

};

/**
 * An array of ints with a dynamic size
 */
class IntArray: public Object {
    public:

        // NOTE: IntArray can be implementing using ObjectArray for code reuse

        /**
         * Creates a new object array. All of the elements in the array are initialized to nullptr.
         * @param size The capacity of the array. Should be > 0, otherwise the program will exit.
         */
        IntArray() : Object() {}

        virtual ~IntArray() {}

        /**
         * Push back the given int onto the array
         */
        virtual void push_back(int obj) {}

        /**
         * Provides a hash of this array. If this array is equal to another array, the hash codes should be equal
         * @return The hash code of the array
         */
        virtual size_t hash() {}

        /**
         * Returns true if this array is equal to another object. If the object is an array they are equal if it has
         * the same elements in the same order as this array.
         * @param other The object to compare this object to
         * @return true if the other object is equal to this object; false otherwise
         */
        virtual bool equals(Object* other) {}

        /**
         * @return The size of the array
         */
        size_t size() {}

        /**
         * Returns the element at the given index. Indices are bound checked.
         * @param i The index of the element to return
         * @return The element at i
         */
        int get(size_t i) {};

        /**
         * Sets the object at the given index. Indices are bound checked.
         * @param givenInt The int that should be placed in the array
         * @param i
         */
        void put(size_t i, int givenInt) {}

        /**
         * Returns the first occurrence of the given object in the array using the object's equal() method.
         * If the object is not found, size() is returned.
         * @param givenInt The int to find in the array
         * @return The first index of the object. size() if not found
         */
        size_t index_of(int givenInt) {}
};

/**
 * An array of floats with a dynamic size
 */
class FloatArray: public Object {
    public:

        // NOTE: FloatArray can be implementing using ObjectArray for code reuse

        /**
         * Creates a new object array. All of the elements in the array are initialized to nullptr.
         * @param size The capacity of the array. Should be > 0, otherwise the program will exit.
         */
        FloatArray() : Object() {}

        virtual ~FloatArray() {}

        /**
         * Push back the given float onto the array
         */
        virtual void push_back(float obj) {}

        /**
         * Provides a hash of this array. If this array is equal to another array, the hash codes should be equal
         * @return The hash code of the array
         */
        virtual size_t hash() {}

        /**
         * Returns true if this array is equal to another object. If the object is an array they are equal if it has
         * the same elements in the same order as this array.
         * @param other The object to compare this object to
         * @return true if the other object is equal to this object; false otherwise
         */
        virtual bool equals(Object* other) {}

        /**
         * @return The size of the array
         */
        size_t size() {}

        /**
         * Returns the element at the given index. Indices are bound checked.
         * @param i The index of the element to return
         * @return The element at i
         */
        float get(size_t i) {};

        /**
         * Sets the object at the given index. Indices are bound checked.
         * @param givenFloat The float that should be placed in the array
         * @param i
         */
        void put(size_t i, float givenFloat) {}

        /**
         * Returns the first occurrence of the given object in the array using the object's equal() method.
         * If the object is not found, size() is returned.
         * @param givenFloat The float to find in the array
         * @return The first index of the object. size() if not found
         */
        size_t index_of(float givenFloat) {}
};

/**
 * An array of bool with a dynamic size
 */
class BoolArray: public Object {
    public:

        // NOTE: BoolArray can be implementing using ObjectArray for code reuse

        /**
         * Creates a new object array. All of the elements in the array are initialized to nullptr.
         * @param size The capacity of the array. Should be > 0, otherwise the program will exit.
         */
        BoolArray() : Object() {}

        virtual ~BoolArray() {}

        /**
         * Push back the given bool onto the array
         */
        virtual void push_back(bool obj) {}

        /**
         * Provides a hash of this array. If this array is equal to another array, the hash codes should be equal
         * @return The hash code of the array
         */
        virtual size_t hash() {}

        /**
         * Returns true if this array is equal to another object. If the object is an array they are equal if it has
         * the same elements in the same order as this array.
         * @param other The object to compare this object to
         * @return true if the other object is equal to this object; false otherwise
         */
        virtual bool equals(Object* other) {}

        /**
         * @return The size of the array
         */
        size_t size() {}

        /**
         * Returns the element at the given index. Indices are bound checked.
         * @param i The index of the element to return
         * @return The element at i
         */
        bool get(size_t i) {};

        /**
         * Sets the object at the given index. Indices are bound checked.
         * @param givenBool The boolean that should be placed in the array
         * @param i
         */
        void put(size_t i, bool givenBool) {}

        /**
         * Returns the first occurrence of the given object in the array using the object's equal() method.
         * If the object is not found, size() is returned.
         * @param givenBool The boolean to find in the array
         * @return The first index of the object. size() if not found
         */
        size_t index_of(bool givenBool) {}
};

