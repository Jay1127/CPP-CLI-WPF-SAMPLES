#pragma once
#include "stdafx.h"

namespace explorer {
	class FileEntityBase
	{
	public:
		FileEntityBase(const string entry_path);
		virtual ~FileEntityBase();
		string name() const;
		string path() const;

	protected:
		std::filesystem::directory_entry m_entry;
	};
}

