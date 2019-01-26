#include "logger/Logger.hpp"
#include "resourcesLoader/ContentLoader.hpp"

int main()
{
   FC_INFO( "Hello world!" );
   FC_ERROR( "Goodbye!" );

	auto content = contentLoader::loadContent(contentLoader::fs::path("resources/content"));
}