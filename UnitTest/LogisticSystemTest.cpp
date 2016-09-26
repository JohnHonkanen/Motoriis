#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Motoriis/LogisticSystem.h"
#include "../Motoriis/LogisticSystem.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(LogisticSystemTest)
	{
	public:
		TEST_METHOD(StoreInPipe) // Stores Item in pipe.
		{
			// TODO: Your test code here

			LogisticSystem mainPipe(1, 1, 1);
			Item *item1 = new Item(4, "item1", 0, "SKU1", "#000", 1);
			Item *item2 = new Item(5, "item2", 1, "SKU2", "#000", 1);
			
			mainPipe.addToList(item1);
			Assert::AreEqual(true, mainPipe.findItem("SKU1"));
			mainPipe.addToList(item2);
			Assert::AreEqual(false, mainPipe.findItem("SKU2"));
			mainPipe.storeItem("SKU1", 1);
			Assert::AreEqual(1, mainPipe.getItem("SKU1")->getAmount());

		}

		TEST_METHOD(RemoveFromPipe) // Removes Items from pipe. 
		{

			LogisticSystem mainPipe(1, 2, 3);
			Item *item1 = new Item(4, "item1", 0, "SKU1", "#000", 2);
			Item *item2 = new Item(5, "item2", 1, "SKU2", "#000", 1);

			mainPipe.addToList(item1);
			Assert::AreEqual(true, mainPipe.findItem("SKU1"));
			mainPipe.addToList(item2);
			Assert::AreEqual(true, mainPipe.findItem("SKU2"));
			mainPipe.removeItem("SKU1", 2);
			Assert::AreEqual(false, mainPipe.findItem("SKU1"));
			Assert::AreEqual(true, mainPipe.findItem("SKU2"));
		}

		TEST_METHOD(TransferFromToPipe) // Transfers Items from, and to pipes.
		{

			LogisticSystem mainPipe(1, 2, 3);
			LogisticSystem transferPipe(2, 1, 3);
			LogisticSystem transferPipe2(3, 1, 3);
			Item *item1 = new Item(4, "item1", 0, "SKU1", "#000", 2);
			Item *item2 = new Item(5, "item2", 1, "SKU2", "#000", 1);

			mainPipe.addToList(item1);
			Assert::AreEqual(true, mainPipe.findItem("SKU1"));
			mainPipe.addToList(item2);
			Assert::AreEqual(true, mainPipe.findItem("SKU2"));
			mainPipe.establishConnection(transferPipe);
			Assert::AreEqual(true, mainPipe.isConnected(transferPipe));
			Assert::AreEqual(false, mainPipe.isConnected(transferPipe2));
			mainPipe.transferItem(transferPipe, "SKU1", 2);
			bool transferToPipe2 = mainPipe.transferItem(transferPipe2, "SKU1", 2);
			Assert::AreEqual(false, transferToPipe2);
			Assert::AreEqual(true, transferPipe.findItem("SKU1"));
			Assert::AreEqual(2, transferPipe.getItem("SKU1")->getAmount());
			Assert::AreEqual(false, mainPipe.findItem("SKU1"));
			Assert::AreEqual(true, mainPipe.findItem("SKU2"));
			mainPipe.transferItem(transferPipe, "SKU2", 1);
			Assert::AreEqual(false, transferPipe.findItem("SKU2"));
			Assert::AreEqual(true, mainPipe.findItem("SKU2"));
			transferPipe.establishConnection(transferPipe2);
			Assert::AreEqual(true, transferPipe.isConnected(transferPipe2));
			Assert::AreEqual(false, transferPipe2.isConnected(mainPipe));
			Assert::AreEqual(true, mainPipe.isConnected(transferPipe));
		}

		TEST_METHOD(QueueTransfer) // Transfers Items in a queue.
		{
			LogisticSystem mainPipe(1, 2, 20000);
			LogisticSystem transferPipe(2, 1, 20000);
			LogisticSystem transferPipe2(3, 1, 20000);
			Item *item1 = new Item(4, "item1", 0, "SKU1", "#000", 6000);
			Item *item2 = new Item(5, "item2", 1, "SKU2", "#000", 5000);

			mainPipe.establishConnection(transferPipe);
			transferPipe.establishConnection(transferPipe2);

			mainPipe.addToList(item1);
			Assert::AreEqual(true, mainPipe.findItem("SKU1"));
			mainPipe.addToList(item2);
			Assert::AreEqual(true, mainPipe.findItem("SKU2"));
			mainPipe.transferItem(transferPipe, "SKU1", 6000);
			Assert::AreEqual(true, transferPipe.findItem("SKU1"));
			Assert::AreEqual(false, mainPipe.findItem("SKU1"));
			mainPipe.transferItem(transferPipe, "SKU2", 5000);
			Assert::AreEqual(false, transferPipe.findItem("SKU2"));
			transferPipe.transferItem(transferPipe2, "SKU1", 6000);
			Assert::AreEqual(true, transferPipe2.findItem("SKU1"));
			Assert::AreEqual(false, transferPipe.findItem("SKU1"));
		}

	};
}