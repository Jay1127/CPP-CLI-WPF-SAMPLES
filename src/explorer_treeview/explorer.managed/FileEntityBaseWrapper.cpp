#include "pch.h"
#include "FileEntityBaseWrapper.h"
#include "ManagedAdapter.h"

namespace Explorer {
	FileEntityBaseWrapper::FileEntityBaseWrapper(explorer::FileEntityBase* entity)
		: entity(entity)
	{
	}

	FileEntityBaseWrapper::~FileEntityBaseWrapper()
	{
		if (entity != nullptr) {
			delete entity;
		}
	}

	String^ FileEntityBaseWrapper::Name::get()
	{
		return NnMHandler::ManagedAdapter::ToString(entity->name());
	}

	String^ FileEntityBaseWrapper::Path::get()
	{
		return NnMHandler::ManagedAdapter::ToString(entity->path());
	}
}
