#ifndef _Enemy_
#define _Enemy_

#include "cocos2d.h"
#include "Utility/Tags.h"
#include "Utility/XHelper.h"
USING_NS_CC;


enum EnemyType
{
	Run,
	Jump,
	Fly
};

class Enemy : public Node
{
protected:
	Enemy();
//---------- Các thuộc tính ----------
protected:

	std::string _fileName;
	float _speed;
	int _health;
	EnemyType _type;

//---------- Các component  ----------
protected:
	Sprite* _sprite;
	PhysicsBody* _body;
	Action* _action;
	//Tự động hủy đối tượng nếu như player chết
	void DestroyIfDie();

public:
	/**
	 * Các lớp con gọi hàm setup, và phải implement setAction
	 * Thực hiện setup các thuộc tính chung chung
	 */
	virtual void setup(std::string fileName, EnemyType type);

	/**
	 *Mỗi cái phải viết 1 cái action riêng
	 */
	virtual void setupAction() = 0;

	/**
	 * Xử lý các va chạm: Có vẻ như là giống nhau hết
	 */
	virtual bool onContact(PhysicsContact& contact);

	/**
	 * Lấy level để xử lý các thông số sao cho phù hợp với các level
	 */
	int getLevel();

	~Enemy();
};
#endif
