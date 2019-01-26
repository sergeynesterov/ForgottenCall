#pragma once

namespace fc
{
   namespace log
   {
      class CDltLoggerContext final
      {
      public:
         static void init();

      private:
         CDltLoggerContext();
         ~CDltLoggerContext();
      };
   }
}