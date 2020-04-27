#include "stdafx.h"
#include "FileEntity.h"

explorer::FileEntity::FileEntity(const string file_path)
	: FileEntityBase(file_path)
{

}

string explorer::FileEntity::extension() const
{
	return m_entry.path().extension().string();
}