#include "resourcesLoader/ContentLoader.hpp"

#include <fstream>
#include <future>

#include "logger/Logger.hpp"

namespace contentLoader
{
	
	std::pair<fs::path, std::string> readFile(const fs::path& path);

	using returnType = std::future<std::pair<fs::path, std::string>>;

	Content loadContent(const fs::path& root, const std::string allowExtension)
	{
		auto needToRead = [&allowExtension](const fs::directory_entry& it) -> bool
		{
			return !it.is_directory()
				&& (allowExtension == it.path().extension());
		};

		std::vector<returnType> resultsReads;

		fs::recursive_directory_iterator rootEntry(root);
		for (auto it : rootEntry)
		{
			if(needToRead(it))
			{
				resultsReads.push_back(std::async(readFile, it.path()));
			}
		}
		Content loading;
		for (auto& it : resultsReads)
		{
			loading.insert(it.get());
		}

		return loading;
	}

	std::pair<fs::path, std::string> readFile(const fs::path& path)
	{
		FC_INFO("reading...  " + path.native());

		std::ifstream streamBuffer(path.filename());

		std::string content;

		if(streamBuffer.is_open())
		{
			for (std::string step; std::getline(streamBuffer, step); )
			{
				content.append(step);
			}
			
			return std::make_pair(path, content);
		}
		else
		{
			return std::make_pair(path, "File is not opened!");
		}
	}
}