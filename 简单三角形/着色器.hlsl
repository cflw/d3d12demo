struct S平面p {
	float4 m位置 : SV_POSITION;
	float4 m颜色 : COLOR0;
};
S平面p f平面v(float2 a位置 : POSITION, float4 a颜色 : COLOR0) {
	S平面p v输出;
	v输出.m位置 = float4(a位置, 0, 1);
	v输出.m颜色 = a颜色;
	return v输出;
}
float4 f平面p(S平面p a输入) : SV_TARGET {
	return a输入.m颜色;
}