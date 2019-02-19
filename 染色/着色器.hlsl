cbuffer cb0 : register(b0) {
	float2 g���ڴ�С;
	float g�ӵ��뾶;
}
Texture2D g���� : register(t0);
SamplerState g���� : register(s0);
struct SȾɫv {
	float2 mλ�� : POSITION;
	float2 m���� : NORMAL;
	float4 m��ɫ0 : COLOR0;
	float4 m��ɫ1 : COLOR1;
};
struct SȾɫp {
	float4 mλ�� : SV_POSITION;
	float4 m��ɫ0 : COLOR0;
	float4 m��ɫ1 : COLOR1;
	float2 m���� : TEXCOORD;
};
SȾɫv fȾɫv(SȾɫv a) {
	return a;
}
SȾɫp f����(SȾɫv a����, float x, float y) {
	float s = sin(a����.m����.x);
	float c = cos(a����.m����.x);
	SȾɫp v;
	v.mλ��.x = x * c - y * s;
	v.mλ��.x *= g�ӵ��뾶;
	v.mλ��.x += a����.mλ��.x;
	v.mλ��.x /= g���ڴ�С.x;
	v.mλ��.y = x * s + y * c;
	v.mλ��.y *= g�ӵ��뾶;
	v.mλ��.y += a����.mλ��.y;
	v.mλ��.y /= g���ڴ�С.y;
	v.mλ��.z = 0;
	v.mλ��.w = 1;
	v.m��ɫ0 = a����.m��ɫ0;
	v.m��ɫ1 = a����.m��ɫ1;
	v.m����.x = (x + 1) * 0.5f;
	v.m����.y = (1 - y) * 0.5f;
	return v;
}
[maxvertexcount(4)]
void fȾɫg(point SȾɫv a����[1], inout TriangleStream<SȾɫp> a���) {
	a���.Append(f����(a����[0], -1, 1));
	a���.Append(f����(a����[0], 1, 1));
	a���.Append(f����(a����[0], -1, -1));
	a���.Append(f����(a����[0], 1, -1));
}
float4 fȾɫp(SȾɫp a����) : SV_TARGET {
	float4 v����ɫ = g����.Sample(g����, a����.m����);
	if (v����ɫ.z <= 0) {
		discard;
	}
	float4 vǰ��ɫ = a����.m��ɫ0 * v����ɫ.x;
	float4 v����ɫ = a����.m��ɫ1 * v����ɫ.y;
	float v͸���� = vǰ��ɫ.a + v����ɫ.a;
	if (v͸���� <= 0) {
		discard;
	}
	float4 v���ɫ = v����ɫ + vǰ��ɫ;
	v���ɫ = lerp(v���ɫ, vǰ��ɫ, v����ɫ.x);
	v���ɫ.a = v͸���� * v����ɫ.z;
	return v���ɫ;
}