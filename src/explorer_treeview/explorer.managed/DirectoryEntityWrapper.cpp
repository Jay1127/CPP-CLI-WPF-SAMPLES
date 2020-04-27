#include "pch.h"
#include "DirectoryEntityWrapper.h"
#include "ManagedAdapter.h"

namespace Explorer 
{
	DirectoryEntityWrapper::DirectoryEntityWrapper(String^ path)
		: FileEntityBaseWrapper(new explorer::DirectoryEntity(NnMHandler::NativeAdapter::ToString(path)))
	{

	}

	DirectoryEntityWrapper::DirectoryEntityWrapper(explorer::DirectoryEntity* entity)
		: FileEntityBaseWrapper(entity)
	{
		
	}

	cli::array<FileEntityBaseWrapper^>^ DirectoryEntityWrapper::SubEntries::get()
	{
		if (m_entries == nullptr) {
			auto directory_entity = static_cast<explorer::DirectoryEntity*>(entity);
			auto sub_entries = directory_entity->sub_entries();

			m_entries = gcnew cli::array<FileEntityBaseWrapper^>((int)sub_entries.size());

			for (int i = 0; i < m_entries->Length; i++)
			{
				auto path = sub_entries[i].path();

				if (std::filesystem::is_directory(path)) 
				{
					m_entries[i] = gcnew DirectoryEntityWrapper(NnMHandler::ManagedAdapter::ToString(sub_entries[i].path()));
				}
				else 
				{
					m_entries[i] = gcnew FileEntityWrapper(NnMHandler::ManagedAdapter::ToString(sub_entries[i].path()));
				}
			}
		}

		return m_entries;
	}

	cli::array<FileEntityWrapper^>^ DirectoryEntityWrapper::SubFiles::get()
	{
		auto directory_entity = static_cast<explorer::DirectoryEntity*>(entity);
		auto sub_entries = directory_entity->sub_files();
		auto entries_converted = gcnew cli::array<FileEntityWrapper^>((int)sub_entries.size());

		for (int i = 0; i < entries_converted->Length; i++)
		{
			entries_converted[i] = gcnew FileEntityWrapper(static_cast<explorer::FileEntity*>(&sub_entries[i]));
		}

		return entries_converted;
	}

	cli::array<DirectoryEntityWrapper^>^ DirectoryEntityWrapper::SubDirectories::get()
	{
		auto directory_entity = static_cast<explorer::DirectoryEntity*>(entity);
		auto sub_entries = directory_entity->sub_directories();
		auto entries_converted = gcnew cli::array<DirectoryEntityWrapper^>((int)sub_entries.size());

		for (int i = 0; i < entries_converted->Length; i++)
		{
			entries_converted[i] = gcnew DirectoryEntityWrapper(static_cast<explorer::DirectoryEntity*>(&sub_entries[i]));
		}

		return entries_converted;
	}
}
