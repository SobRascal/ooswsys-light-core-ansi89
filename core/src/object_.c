/* SPDX-License-Identifier: Apache-2.0 */
/* Copyright 2026 Jakub Stulir */


#include "core/inc/object_.h"



struct Object_ * new_ ( struct ClassObject const * const classObject,
                        struct CtorParams const  * const args ) {


          struct Object_ * object_;


          if ( ( classObject == 0 ) ||
               ( classObject -> size_ < sizeof ( struct Object_ ) ) ||
               ( classObject -> ctor == 0 ) ) {


                    return 0;


                    }


          object_ = malloc ( classObject -> size_ );


          if ( object_ != 0 ) {


                    object_ -> classObject = classObject;


                    classObject -> ctor ( object_, args );


                    }


          return object_;


          }


void delete_( struct Object_ * const object_ ) {


          if ( object_ == 0 ) {


                    return;


                    }


          if ( ( object_ -> classObject != 0 ) &&
               ( object_ -> classObject -> dtor != 0 ) ) {


                    object_ -> classObject -> dtor ( object_ -> classObject, object_ );


                    }


          free ( object_ );


          }


static void objectCtor ( struct Object_          * const object_,
                         struct CtorParams const * const args ) {


          struct ObjectCtorParams const * const _args =
                    ( struct ObjectCtorParams const * ) args;


          object_ -> objectId = 0;


          if ( _args != 0 ) {


                    object_ -> objectId = _args -> objectId;


                    }


          printf ( "\nhello from object_ ctor\n" );


          return;


          }


static void objectDtor ( struct ClassObject const * const classObject,
                         struct Object_           * const object_ ) {


          ( void ) classObject;
          ( void ) object_;


          printf ( "\nHi from the Object_ destructor\n" );


          return;


          }



static struct ClassObject * makeClass ( void ) {


          struct ClassObject * classObject = malloc ( sizeof ( struct ClassObject ) );


          if ( classObject != 0 ) {


                    classObject -> super_ = classObject;
                    classObject -> size_  = sizeof ( struct Object_ );
                    classObject -> ctor   = objectCtor;
                    classObject -> dtor   = objectDtor;


                    }


          return classObject;


          }



static void dropClass ( struct ClassObject * const classObject ) {


          free ( classObject );


          return;


          }



struct MakeClassObject const makeClassObject = {


          makeClass, dropClass


          };




