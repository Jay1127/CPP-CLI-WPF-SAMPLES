#pragma once
#include "FileEntityBase.h"

using namespace System;

namespace Explorer 
{
	public ref class FileEntityBaseWrapper
	{
	public:
		property String^ Name 
		{
			String^ get();
		}

		property String^ Path 
		{
			String^ get();
		}

	protected:
		FileEntityBaseWrapper(explorer::FileEntityBase* entity);
		~FileEntityBaseWrapper();

		explorer::FileEntityBase* entity;
	};
}

