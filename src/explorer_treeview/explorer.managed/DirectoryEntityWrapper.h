#pragma once

#include "NativeAdapter.h"
#include "DirectoryEntity.h"
#include "FileEntityBaseWrapper.h"
#include "FileEntityWrapper.h"

namespace Explorer {
	public ref class DirectoryEntityWrapper : public FileEntityBaseWrapper
	{
	public:
		DirectoryEntityWrapper(String^ path);

		property cli::array<FileEntityBaseWrapper^>^ SubEntries {
			cli::array<FileEntityBaseWrapper^>^ get();
		}

		property cli::array<FileEntityWrapper^>^ SubFiles {
			cli::array<FileEntityWrapper^>^ get();
		}

		property cli::array<DirectoryEntityWrapper^>^ SubDirectories {
			cli::array<DirectoryEntityWrapper^>^ get();
		}

	internal:
		DirectoryEntityWrapper(explorer::DirectoryEntity* entity);

	private:
		cli::array<FileEntityBaseWrapper^>^ m_entries;
	};
}

