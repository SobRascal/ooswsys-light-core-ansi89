/* SPDX-License-Identifier: Apache-2.0 */
/* Copyright 2026 Jakub Stulir */



#include "core/inc/object_.h"
#include "app/inc/object_a1.h"
#include "app/inc/object_b1.h"




int main ( int argc, char ** argv ) {


          struct ClassObject * classObject;
          struct ClassA1     * classA1;
          struct ClassB1     * classB1;


          struct ObjectCtorParams   objectCtorParams;
          struct ObjectA1CtorParams objectA1CtorParams;
          struct ObjectB1CtorParams objectB1CtorParams;


          struct Object_  * obj0;
          struct Object_  * obj1;
          struct Object_  * obj2;
          struct ObjectA1 const * objA1;
          struct ObjectB1 const * objB1;

          char const virtual_method_0_arg_a1 [ 50 ] = "This Class A1 instance A R G U M E N T";
          char const virtual_method_0_arg_b1 [ 160 ] ="Class B1 has only arg0 and a larger virtual method arg.";

          ( void ) argc;
          ( void ) argv;


          classObject = makeClassObject . makeClass ( );
          classA1     = makeClassA1     . makeClass ( virtual_method_0_arg_a1 );
          classB1     = makeClassB1     . makeClass ( virtual_method_0_arg_b1 );


          if ( ( classObject == 0 ) || ( classA1 == 0 ) || ( classB1 == 0 ) ) {


                    makeClassB1     . dropClass ( classB1 );
                    makeClassA1     . dropClass ( classA1 );
                    makeClassObject . dropClass ( classObject );


                    return 1;


                    }


          objectCtorParams . ctorParams . this_ = & objectCtorParams . ctorParams;
          objectCtorParams . objectId           = 12322;


          objectA1CtorParams . ctorParams . this_ = & objectA1CtorParams . ctorParams;
          objectA1CtorParams . objectCtorParams   = & objectCtorParams;
          objectA1CtorParams . arg0               = 25;
          objectA1CtorParams . arg1               = 50;


          objectB1CtorParams . ctorParams . this_ = & objectB1CtorParams . ctorParams;
          objectB1CtorParams . objectCtorParams   = & objectCtorParams;
          objectB1CtorParams . arg0               = 250;


          obj0 = new_ ( classObject, objectCtorParams . ctorParams . this_ );


          obj1 = new_ ( & classA1 -> classObject, objectA1CtorParams . ctorParams . this_ );


          obj2 = new_ ( & classB1 -> classObject, objectB1CtorParams . ctorParams . this_ );


          if ( ( obj0 == 0 ) || ( obj1 == 0 ) || ( obj2 == 0 ) ) {


                    delete_ ( obj0 );
                    delete_ ( obj1 );
                    delete_ ( obj2 );


                    makeClassB1     . dropClass ( classB1 );
                    makeClassA1     . dropClass ( classA1 );
                    makeClassObject . dropClass ( classObject );


                    return 1;


                    }


          objA1 = ( struct ObjectA1 const * ) obj1;
          objB1 = ( struct ObjectB1 const * ) obj2;


          printf ( "\nsize of Object_ %d\n", ( int ) sizeof ( struct Object_ ) );
          printf ( "\nsize of ObjectA1 %d\n", ( int ) sizeof ( struct ObjectA1 ) );
          printf ( "\nsize of ObjectB1 %d\n", ( int ) sizeof ( struct ObjectB1 ) );
          printf ( "\nsize of ClassA1 %d\n", ( int ) sizeof ( struct ClassA1 ) );
          printf ( "\nsize of ClassB1 %d\n", ( int ) sizeof ( struct ClassB1 ) );
          printf ( "\nobjectId of obj0 %u\n", obj0 -> objectId );
          printf ( "\narg0 of objA1 %u\n", objA1 -> arg0 );
          printf ( "\narg1 of objA1 %u\n", objA1 -> arg1 );
          printf ( "\narg0 of objB1 %u\n", objB1 -> arg0 );

          classA1 -> virtual_method_0 ( classA1 );
          classB1 -> virtual_method_0 ( classB1 );


          delete_ ( obj0 );
          delete_ ( obj1 );
          delete_ ( obj2 );


          makeClassB1     . dropClass ( classB1 );
          makeClassA1     . dropClass ( classA1 );
          makeClassObject . dropClass ( classObject );


          return 0;


          }
