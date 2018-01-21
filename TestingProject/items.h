#pragma once

#include<vector>

enum class ItemID
{
	NONE = -1,
	IRON_SWORD,
	WOODEN_SHIELD,
	IRON_MACE
};

std::string getItemName(ItemID id);

class ItemStack
{
	ItemID m_id;
	int m_amount;
	
public:
	ItemStack(ItemID = ItemID::NONE, int amount = 0);

	ItemID getItem() const;
	int getAmount() const;

	void addAmount(int amount);

	// Returns how many items was removed
	int removeAmount(int amount);
};

class Inventory
{
private:
	std::vector<ItemStack> m_items{ };

public:
	ItemStack& operator[](const int index);

	void addItem(ItemID id, int amount = 1);
	int removeItem(ItemID id, int amount = 1);
	int getItemIndex(ItemID id) const;

	void printContents();
};