#pragma once
#include "����.h"
#include <cflw��ѧ.h>
#include <cflw��ѧ_����.h>
#include <cflw��ѧ_ͼ��.h>
namespace ��ѧ = cflw::��ѧ;
struct S���� {
	��ѧ::S����2 m����;
	��ѧ::S����2 m����;
	��ѧ::S��ɫ mǰ��ɫ;
	��ѧ::S��ɫ m����ɫ;
};
class C���� {
public:
	void f����();
	void f����();
	��ѧ::S����2 m����;
	��ѧ::S����2 m�ٶ�;
	��ѧ::S��ɫ mǰ��ɫ;
	��ѧ::S��ɫ m����ɫ;
	std::byte *mĿ��;
};
class C���ӹ��� {
public:
	struct S���� {
		��ѧ::S����2 m����;
		��ѧ::S����2 m�ٶ�;
		��ѧ::S��ɫ mǰ��ɫ;
		��ѧ::S��ɫ m����ɫ;
	};
	void f��������();
	S���� m����;
	C���� *ma���Ӷ���;
	int m���� = 0;
};