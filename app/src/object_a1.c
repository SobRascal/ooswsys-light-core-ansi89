/* SPDX-License-Identifier: Apache-2.0 */
/* Copyright 2026 Jakub Stulir */


#include "core/inc/object_.h"
#include "app/inc/object_a1.h"


#include <string.h>



static void objectA1Ctor ( struct Object_          * const object_,
                           struct CtorParams const * const args ) {


          struct ObjectA1 * const obj = ( struct ObjectA1 * ) object_;


          struct ObjectA1CtorParams const * const _args =
                    ( struct ObjectA1CtorParams const * ) args;


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


          printf ( "\nhello from ObjectA1 ctor\n" );


          obj -> arg0 = 0;


          obj -> arg1 = 0;


          if ( _args != 0 ) {


                    obj -> arg0 = _args -> arg0;


                    obj -> arg1 = _args -> arg1;


                    }


          return;


          }



static void objectA1Dtor ( struct ClassObject const * const classObject,
                           struct Object_           * const object_ ) {


          printf ( "\nHi from the ObjectA1 destructor\n" );


          if ( ( classObject != 0 ) &&
               ( classObject -> super_ != 0 ) &&
               ( classObject -> super_ -> dtor != 0 ) ) {


                    classObject -> super_ -> dtor ( classObject -> super_, object_ );


                    }


          return;


          }



/* virtual method */

static void virtual_method_0 ( struct ClassA1 const * const classA1 ) {


          if ( classA1 == 0 ) {


                    return;


                    }


          printf ( "\nhello from ObjectA1 virtual_method_0\n" );
          printf ( "ObjectA1 says: this is an argument for this class instance: " );
          printf ( "%s\n", classA1 -> virtual_method_0_arg );


          return;


          }



static struct ClassA1 * makeClass ( char const * const virtual_method_0_arg ) {


          struct ClassA1 * classA1 = malloc ( sizeof ( struct ClassA1 ) );


          if ( classA1 != 0 ) {


                    classA1 -> classObject . super_ = makeClassObject . makeClass ( );


                    if ( classA1 -> classObject . super_ == 0 ) {


                              free ( classA1 );


                              return 0;


                              }


                    classA1 -> classObject . size_  = sizeof ( struct ObjectA1 );
                    classA1 -> classObject . ctor   = objectA1Ctor;
                    classA1 -> classObject . dtor   = objectA1Dtor;


                    classA1 -> virtual_method_0 = virtual_method_0;


                    classA1 -> virtual_method_0_arg [ 0 ] = '\0';


                    if ( virtual_method_0_arg != 0 ) {


                              strncpy ( classA1 -> virtual_method_0_arg,
                                        virtual_method_0_arg,
                                        sizeof ( classA1 -> virtual_method_0_arg ) - 1 );


                              classA1 -> virtual_method_0_arg
                                        [ sizeof ( classA1 -> virtual_method_0_arg ) - 1 ] = '\0';


                              }


                    }


          return classA1;


          }


static void dropClass ( struct ClassA1 * const classA1 ) {


          if ( classA1 == 0 ) {


                    return;


                    }


          makeClassObject . dropClass ( classA1 -> classObject . super_ );

          free ( classA1 );


          return;


          }



struct MakeClassA1 const makeClassA1 = {


          makeClass, dropClass


          };
