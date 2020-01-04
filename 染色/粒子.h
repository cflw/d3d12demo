#pragma once
#include "常量.h"
#include <cflw数学.h>
#include <cflw数学_向量.h>
#include <cflw数学_图形.h>
namespace 数学 = cflw::数学;
struct S粒子 {
	数学::S向量2 m坐标;
	数学::S向量2 m方向;
	数学::S颜色 m前景色;
	数学::S颜色 m背景色;
};
class C粒子 {
public:
	void f计算();
	void f复制();
	数学::S向量2 m坐标;
	数学::S向量2 m速度;
	数学::S颜色 m前景色;
	数学::S颜色 m背景色;
	std::byte *m目标;
};
class C粒子工厂 {
public:
	struct S参数 {
		数学::S向量2 m坐标;
		数学::S向量2 m速度;
		数学::S颜色 m前景色;
		数学::S颜色 m背景色;
	};
	void f产生粒子();
	S参数 m参数;
	C粒子 *ma粒子对象;
	int m索引 = 0;
};