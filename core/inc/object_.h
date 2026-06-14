/* SPDX-License-Identifier: Apache-2.0 */
/* Copyright 2026 Jakub Stulir */

#ifndef OBJECT_H
#define OBJECT_H



#include <stdlib.h>
#include <stdio.h>



struct Object_ {


          struct ClassObject const * classObject;


          unsigned int objectId;


          };



struct CtorParams {


          struct CtorParams const * this_;


          };



struct ObjectCtorParams {


          struct CtorParams ctorParams;


          unsigned int objectId;


          };



struct ClassObject {


          struct ClassObject * super_;


          size_t size_;


          void ( * ctor ) ( struct Object_          * const object_,
                            struct CtorParams const * const args );


          void ( * dtor ) ( struct ClassObject const * const classObject,
                            struct Object_           * const object_ );


          };



extern struct Object_ * new_ ( struct ClassObject const * const classObject,
                               struct CtorParams const  * const args );



extern void delete_ ( struct Object_ * const object_ );



struct MakeClassObject {


          struct ClassObject * ( * makeClass ) ( void );


          void ( * dropClass ) ( struct ClassObject * const classObject );


          };



extern struct MakeClassObject const makeClassObject;



#endif /* OBJECT_H */


