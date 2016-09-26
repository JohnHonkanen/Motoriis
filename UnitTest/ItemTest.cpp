#include "stdafx.h"
#include "CppUnitTest.h"
#include"../Motoriis/Item.h"
#include"../Motoriis/Item.cpp"
#include "../Motoriis/ItemManager.h"
#include "../Motoriis/ItemManager.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(ItemTest)
	{
	public:
		TEST_METHOD(SetItem)
		{
			//Test for Item initializing
			string itemArr[] = { "1", "testItem", "0", "TE001", "#000" };
			string itemString = "1,testItem,0,TE001,#000";

			Item *item = Item::convertToItem(itemString);
			Assert::AreEqual(item->getName(), itemArr[1]);
			Assert::AreEqual(item->getType(), stoi(itemArr[2]));
			Assert::AreEqual(item->getSKU(), itemArr[3]);
			Assert::AreEqual(item->getColor(), itemArr[4]);
			delete item;
		}
		TEST_METHOD(AddItems) {
			//Populating Item Managers
			vector<string> ItemListString;
			for (int i = 0; i < 10; i++) {
				ItemListString.push_back(to_string(i) + "," + "testItem" + to_string(i)
					+"," + to_string(i) +"," + "TE001"+ to_string(i) +"," + "#000");
			}
			ItemManager manager;
			manager.populateItems(ItemListString);
			//Check if Items are in List
			for (int i = 0; i < 10; i++) {
				bool found = manager.findItem("TE001" + to_string(i));
				Assert::AreEqual(true, found);
			}
			//Add Item Amount
			bool added = manager.storeItem("TE0011", 10);
			Assert::AreEqual(true, added);
			Item *item = manager.getItem("TE0011");
			Assert::AreEqual(10, item->getAmount());
			delete item;
			//Remove Item Amount
			bool removed = manager.removeItem("TE0011", 5);
			Assert::AreEqual(true, removed);
			item = manager.getItem("TE0011");
			Assert::AreEqual(5, item->getAmount());
			delete item;
			//Remove Item from List when 0
			removed = manager.removeItem("TE0011", 5);
			Assert::AreEqual(true, removed);
			bool found = manager.findItem("TE0011");
			Assert::AreEqual(false, found);
		}
	};
}