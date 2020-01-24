#pragma once

#include "object.h"

/**
 * An array of objects with a fixed size
 */
class ObjectArray: public Object {
    public:

        /**
         * Creates a new object array. All of the elements in the array are initialized to nullptr.
         * @param size The capacity of the array. Should be > 0, otherwise the program will exit.
         */
        ObjectArray(size_t size) : Object() {}

        virtual ~ObjectArray() {}

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
        virtual bool equal(Object* other) {}

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
        size_t indexOf(Object* obj) {}

};

/**
 * An array of strings with a fixed size
 */
class StringArray: public Object {
    public:

        // NOTE: StringArray can be implementing using ObjectArray for code reuse

        /**
         * Creates a new object array. All of the elements in the array are initialized to nullptr.
         * @param size The capacity of the array. Should be > 0, otherwise the program will exit.
         */
        StringArray(size_t size) : Object() {}

        virtual ~StringArray() {}

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
        virtual bool equal(Object* other) {}

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
        void put(size_t i, String* obj) {}

        /**
         * Returns the first occurrence of the given object in the array using the object's equal() method.
         * If the object is not found, size() is returned.
         * @param obj The object to find in the array
         * @return The first index of the object. size() if not found
         */
        size_t indexOf(String* obj) {}

};