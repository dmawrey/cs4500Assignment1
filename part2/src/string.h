#pragma once

#include "object.h"

/**
 * An object that contains a series of characters
 */
class String : public Object {
    public:

        /**
         * Creates a new string object from the given string
         * @param str The string that should be the value of this string
         */
        String (const char* str) : Object() {}

        virtual ~String() {}

        /**
         * Provides a hash of the string object. This is done by adding up the character value in the char array
         * @return size_t representing the hash
         */
        virtual size_t hash() {}

        /**
         * Returns true if the two objects are equal in terms of class and contents
         * @param other represents the other given object
         * @return bool, returns true if objects are and contains the same value, else return false
         */
        virtual bool equals(Object* other) {}

        /**
         * Returns the length of the string
         * @return size_t, represents the length of the string
         */
        size_t length() {}

        /**
         * @return The raw value of this string
         */
        const char* value() {}

};