#pragma once
#include "stdafx.h";
#include "FileEntityBase.h"

namespace explorer {
	class FileEntity : public FileEntityBase
	{
	public:
		FileEntity(const string file_path);		

		string extension() const;
	};
}

