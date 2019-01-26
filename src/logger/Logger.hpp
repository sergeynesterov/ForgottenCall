#pragma once

#include <string>
#include <string_view>

#define FC_INFO( str ) do { \
   MAKE_PREFIX() \
   fc::log::details::info( logPrefix, str ); \
} while (0)

#define FC_ERROR( str ) do { \
   MAKE_PREFIX() \
   fc::log::details::error( logPrefix, str ); \
} while (0)

#define MAKE_PREFIX() \
   std::string_view filePrefix( __FILE__); \
   filePrefix.remove_prefix( std::min( filePrefix.rfind( "src" ), filePrefix.size() ) ); \
   std::string logPrefix( std::string( filePrefix ) + "::" + std::string( __FUNCTION__ ) + "()::" + std::to_string( __LINE__ ) );

namespace fc
{
   namespace log
   {
      namespace details
      {
         void info( const std::string& prefix, const std::string& str );
         void error( const std::string& prefix, const std::string& str );
      }
   }
}