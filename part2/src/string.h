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
         * @return The raw value of this string
         */
        const char* value() {}
                                                                                                                                          
        /** Returns 0 if strings are equal, >0 if this string is larger,               
        *  <0 otherwise */                                                            
        int compare(String* tgt) {}                                                                                          
                                                                                 
        /** Number of non \0 characters in this string */                              
        size_t size() {}                                                
                                                                                 
        /** Concatenate the strings, return a new object */                            
        String* concat(String* other) {}                                                                              
                                                                                 
        /** Return a newly allocated char* with this string value */                   
        char* to_string() {}                                  
                                                                                 
        /** Print this string on stdout. */                                            
        void print() {} 
};