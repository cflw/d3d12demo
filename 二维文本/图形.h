﻿#pragma once
#include <cflw数学.h>
#include <cflw图形_d3d12.h>
#include <cflw图形_d3d11上12.h>
#include <cflw图形_d2d.h>
namespace 数学 = cflw::数学;
namespace 三维 = cflw::图形::d3d12;
namespace 旧三维 = cflw::图形::d3d11上12;
namespace 二维 = cflw::图形::d2d;
class C图形 {
public:
	void f初始化(HWND);
	void f销毁();
	void f计算();
	void f更新();
	void f显示();
	三维::C三维 m三维;
	旧三维::C三维 m旧三维;
	二维::C二维 m二维;
	三维::tp图形管线 m图形管线;
	三维::tp顶点 m顶点;
	二维::tp画图形 m画图形;
	二维::tp画文本 m画文本;
};