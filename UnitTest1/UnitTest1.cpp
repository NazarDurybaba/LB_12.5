#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_12.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestPushNumbers)
		{
			std::stack<int> stack;
			pushNumbers(stack, 5);
			Assert::AreEqual(stack.top(), 5);
		}

		TEST_METHOD(TestConcatenateStacks)
		{
			std::stack<int> stack1, stack2;
			pushNumbers(stack1, 1);
			pushNumbers(stack1, 2);
			pushNumbers(stack1, 3);
			pushNumbers(stack2, 4);
			pushNumbers(stack2, 5);
			pushNumbers(stack2, 6);

			std::stack<int> concatenatedStack = concatenateStacks(stack1, stack2);

			Assert::AreEqual(concatenatedStack.size(), static_cast<size_t>(6));
			Assert::AreEqual(concatenatedStack.top(), 4);
		}

		TEST_METHOD(TestPrintStack)
		{
			std::stringstream buffer;
			std::streambuf* sbuf = std::cout.rdbuf();
			std::cout.rdbuf(buffer.rdbuf()); // Перенаправлення stdout до буфера

			std::stack<int> stack;
			pushNumbers(stack, 1);
			pushNumbers(stack, 2);
			pushNumbers(stack, 3);

			printStack(stack);
			std::cout.rdbuf(sbuf); // Повернення stdout до його попереднього буфера

			Assert::AreEqual(buffer.str(), std::string("Stack elements: 3 2 1 \n"));
		}
	};
}
