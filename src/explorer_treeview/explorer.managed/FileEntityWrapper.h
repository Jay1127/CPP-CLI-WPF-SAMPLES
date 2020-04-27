#pragma once

#include "NativeAdapter.h"
#include "FileEntity.h"
#include "FileEntityBaseWrapper.h"

using namespace System;

namespace Explorer 
{
	public ref class FileEntityWrapper : public FileEntityBaseWrapper
	{		
	public:		
		FileEntityWrapper(String^ path);

		property String^ Extension 
		{
			String^ get();
		}

	internal:
		FileEntityWrapper(explorer::FileEntity* entity);
	};
}
