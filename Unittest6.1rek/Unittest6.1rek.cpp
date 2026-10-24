#include "pch.h"
#include "CppUnitTest.h"
#include "../6.1rek/6.1rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unittest61rek
{
	TEST_CLASS(Unittest61rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int p[] = { 15, 25, 35, 45, 55, 65 };

            Assert::AreEqual(5, CountElements(p, 6));
            Assert::AreEqual(225, SumElements(p, 6));
        }

        TEST_METHOD(TestZeroElements)
        {
            int p[] = { 15, 25, 35, 45, 55, 65 };

            ZeroElements(p, 6);

            Assert::AreEqual(15, p[0]);
            Assert::AreEqual(0, p[1]);
            Assert::AreEqual(0, p[2]);
            Assert::AreEqual(0, p[3]);
            Assert::AreEqual(0, p[4]);
            Assert::AreEqual(0, p[5]);
		}
	};
}
