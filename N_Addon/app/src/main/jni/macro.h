//
// Created by humdr on 2017-01-08.
//

#ifndef N_ADDON_MACRO_H
#define N_ADDON_MACRO_H
#define VTABLE_PADDING 8
#define access(ret, target, offset) (*(ret*)(((unsigned int)target) + offset))
#define vfunction(ret, target, offset, ...) ((ret(*)(__VA_ARGS__))access(void*, access(void**, target, 0), offset))
#endif //N_ADDON_MACRO_H
