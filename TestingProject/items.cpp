#include "stdafx.h"

#include "items.h"

#include <string>
#include <iostream>
#include <cassert>



std::string getItemName(ItemID id)
{
	switch (id)
	{
		case ItemID::IRON_SWORD:
			return "Iron Sword";
		case ItemID::WOODEN_SHIELD:
			return "Wooden Shield";
		case ItemID::IRON_MACE:
			return "Iron Mace";
		case ItemID::NONE:
		default:
			return "???";
	}
}



ItemStack::ItemStack(ItemID id, int amount)
{
	m_id = id;
	m_amount = amount;
}

ItemID ItemStack::getItem() const
{
	return m_id;
}

int ItemStack::getAmount() const
{
	return m_amount;
}

void ItemStack::addAmount(int amount)
{
	m_amount += amount;
}

int ItemStack::removeAmount(int amount)
{
	amount = amount > m_amount ? m_amount : amount;

	m_amount -= amount;
	return amount;
}

std::ostream& operator<<(std::ostream &out, const ItemID &id)
{
	out << static_cast<int>(id);
	return out;
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
	m_items.push_back(ItemStack(id, amount));
}

int Inventory::removeItem(ItemID id, int amount)
{
	int index{ getItemIndex(id) };
	if (index != -1)
	{
		if (m_items[index].getAmount() > amount)
		{
			
			return m_items[index].removeAmount(amount);
		}
		else
		{
			int amnt{ m_items[index].getAmount() };
			m_items.erase(m_items.begin() + index);
			return amnt;
		}
	}
	return -1;
}

int Inventory::getItemIndex(ItemID id) const
{
	for (int i{ 0 }; i < m_items.size(); ++i)
	{
		if (m_items[i].getItem() == id)
		{
			return i;
		}
	}
	return -1;
}

void Inventory::printContents()
{
	std::cout << "-----INVENTORY-----\n";
	for (ItemStack is : m_items)
	{
		std::cout << "Item name: " << getItemName(is.getItem()) <<
			", Amount: " << is.getAmount() << "\n";
	}
	std::cout << "-------------------\n";
}