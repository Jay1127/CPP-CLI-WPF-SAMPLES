#include "stdafx.h"
#include "FileEntityBase.h"

namespace explorer {

    FileEntityBase::FileEntityBase(const string entry_path)
        : m_entry(filesystem::directory_entry(entry_path))
    {
    }

    FileEntityBase::~FileEntityBase()
    {
    }

    string FileEntityBase::name() const
    {
        auto path = m_entry.path();

        if (filesystem::_Is_drive_prefix(path.c_str()))
            return this->path();
        else
            return m_entry.path().filename().string();
    }

    string FileEntityBase::path() const
    {
        return m_entry.path().string();
    }
}
