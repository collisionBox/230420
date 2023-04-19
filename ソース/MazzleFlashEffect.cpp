#include "MazzleFlashEffect.h"
#include "EffectTag.h"

MazzleFlashEffect::MazzleFlashEffect(VECTOR pos, VECTOR dir) :
	EffectBase(EffectTag::Graphic)
{
	handle = LoadEffekseerEffect("data/effect/explosion/爆発1.efkefc", Size);
	this->dir = dir;
	this->pos = pos;
	this->pos = VAdd(this->pos, VScale(this->dir, BarrelHeadLen));// 砲塔先頭にセットする.
	this->pos.y += BarrelHeadHeight;

	playingEffectHandle = PlayEffekseer3DEffect(handle);
	SetPosPlayingEffekseer3DEffect(playingEffectHandle,this->pos.x, this->pos.y, this->pos.z);
	SetSpeedPlayingEffekseer3DEffect(playingEffectHandle, PlayEffectSpeed);
	
	UpdateEffekseer3D();

}

MazzleFlashEffect::~MazzleFlashEffect()
{
	DeleteEffekseerEffect(playingEffectHandle);
}

void MazzleFlashEffect::Update(float deltaTime)
{
	
	if (IsEffekseer3DEffectPlaying(playingEffectHandle) == -1)
	{
		valid = false;
		DeleteEffekseerEffect(playingEffectHandle);
	}

	UpdateEffekseer3D();

}

void MazzleFlashEffect::Play()
{
	DrawEffekseer3D_Draw(playingEffectHandle);
}


