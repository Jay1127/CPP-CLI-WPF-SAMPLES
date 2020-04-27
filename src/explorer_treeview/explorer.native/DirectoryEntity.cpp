#include "stdafx.h"
#include "DirectoryEntity.h"

namespace explorer {

	DirectoryEntity::DirectoryEntity(const string directory_path)
		: FileEntityBase(directory_path)
	{

	}

	vector<FileEntityBase> DirectoryEntity::sub_entries() const
	{
		std::vector<FileEntityBase> entries;
		try
		{
			for (auto entry : filesystem::directory_iterator(path())) 
			{
				try
				{
					if (entry.is_directory()) 
					{
						entries.push_back(DirectoryEntity(entry.path().string()));
					}
					else 
					{
						entries.push_back(FileEntity(entry.path().string()));
					}
				}
				catch (exception e) 
				{

				}
			}
		}
		catch (exception e) 
		{

		}

		return entries;
	}

	vector<FileEntity> DirectoryEntity::sub_files() const
	{
		std::vector<FileEntity> entries;

		for (auto entry : filesystem::directory_iterator(path())) 
		{
			try 
			{
				if (!entry.is_directory()) 
				{
					entries.push_back(FileEntity(entry.path().string()));
				}
			}
			catch (exception e)
			{

			}
		}

		return entries;
	}

	vector<DirectoryEntity> DirectoryEntity::sub_directories() const
	{
		std::vector<DirectoryEntity> entries;

		for (auto entry : filesystem::directory_iterator(path())) 
		{
			try 
			{
				if (entry.is_directory()) 
				{
					entries.push_back(DirectoryEntity(entry.path().string()));
				}
			}
			catch (exception e) 
			{

			}
		}

		return entries;
	}
}