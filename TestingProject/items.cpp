#include "stdafx.h"

#include "items.h"

#include <cassert>


ItemID ItemStack::getItem()
{
	return m_id;
}

int ItemStack::getAmount()
{
	return m_amount;
}

void ItemStack::addAmount(int amount)
{
	m_amount += amount;
}



ItemStack& Inventory::operator[](const int index)
{
	return m_items[index];
}

void Inventory::addItem(ItemID id, int amount)
{
	for (int i{ 0 }; i < m_items.size(); ++i)
	{
		if (m_items[i].getItem() == id)
		{
			m_items[i].addAmount(amount);
			return;
		}
	}
	m_items.push_back(ItemStack());
}