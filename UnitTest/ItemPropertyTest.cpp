#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Motoriis/Property.h";
#include "../Motoriis/Property.cpp";
#include "../Motoriis/PropertyModifier.h";
#include "../Motoriis/PropertyModifier.cpp";
#include "../Motoriis/Building.h";
#include "../Motoriis/Building.cpp";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(ItemPropertyTest)
	{
	public:
		TEST_METHOD(AddAndRemovePropertyModifier)
		{
			Property property = Property(1,"prop1","Property", "Desc", 1.0);
			PropertyModifier modifier = PropertyModifier(1, "mod1", "modifier", "desc", 1.1, false);
			PropertyModifier modifier2 = PropertyModifier(2, "mod2", "modifier2", "desc", 1.2, false);
			PropertyModifier modifier3 = PropertyModifier(2, "mod2", "modifier2", "desc", 1.0, true);

			property.addModifier(modifier);
			float assertVal = 1.0 * 1.1;
			Assert::AreEqual(assertVal, property.getFinalValue());
			property.addModifier(modifier2);
			assertVal = 1.0*1.1*1.2;
			Assert::AreEqual(assertVal, property.getFinalValue());
			property.removeModifier(modifier2);
			assertVal = 1.0*1.1;
			Assert::AreEqual(assertVal, property.getFinalValue());
			property.addModifier(modifier3);
			assertVal = 2.0*1.1;
			Assert::AreEqual(assertVal, property.getFinalValue());

		}
		TEST_METHOD(AddPropertyToBuilding) {
			Property property = Property(1, "prop1", "Property", "Desc", 1.0);
			Building building = Building();
			building.addProperty(property);
			float val = building.getPropertyValue("prop1");
			Assert::AreEqual(1.0f, val);
		}
	};
}