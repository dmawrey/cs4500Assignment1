#pragma once

#include <stddef.h>

/** Root object type all other objects should inherit from */
class Object {
    public:

        virtual ~Object() {}

        /**
         * Provides a hash of this object. If this object is equal to another object, the hash codes should be equal
         * @return The hash code of the object
         */
        virtual size_t hash() {}
        
        /**
         * Returns true if this object is equal to another object
         * @param other The object to compare this object to
         * @return true if the other object is equal to this object; false otherwise
         */                                                                             
        virtual bool equals(Object* other) { return this == other; }                   
                                                                                 
        /** Return a newly allocated string describin the object */                    
        virtual char* to_string() {}                      
                                                                                 
        /** Print to stdout. */                                                        
        virtual void print() {}
};