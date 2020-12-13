cbuffer cb0 : register(b0) {
	float2 g窗口;
}
struct S二维p {
	float4 m位置: SV_POSITION;
	float4 m颜色: COLOR0;
};
S二维p f二维v(float2 a位置: POSITION, float4 a颜色: COLOR0) {
	S二维p v;
	v.m位置 = float4(a位置, 0, 1);
	v.m位置.x /= g窗口.x;
	v.m位置.y /= g窗口.y;
	v.m颜色 = a颜色;
	return v;
}
float4 f二维p(S二维p i) : SV_TARGET {
	return i.m颜色;
}