/* SPDX-License-Identifier: Apache-2.0 */
/* Copyright 2026 Jakub Stulir */


#include "core/inc/object_.h"
#include "app/inc/object_b1.h"


#include <string.h>



static void objectB1Ctor ( struct Object_           * const object_,
                           struct CtorParams  const * const args ) {


          struct ObjectB1 * const obj = ( struct ObjectB1 * ) object_;


          struct ObjectB1CtorParams const * const _args =
                    ( struct ObjectB1CtorParams const * ) args;


          if ( ( object_ -> classObject != 0 ) &&
               ( object_ -> classObject -> super_ != 0 ) &&
               ( object_ -> classObject -> super_ -> ctor != 0 ) ) {


                    if ( ( _args != 0 ) && ( _args -> objectCtorParams != 0 ) ) {


                              object_ -> classObject -> super_ -> ctor (
                                        object_,
                                        _args -> objectCtorParams -> ctorParams . this_ );


                              }
                    else {


                              object_ -> classObject -> super_ -> ctor ( object_, 0 );


                              }


                    }


          printf ( "\nhello from ObjectB1 ctor\n" );


          obj -> arg0 = 0;


          if ( _args != 0 ) {


                    obj -> arg0 = _args -> arg0;


                    }


          return;


          }



static void objectB1Dtor ( struct ClassObject const * const classObject,
                           struct Object_           * const object_ ) {


          printf ( "\nHi from the ObjectB1 destructor\n" );


          if ( ( classObject != 0 ) &&
               ( classObject -> super_ != 0 ) &&
               ( classObject -> super_ -> dtor != 0 ) ) {


                    classObject -> super_ -> dtor ( classObject -> super_, object_ );


                    }


          return;


          }



/* virtual method */

static void virtual_method_0 ( struct ClassB1 const * const classB1 ) {


          if ( classB1 == 0 ) {


                    return;


                    }


          printf ( "\nhello from ObjectB1 virtual_method_0\n" );
          printf ( "ObjectB1 says: same object system, different class properties: " );
          printf ( "%s\n", classB1 -> virtual_method_0_arg );


          return;


          }



static struct ClassB1 * makeClass ( char const * const virtual_method_0_arg ) {


          struct ClassB1 * classB1 = malloc ( sizeof ( struct ClassB1 ) );


          if ( classB1 != 0 ) {


                    classB1 -> classObject . super_ = makeClassObject . makeClass ( );


                    if ( classB1 -> classObject . super_ == 0 ) {


                              free ( classB1 );


                              return 0;


                              }


                    classB1 -> classObject . size_  = sizeof ( struct ObjectB1 );
                    classB1 -> classObject . ctor   = objectB1Ctor;
                    classB1 -> classObject . dtor   = objectB1Dtor;


                    classB1 -> virtual_method_0 = virtual_method_0;


                    classB1 -> virtual_method_0_arg [ 0 ] = '\0';


                    if ( virtual_method_0_arg != 0 ) {


                              strncpy ( classB1 -> virtual_method_0_arg,
                                        virtual_method_0_arg,
                                        sizeof ( classB1 -> virtual_method_0_arg ) - 1 );


                              classB1 -> virtual_method_0_arg
                                        [ sizeof ( classB1 -> virtual_method_0_arg ) - 1 ] = '\0';


                              }


                    }


          return classB1;


          }


static void dropClass ( struct ClassB1 * const classB1 ) {


          if ( classB1 == 0 ) {


                    return;


                    }


          makeClassObject . dropClass ( classB1 -> classObject . super_ );

          free ( classB1 );


          return;


          }



struct MakeClassB1 const makeClassB1 = {


          makeClass, dropClass


          };
