#pragma once
#include <string>

using namespace System;

namespace NnMHandler {
	ref class ManagedAdapter
	{
	public:
		static String^ ToString(std::string value)
		{
			return %String(value.c_str());
		}
	};
}

