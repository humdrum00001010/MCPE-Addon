#pragma once
#ifndef MCPELAUNCHER_H_
#define MCPELAUNCHER_H_
#include <dlfcn.h>
extern "C" {
void MSHookFunction(void*, void*, void**);
};
#endif