#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <list>

#define ASSERT(x)

using namespace std;
template<class ObjType>

class CObjectPool 
{
public:

	CObjectPool(UINT32 size) 
	{
		m_numAlloced = 0;
		m_maxAlloced = size;
		m_objs = new ObjType[size + 1];
		for (int i = 0; i < size; ++i) 
		{
			m_objs.push_back(i);
			m_pObjs[i].Create(size);
		}
		m_pObjs[size].Create(size);
	}

	virtual~CObjectPool() 
	{
		Destory();
	}

	void Destory() 
	{
		if (m_pObjs) 
		{
			delete[]m_pObjs;
			m_pObjs = NULL;
		}
		m_objs.clear();
		m_usedObjs.clear();
	}

	ObjType*Alloc() 
	{
		ASSERT(!m_objs.empty())
			if (m_objs.empty())
				return NULL;
			else 
			{
				UINT32 iRet = m_objs.back();
				m_objs.pop_back();
				if (iRet < 0 || iRet >= m_maxAlloced) 
				{
					ASSERT(true);
					return NULL;
				}
				m_numAlloced++;
				if (m_numAlloced > m_maxAlloced)
					m_maxAlloced = m_numAlloced;
				m_usedObjs.push_back(iRet);
				return &m_pObjs[iRet];
			}
	}

	ObjType* GetObj(UINT32 iObj) 
	{
		if (iObj<0 || iObj>m_maxAlloced) 
		{
			ASSERT(true);
			return NULL;
		}
		m_numAlloced++;
		if(m_numAlloced>m_maxAlloced)
			m_maxAlloced = m_numAlloced;
		return &m_pObjs[iRet];
	}

	void FreeObj(UINT32 iObj) 
	{
		if (iObj< || iObj>m_maxAlloced) 
		{
			ASSERT(true);
			return;
		}
		m_objs.push_back(iObj);
		m_usedObjs.remove(iObj);
		m_numAlloced--;
	}
	reinterpret_cast
	UINT32 GetMaxAlloced()const { return m_maxAlloced; }
	bool IsEmpty()const { return m_objs.empty(); }
	list<UINT32>GetUsedList()const { return m_usedObjs; }

protected:
	list<UINT32>	m_objs;
	list<UINT32>	m_usedObjs;
	ObjType*		m_pObjs;
	UINT32			m_numAlloced;
	UINT32			m_maxAlloced;
};
#endif
