#pragma once
#include <msclr\marshal_cppstd.h>

using namespace System;

namespace NnMHandler {
	ref class NativeAdapter
	{
	public:
		static std::string ToString(String^ value)
		{
			return msclr::interop::marshal_as<std::string>(value);
		}
	};
}

