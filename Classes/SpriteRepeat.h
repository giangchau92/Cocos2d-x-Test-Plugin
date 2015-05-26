#pragma once
#include <cocos2d.h>
#include <string>

USING_NS_CC;

namespace stickman
{
	class SpriteRepeat : public Node
	{
	public:
		enum RType
		{
			HORIZONTAL,
			VERTICAL
		};
		SpriteRepeat(void);
		~SpriteRepeat(void);

		bool initWithSprite(const std::string& filename, const RType& type);
		void setOffset(const float& offset);
		float getOffset() const;
		void setRatio(const float& ratio);

		static SpriteRepeat* create(const std::string& filename, const RType& type);
	private:
		RType _type;
		Vec2 _direct;
		float _ratio;
		float _offset;
		Vector<Sprite*> _listSprite;
	};
}

