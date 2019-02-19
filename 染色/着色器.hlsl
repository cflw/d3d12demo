cbuffer cb0 : register(b0) {
	float2 g窗口大小;
	float g子弹半径;
}
Texture2D g纹理 : register(t0);
SamplerState g采样 : register(s0);
struct S染色v {
	float2 m位置 : POSITION;
	float2 m方向 : NORMAL;
	float4 m颜色0 : COLOR0;
	float4 m颜色1 : COLOR1;
};
struct S染色p {
	float4 m位置 : SV_POSITION;
	float4 m颜色0 : COLOR0;
	float4 m颜色1 : COLOR1;
	float2 m纹理 : TEXCOORD;
};
S染色v f染色v(S染色v a) {
	return a;
}
S染色p f生成(S染色v a输入, float x, float y) {
	float s = sin(a输入.m方向.x);
	float c = cos(a输入.m方向.x);
	S染色p v;
	v.m位置.x = x * c - y * s;
	v.m位置.x *= g子弹半径;
	v.m位置.x += a输入.m位置.x;
	v.m位置.x /= g窗口大小.x;
	v.m位置.y = x * s + y * c;
	v.m位置.y *= g子弹半径;
	v.m位置.y += a输入.m位置.y;
	v.m位置.y /= g窗口大小.y;
	v.m位置.z = 0;
	v.m位置.w = 1;
	v.m颜色0 = a输入.m颜色0;
	v.m颜色1 = a输入.m颜色1;
	v.m纹理.x = (x + 1) * 0.5f;
	v.m纹理.y = (1 - y) * 0.5f;
	return v;
}
[maxvertexcount(4)]
void f染色g(point S染色v a输入[1], inout TriangleStream<S染色p> a输出) {
	a输出.Append(f生成(a输入[0], -1, 1));
	a输出.Append(f生成(a输入[0], 1, 1));
	a输出.Append(f生成(a输入[0], -1, -1));
	a输出.Append(f生成(a输入[0], 1, -1));
}
float4 f染色p(S染色p a输入) : SV_TARGET {
	float4 v纹理色 = g纹理.Sample(g采样, a输入.m纹理);
	if (v纹理色.z <= 0) {
		discard;
	}
	float4 v前景色 = a输入.m颜色0 * v纹理色.x;
	float4 v背景色 = a输入.m颜色1 * v纹理色.y;
	float v透明度 = v前景色.a + v背景色.a;
	if (v透明度 <= 0) {
		discard;
	}
	float4 v输出色 = v背景色 + v前景色;
	v输出色 = lerp(v输出色, v前景色, v纹理色.x);
	v输出色.a = v透明度 * v纹理色.z;
	return v输出色;
}