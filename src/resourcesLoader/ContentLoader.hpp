#include <iostream>
#include <filesystem>
#include <map>

namespace contentLoader
{
	namespace fs = std::filesystem;

	using Content = std::map<fs::path, std::string>;
	using FileContent = std::pair<fs::path, std::string>;

	Content loadContent(const fs::path& root, const std::string allowExtension = ".txt");
}