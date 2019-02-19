#include "图形.h"
#include "常量.h"
#include <cflw图形_dx着色器.h>
namespace 着色器 = cflw::图形::dx着色器;
void C图形::f初始化(HWND a窗口) {
	m三维.f初始化(a窗口);
	三维::C渲染控制 &v渲染控制 = m三维.fg渲染控制();
	三维::C渲染状态 &v渲染状态 = m三维.fg渲染状态();
	三维::C缓冲工厂 &v缓冲工厂 = m三维.fg缓冲工厂();
	着色器::C着色器工厂 v着色器工厂;
	v着色器工厂.f初始化();
	v渲染控制.f重置命令();
	//着色器
	着色器::tp着色器 vs, ps;
	v着色器工厂.f编译顶点着色器(vs, L"着色器.hlsl", L"f平面v");
	v着色器工厂.f编译像素着色器(ps, L"着色器.hlsl", L"f平面p");
	三维::C顶点格式 v顶点格式;
	v顶点格式.f添加(三维::C顶点格式::e位置, 2);
	v顶点格式.f添加(三维::C顶点格式::e颜色, 4);
	//图形管线
	三维::S图形管线参数 v图形管线;
	v图形管线.fs根签名(m三维.fg默认根签名());
	v图形管线.fs图元拓扑类型(三维::E图元拓扑类型::e三角形);
	v图形管线.fs顶点着色器(着色器::fc跨度(vs));
	v图形管线.fs像素着色器(着色器::fc跨度(ps));
	v图形管线.fs输入布局(v顶点格式);
	v图形管线.fs光栅化(v渲染状态.m光栅化.m默认);
	v图形管线.fs混合(v渲染状态.m混合.m开启透明);
	v图形管线.fs深度模板(v渲染状态.m深度模板.m正常深度r);
	m三维.f创建图形管线(m图形管线, v图形管线);
	v渲染控制.fs图形管线(m图形管线.Get());
	//顶点
	struct S顶点 {
		数学::S向量2 m坐标;
		数学::S颜色 m颜色;
	};
	const S顶点 va顶点[] = {
		{数学::S向量2(0, 0.5f), 数学::S颜色(1, 0, 0)},
		{数学::S向量2(0.5f, -0.5f), 数学::S颜色(0, 1, 0)},
		{数学::S向量2(-0.5f, -0.5f), 数学::S颜色(0, 0, 1)}
	};
	v缓冲工厂.f创建顶点(m顶点, va顶点, sizeof(S顶点), sizeof(va顶点));
	//结束
	v渲染控制.f执行命令并等待();
}
void C图形::f销毁() {
	m三维.f销毁();
}
void C图形::f计算() {

}
void C图形::f更新() {

}
void C图形::f显示() {
	三维::C渲染控制 &v渲染控制 = m三维.fg渲染控制();
	v渲染控制.f重置命令();
	v渲染控制.f开始();
	v渲染控制.f清屏();
	v渲染控制.fs图元拓扑(三维::E图元拓扑::e列表三角形);
	v渲染控制.fs顶点缓冲(*m顶点);
	v渲染控制.f绘制(3);
	v渲染控制.f结束();
	v渲染控制.f执行命令并显示();
}