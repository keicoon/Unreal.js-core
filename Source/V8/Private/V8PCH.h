#pragma once

#include "CoreUObject.h"
#include "Engine.h"

#pragma warning( push )
#pragma warning( disable : 4946 )
#pragma warning( disable : 4191 )

PRAGMA_DISABLE_SHADOW_VARIABLE_WARNINGS

#ifndef THIRD_PARTY_INCLUDES_START
#	define THIRD_PARTY_INCLUDES_START
#	define THIRD_PARTY_INCLUDES_END
#endif

THIRD_PARTY_INCLUDES_START
#include "v8.h"
#include <v8-debug.h>
#include <v8-profiler.h>
THIRD_PARTY_INCLUDES_END

PRAGMA_ENABLE_SHADOW_VARIABLE_WARNINGS

#pragma warning( pop )

DECLARE_LOG_CATEGORY_EXTERN(Javascript, Log, All);

struct IJavascriptDebugger
{
	virtual ~IJavascriptDebugger() {}

	virtual void Destroy() = 0;

	static IJavascriptDebugger* Create(int32 InPort, v8::Local<v8::Context> InContext);
};

struct IJavascriptInspector
{
	virtual ~IJavascriptInspector() {}

	virtual void Destroy() = 0;

	static IJavascriptInspector* Create(int32 InPort, v8::Local<v8::Context> InContext);
};