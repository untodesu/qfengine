#ifndef SERVER_MODULES_HH
#define SERVER_MODULES_HH
#pragma once

#include "common/module.hh"

namespace server_modules
{
void invoke(qf::ModuleCallback callback);
} // namespace server_modules

#endif // SERVER_MODULES_HH
