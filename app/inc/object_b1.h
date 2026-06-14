/* SPDX-License-Identifier: Apache-2.0 */
/* Copyright 2026 Jakub Stulir */

#ifndef OBJECT_B1_H
#define OBJECT_B1_H

#include "core/inc/object_.h"



struct ObjectB1 {


          struct Object_ object_;


          unsigned int arg0;


          };



struct ObjectB1CtorParams {


          struct CtorParams ctorParams;


          struct ObjectCtorParams const * objectCtorParams;


          unsigned int arg0;


          };



struct ClassB1 {


          struct ClassObject classObject;


          void ( * virtual_method_0 ) ( struct ClassB1 const * const classB1 );


          char virtual_method_0_arg  [ 160 ];


          };



struct MakeClassB1 {


          struct ClassB1 * ( * makeClass ) ( char const * const virtual_method_0_arg );


          void ( * dropClass ) ( struct ClassB1 * const classB1 );


          };



extern struct MakeClassB1 const makeClassB1;




#endif /* OBJECT_B1_H */
