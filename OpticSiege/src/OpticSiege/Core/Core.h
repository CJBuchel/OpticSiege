#pragma once

#include "ops_pch.h"

#define OPS_EXPAND_MACRO(x) x
#define OPS_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define OPS_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }