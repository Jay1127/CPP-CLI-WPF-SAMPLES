#include "pch.h"
#include "FileEntityWrapper.h"
#include "ManagedAdapter.h"

namespace Explorer 
{
	FileEntityWrapper::FileEntityWrapper(String^ path)
		: FileEntityBaseWrapper(new explorer::FileEntity(NnMHandler::NativeAdapter::ToString(path)))
	{
	}
	FileEntityWrapper::FileEntityWrapper(explorer::FileEntity* entity)
		: FileEntityBaseWrapper(entity)
	{
		
	}

	String^ FileEntityWrapper::Extension::get()
	{
		return NnMHandler::ManagedAdapter::ToString(static_cast<explorer::FileEntity*>(entity)->extension());
	}
}
