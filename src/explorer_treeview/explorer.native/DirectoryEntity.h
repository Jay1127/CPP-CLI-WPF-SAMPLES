#pragma once

#include "stdafx.h"
#include <vector>
#include "FileEntityBase.h"
#include "FileEntity.h"

namespace explorer 
{
	class DirectoryEntity : public FileEntityBase
	{
	public:		
		DirectoryEntity(const string directory_path);

		vector<FileEntityBase> sub_entries() const;
		vector<FileEntity> sub_files() const;
		vector<DirectoryEntity> sub_directories() const;
	};
}

