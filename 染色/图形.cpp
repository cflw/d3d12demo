﻿#include <execution>
#include <cflw图形_dx着色器.h>
#include "图形.h"
#include "常量.h"
namespace 着色器 = cflw::图形::dx着色器;
constexpr size_t c粒子数据大小 = sizeof(S粒子) * c粒子数量;
void C图形::f初始化(HWND a窗口) {
	m三维.f初始化(a窗口);
	三维::C渲染控制 &v渲染控制 = m三维.fg渲染控制();
	三维::C渲染状态 &v渲染状态 = m三维.fg渲染状态();
	三维::C缓冲工厂 &v缓冲工厂 = m三维.fg缓冲工厂();
	三维::C纹理工厂 &v纹理工厂 = m三维.fg纹理工厂();
	着色器::C着色器工厂 v着色器工厂;
	v着色器工厂.f初始化();
	v渲染控制.f重置命令();
	//根签名
	三维::C根签名参数 v根签名;
	v根签名.f添加描述符(三维::C根签名参数::E类型::e常量缓冲视图, 0, 0, 三维::E着色器::e全部);
	v根签名.f添加范围(三维::C根签名参数::E类型::e着色器资源视图, 1, 0, 0, 三维::c描述符范围默认偏移, 三维::E着色器::e全部);
	v根签名.f添加采样器(v渲染状态.m采样器.m纹理, 0, 0, 三维::E着色器::e全部);
	m三维.f创建根签名(m根签名, v根签名);
	v渲染控制.fs根签名(m根签名.Get());
	//着色器
	着色器::tp着色器 vs, gs, ps;
	v着色器工厂.f编译顶点着色器(vs, L"着色器.hlsl", L"f染色v");
	v着色器工厂.f编译几何着色器(gs, L"着色器.hlsl", L"f染色g");
	v着色器工厂.f编译像素着色器(ps, L"着色器.hlsl", L"f染色p");
	三维::C顶点格式 v顶点格式;
	v顶点格式.f添加(三维::C顶点格式::e位置, 2);
	v顶点格式.f添加(三维::C顶点格式::e法线, 2);
	v顶点格式.f添加(三维::C顶点格式::e颜色, 4);
	v顶点格式.f添加(三维::C顶点格式::e颜色, 4);
	//图形管线
	三维::S图形管线参数 v图形管线;
	v图形管线.fs根签名(m根签名.Get());
	v图形管线.fs图元拓扑类型(三维::E图元拓扑类型::e点);
	v图形管线.fs顶点着色器(着色器::fc跨度(vs));
	v图形管线.fs几何着色器(着色器::fc跨度(gs));
	v图形管线.fs像素着色器(着色器::fc跨度(ps));
	v图形管线.fs输入布局(v顶点格式);
	v图形管线.fs光栅化(v渲染状态.m光栅化.m默认);
	v图形管线.fs混合(v渲染状态.m混合.m颜色叠加);
	v图形管线.fs深度模板(v渲染状态.m深度模板.m正常深度r);
	m三维.f创建图形管线(m图形管线, v图形管线);
	v渲染控制.fs图形管线(m图形管线.Get());
	//顶点
	v缓冲工厂.f创建顶点(m顶点, nullptr, sizeof(S粒子), c粒子数据大小);
	m顶点->m资源->Map(0, nullptr, (void**)&mp映射);
	//纹理
	v纹理工厂.f从文件创建纹理资源视图(m纹理, L"子弹.png");
	//常量
	struct S常量 {
		数学::S向量2 m窗口大小;
		float m粒子大小;
	} v常量 = {
		数学::S向量2(c基础宽度, c基础高度),
		16
	};
	v缓冲工厂.f创建常量(m常量, &v常量, sizeof(v常量), sizeof(v常量));
	//粒子
	int v偏移 = 0;
	for (C粒子 &v粒子 : ma粒子对象) {
		v粒子.m目标 = mp映射 + v偏移;
		v偏移 += sizeof(S粒子);
	}
	m粒子工厂.ma粒子对象 = ma粒子对象;
	m粒子工厂.m参数.m坐标 = 数学::S向量2::c零;
	m粒子工厂.m参数.m背景色 = 数学::S颜色::c白;
	//结束
	v渲染控制.f执行命令并等待();
}
void C图形::f销毁() {
	m三维.f销毁();
}
void C图形::f计算() {
	m时间 += c帧秒;
	m计时 += c帧秒;
	//产生粒子
	if (m计时 >= 0.01f) {
		m计时 = 0;
		const float v方向 = m时间 * 10;
		m粒子工厂.m参数.m速度 = 数学::S向量2::fc方向r(100, v方向);
		m粒子工厂.m参数.m前景色 = 数学::S颜色::fc彩虹(m时间);
		m粒子工厂.f产生粒子();
	}
	//计算
	std::for_each(std::execution::par,
		std::begin(ma粒子对象), std::end(ma粒子对象),
		std::bind(&C粒子::f计算, std::placeholders::_1));
}
void C图形::f更新() {
	std::for_each(std::execution::par_unseq,
		std::begin(ma粒子对象), std::end(ma粒子对象),
		std::bind(&C粒子::f复制, std::placeholders::_1));
}
void C图形::f显示() {
	三维::C渲染控制 &v渲染控制 = m三维.fg渲染控制();
	v渲染控制.f重置命令();
	v渲染控制.f开始();
	v渲染控制.f清屏();
	v渲染控制.fs根签名(m根签名.Get());
	v渲染控制.fs图形管线(m图形管线.Get());
	v渲染控制.fs图元拓扑(三维::E图元拓扑::e列表点);
	v渲染控制.fs顶点缓冲(*m顶点);
	v渲染控制.fs常量缓冲(0, *m常量);
	v渲染控制.fs描述符表(1, *m纹理);
	v渲染控制.f绘制(c粒子数量);
	v渲染控制.f结束();
	v渲染控制.f执行命令并显示();
}