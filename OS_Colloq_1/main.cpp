#ifdef UNIT_TEST
#include <gtest/gtest.h>
#include "functions.h"

TEST(FactorialTest, HandlesValidInput) {
	EXPECT_EQ(generateFactorials(5), std::vector<unsigned long long>({ 1, 2, 6, 24, 120 }));
	EXPECT_EQ(generateFactorials(0).size(), 0);
}

TEST(FactorialTest, ThrowsOnInvalidInput) {
	EXPECT_THROW(generateFactorials(-1), std::invalid_argument);
	EXPECT_THROW(generateFactorials(21), std::overflow_error);
}

TEST(RemoveDuplicatesTest, BasicCases) {
	std::vector<int> input = { 1, 2, 2, 3, 1, 4 };
	EXPECT_EQ(removeDuplicates(input), std::vector<int>({ 1, 2, 3, 4 }));

	std::vector<double> dbl_input = { 1.1, 2.2, 1.1, 3.3 };
	std::vector<double> expected = { 1.1, 2.2, 3.3 };
	auto result = removeDuplicates(dbl_input);
	ASSERT_EQ(result.size(), expected.size());
	for (size_t i = 0; i < expected.size(); ++i) {
		EXPECT_DOUBLE_EQ(result[i], expected[i]);
	}
}


TEST(LinkedListTest, ReverseCorrectness) {
	std::vector<int> values = { 1, 2, 3, 4 };
	Node* head = createList(values);
	Node* reversed = reverseLinkedList(head);
	std::vector<int> result = listToVector(reversed);
	EXPECT_EQ(result, std::vector<int>({ 4, 3, 2, 1 }));
	freeList(reversed);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#else
#include <iostream>
#include "functions.h"

void menu()
{
	while (true)
	{
		std::cout << "MENU:\n";
		std::cout << "1. generate factorials for n lesser than 20;\n";
		std::cout << "2. Remove duplicate numbers from array;\n";
		std::cout << "3. Invert linked list;\n";
		std::cout << "Enter any other key to exit.\n";
		int k = 0;
		int n, val;
		std::vector<unsigned long long> fct;
		std::vector<int> nums;
		Node* first, *cur;
		std::cin >> k;
		switch (k)
		{
		case 1:
			std::cout << "Enter n: ";
			std::cin >> n;
			while (n < 1 || n > 20)
			{
				std::cout << "Error: n should be in range of 0 to 20. Enter again: ";
				std::cin >> n;
			}
			fct = generateFactorials(n);
			std::cout << "First " << n << " factorials:\n";
			for (int i = 0; i < n; i++)
			{
				std::cout << fct[i] << ' ';
			}
			std::cout << '\n';
			break;
		case 2:
			std::cout << "Enter n: ";
			std::cin >> n;
			nums.resize(n);
			while (n < 1)
			{
				std::cout << "Error: n should be positive. Enter again: ";
				std::cin >> n;
			}
			std::cout << "Enter " << n << " numbers:\n";
			for (int i = 0; i < n; i++)
			{
				std::cin >> nums[i];
			}
			nums = removeDuplicates(nums);
			std::cout << "Array without duplicates:\n";
			for (int i = 0; i < nums.size(); i++)
			{
				std::cout << nums[i] << ' ';
			}
			std::cout << '\n';
			break;
		case 3:
			std::cout << "Enter n: ";
			std::cin >> n;
			while (n < 1)
			{
				std::cout << "Error: n should be positive. Enter again: ";
				std::cin >> n;
			}
			std::cout << "Enter " << n << " numbers:\n";
			std::cin >> val;
			first = new Node(val);
			cur = first;
			for (int i = 1; i < n; i++)
			{
				std::cin >> val;
				Node* nd = new Node(val);
				cur->next = nd;
				cur = nd;
			}
			first = reverseLinkedList(first);
			cur = first;
			std::cout << "Reversed list:\n";
			while(cur != nullptr)
			{
				std::cout << cur->data << " ";
				cur = cur->next;
			}
			std::cout << '\n';
			freeList(first);
			break;
		default:
			return;
		}
	}
}

int main()
{
	menu();
	return 0;
}
#endif