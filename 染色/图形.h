#pragma once
#include <cflw��ѧ.h>
#include <cflwͼ��_d3d12.h>
#include <cflw����.h>
#include "����.h"
namespace ��ѧ = cflw::��ѧ;
namespace ��ά = cflw::ͼ��::d3d12;
namespace ���� = cflw::����;
class Cͼ�� {
public:
	void f��ʼ��(HWND);
	void f����();
	void f����();
	void f����();
	void f��ʾ();
	��ά::C��ά m��ά;
	��ά::tp��ǩ�� m��ǩ��;
	��ά::tpͼ�ι��� mͼ�ι���;
	��ά::tp���� m����;
	��ά::tp���� m����;
	��ά::tp���� m����;
	std::byte *mpӳ�� = nullptr;
	C���� ma���Ӷ���[c��������] = {};
	C���ӹ��� m���ӹ���;
	float mʱ�� = 0;
	float m��ʱ = 0;
};