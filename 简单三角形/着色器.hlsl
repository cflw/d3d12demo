struct Sƽ��p {
	float4 mλ�� : SV_POSITION;
	float4 m��ɫ : COLOR0;
};
Sƽ��p fƽ��v(float2 aλ�� : POSITION, float4 a��ɫ : COLOR0) {
	Sƽ��p v���;
	v���.mλ�� = float4(aλ��, 0, 1);
	v���.m��ɫ = a��ɫ;
	return v���;
}
float4 fƽ��p(Sƽ��p a����) : SV_TARGET {
	return a����.m��ɫ;
}