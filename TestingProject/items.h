#pragma once

#include<vector>

enum class ItemID
{
	NONE = -1
};

class ItemStack
{
	ItemID m_id;
	int m_amount;
	
public:
	ItemStack(ItemID = ItemID::NONE, int amount = 0)
	{
	
	};

	ItemID getItem();
	int getAmount();

	void addAmount(int amount);
};

class Inventory
{
private:
	std::vector<ItemStack> m_items;

public:
	ItemStack& operator[](const int index);

	void addItem(ItemID, int amount = 1);
};