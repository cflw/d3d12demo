#pragma once
#include <cflw数学.h>
#include <cflw图形_d3d12.h>
#include <cflw工具.h>
#include "粒子.h"
namespace 数学 = cflw::数学;
namespace 三维 = cflw::图形::d3d12;
namespace 工具 = cflw::工具;
class C图形 {
public:
	void f初始化(HWND);
	void f销毁();
	void f计算();
	void f更新();
	void f显示();
	三维::C三维 m三维;
	三维::tp根签名 m根签名;
	三维::tp图形管线 m图形管线;
	三维::tp顶点 m顶点;
	三维::tp纹理 m纹理;
	三维::tp常量 m常量;
	std::byte *mp映射 = nullptr;
	C粒子 ma粒子对象[c粒子数量] = {};
	C粒子工厂 m粒子工厂;
	float m时间 = 0;
	float m计时 = 0;
};