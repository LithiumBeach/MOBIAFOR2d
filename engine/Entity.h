#ifndef ENTITY_H
#define ENTITY_H

namespace mob_phys
{
	static unsigned int ID_CURSOR = 0;

	class Entity
	{
	public:
		Entity(){ m_id = ID_CURSOR++; }

		unsigned int GetID(){ return m_id; }

	private:
		unsigned int m_id;
	};
}


#endif