#include "SpriteRepeat.h"

namespace stickman
{
	SpriteRepeat::SpriteRepeat(void)
	{
		_offset = 0;
		_ratio = 1;
	}


	SpriteRepeat::~SpriteRepeat(void)
	{
	}

	bool SpriteRepeat::initWithSprite(const std::string& filename, const RType& type)
	{
		if (!Node::init())
			return false;

		if (type == RType::HORIZONTAL)
			_direct = Vec2(-1, 0);
		else
			_direct = Vec2(0, -1);
		Sprite* sprite1 = Sprite::create(filename);
		sprite1->setAnchorPoint(Point::ZERO);
		setContentSize(sprite1->getContentSize());
		Size size = getContentSize();
		Sprite* sprite2 = Sprite::create(filename);
		sprite2->setAnchorPoint(Point::ZERO);
		_listSprite.pushBack(sprite1);
		_listSprite.pushBack(sprite2);
		sprite1->setPosition(Point::ZERO);
		sprite2->setPosition(_direct.x * size.width, _direct.y * size.height);
		addChild(sprite1);
		addChild(sprite2);

		return true;
	}

	void SpriteRepeat::setOffset(const float& offset)
	{
		Size size = getContentSize();
		_offset = offset;
		Point pos(_offset * _ratio * _direct.x, _offset * _ratio * _direct.y);
		//float a = ceil(pos.x / size.width);
		pos.x = pos.x - ceil(pos.x / size.width) * size.width * abs(_direct.x);
		pos.y = pos.y - ceil(pos.y / size.height) * size.height * abs(_direct.y);

		for (int i = 0; i < _listSprite.size(); i++)
		{
			Sprite* sprite = _listSprite.at(i);
			sprite->setPositionX(pos.x + i * size.width * abs(_direct.x));
			sprite->setPositionY(pos.y + i * size.height * abs(_direct.y));
		}
	}

	SpriteRepeat* SpriteRepeat::create(const std::string& filename, const RType& type)
	{
		SpriteRepeat* result = new SpriteRepeat();
		if (result && result->initWithSprite(filename, type))
		{
			result->autorelease();
		}
		else {
			delete result;
			result = nullptr;
		}
		return result;
	}

	float SpriteRepeat::getOffset() const
	{
		return _offset;
	}

	void SpriteRepeat::setRatio(const float& ratio)
	{
		_ratio = ratio;
	}

}
