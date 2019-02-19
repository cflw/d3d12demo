#include <time.h>
#include <random>
#include <mutex>
#include "粒子.h"
void C粒子::f计算() {
	m坐标 += m速度 * c帧秒;
}
void C粒子::f复制() {
	S粒子 &v目标 = (S粒子 &)*m目标;
	v目标.m坐标 = m坐标;
	v目标.m方向.x = m速度.fg方向r();
	v目标.m前景色 = m前景色;
	v目标.m背景色 = m背景色;
}

void C粒子工厂::f产生粒子() {
	C粒子 &v粒子 = ma粒子对象[m索引++];
	v粒子.m坐标 = m参数.m坐标;
	v粒子.m速度 = m参数.m速度;
	v粒子.m前景色 = m参数.m前景色;
	v粒子.m背景色 = m参数.m背景色;
	if (m索引 >= c粒子数量) {
		m索引 = 0;
	}
}