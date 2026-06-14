/* SPDX-License-Identifier: Apache-2.0 */
/* Copyright 2026 Jakub Stulir */

#ifndef OBJECT_A1_H
#define OBJECT_A1_H

#include "core/inc/object_.h"



struct ObjectA1 {


          struct Object_ object_;


          unsigned int arg0;


          unsigned int arg1;


          };



struct ObjectA1CtorParams {


          struct CtorParams ctorParams;


          struct ObjectCtorParams const * objectCtorParams;


          unsigned int arg0;

          unsigned int arg1;


          };



struct ClassA1 {


          struct ClassObject classObject;


          void ( * virtual_method_0 ) ( struct ClassA1 const * const classA1 );


          char virtual_method_0_arg  [ 50 ];


          };



struct MakeClassA1 {


          struct ClassA1 * ( * makeClass ) ( char const * const virtual_method_0_arg );


          void ( * dropClass ) ( struct ClassA1 * const classA1 );


          };



extern struct MakeClassA1 const makeClassA1;




#endif /* OBJECT_A1_H */


