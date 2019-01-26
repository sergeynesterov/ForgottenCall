#include "logger/Logger.hpp"

#include <pthread.h>

#include <dlt/dlt.h>

#include "logger/private/CDltLoggerContext.hpp"

DLT_IMPORT_CONTEXT( dlt_context )

namespace fc
{
   namespace log
   {
      namespace details
      {
         void do_log( const DltLogLevelType& logLevel, const std::string& prefix, const std::string& str );
      }
   }
}

namespace fc
{
   namespace log
   {
      namespace details
      {
         void info( const std::string& prefix, const std::string& str )
         {
            details::do_log( DLT_LOG_INFO, prefix, str );
         }

         void error( const std::string& prefix, const std::string& str )
         {
            details::do_log( DLT_LOG_FATAL, prefix, str );
         }

         void do_log( const DltLogLevelType& logLevel, const std::string& prefix, const std::string& str )
         {
            CDltLoggerContext::init();

            DLT_LOG( dlt_context, logLevel, DLT_CSTRING( prefix.c_str() ), DLT_CSTRING( str.c_str() ) );
         }
      }
   }
}