#include "logger/private/CDltLoggerContext.hpp"

#include <pthread.h>

#include <dlt/dlt.h>

DLT_DECLARE_CONTEXT( dlt_context )

namespace fc
{
   namespace log
   {
      void CDltLoggerContext::init()
      {
         static const CDltLoggerContext dltContext;
      }

      CDltLoggerContext::CDltLoggerContext()
      {
         DLT_REGISTER_APP( "FC", "ForgottenCall" );
         DLT_REGISTER_CONTEXT( dlt_context, "MAIN", "Game logic" );
      }

      CDltLoggerContext::~CDltLoggerContext()
      {
         DLT_UNREGISTER_CONTEXT( dlt_context );
         DLT_UNREGISTER_APP();
      }
   }
}