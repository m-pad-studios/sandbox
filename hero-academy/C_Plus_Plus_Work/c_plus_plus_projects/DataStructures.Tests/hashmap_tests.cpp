#include "pch.h"
#include "CppUnitTest.h"
#include "crt_check_memory.hpp"

#include "..//DataStructures/hash_map.hpp"
#include <string>
#include <functional>

using std::string;
using std::function;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace data_structures;

namespace data_structures_tests
{
	TEST_CLASS(HashMap_Tests)
	{
	public:

		struct Book
		{
			long Isbn{};
			string name{};
			string publisher{};
			long year{};
		};
		//static auto HashMapFactory()->HashMap<long, Book>;
		TEST_METHOD(TemplateTestMethod)
		{
			const CrtCheckMemory check;
			const int table_size = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % table_size;
				//auto temp = table_size;
			};

			HashMap<long, Book> card_catalog(table_size, hash_function);

			const Book book{ 123456789, "LuiLui", "Olvera - Publisher", 2021 };

			card_catalog.Insert(book.Isbn, book);

			Assert::IsTrue(card_catalog.Contains(book.Isbn));
		}

		TEST_METHOD(CopyTestMethod)
		{
			const CrtCheckMemory check;
			const int table_size = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % table_size;
				//auto temp = table_size;
			};

			HashMap<long, Book> card_catalog(table_size, hash_function);

			const Book book{ 123456789, "LuiLui", "Olvera - Publisher", 2021 };

			card_catalog.Insert(book.Isbn, book);

			HashMap<long, Book> card_catalog_copy = card_catalog;

			Assert::IsTrue(card_catalog_copy.Contains(book.Isbn));
		}
		/*TEST_METHOD(MOVECONSTRUCTORTest)
		{
			const CrtCheckMemory check;

			HashMap<long, Book> card_catalog = std::move(HashMapFactory());

			Assert::IsTrue(card_catalog.Contains(123456789));
		}*/

		TEST_METHOD(RemoveTest)
		{
			const CrtCheckMemory check;
			const int table_size = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % table_size;
				//auto temp = table_size;
			};

			HashMap<long, Book> card_catalog(table_size, hash_function);

			const Book book{ 123456789, "LuiLui", "Olvera - Publisher", 2021 };

			card_catalog.Insert(book.Isbn, book);

			card_catalog.Remove(book.Isbn);

			Assert::IsTrue(!card_catalog.Contains(book.Isbn));
		}

		TEST_METHOD(VisitTest)
		{
			const CrtCheckMemory check;
			const int table_size = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % table_size;
				//auto temp = table_size;
			};

			HashMap<long, Book> card_catalog(table_size, hash_function);

			const Book book{ 123456789, "LuiLui", "Olvera - Publisher", 2021 };

			card_catalog.Insert(book.Isbn, book);
			card_catalog.Insert(123987654, Book{ 123987654,"Book 2","publisher", 2030 });

			vector<long> visit_keys;
			//const
			auto visit_function = [&](const long& key, const Book& value) -> void
			{
				visit_keys.push_back(key);
			};
			card_catalog.Traverse(visit_function);

			vector<long> expected{ 123456789, 123987654 };

			Assert::AreEqual(expected.size(), visit_keys.size());
			for (auto i = 0u; i < visit_keys.size(); ++i)
			{
				Assert::AreEqual(expected[i], visit_keys[i]);
			}
		}

		TEST_METHOD(ConstructorTest)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };

			hashmap.Insert(book.Isbn, book);

			Assert::IsTrue(hashmap.Contains(book.Isbn));
		}

		TEST_METHOD(CountTest)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };

			hashmap.Insert(book.Isbn, book);

			Assert::IsTrue(hashmap.Count() == 1);
		}

		TEST_METHOD(CountX2Test)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			const Book book_2{ 1234, "Caf Rehab", "M", 2020 };

			hashmap.Insert(book.Isbn, book);
			hashmap.Insert(book_2.Isbn, book_2);
			Assert::IsTrue(hashmap.Count() == 2);
		}

		TEST_METHOD(FillMapWithLoopStructTest)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			const Book book_2{ 1234, "Caf Rehab", "M", 2020 };

			hashmap.Insert(book.Isbn, book);
			hashmap.Insert(book_2.Isbn, book_2);

			Assert::AreEqual(2ull, hashmap.Count());
		}

		TEST_METHOD(FillMapWithLoopStruct_ThenRemoveWithLoopStructTest)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			const Book book_2{ 1234, "Caf Rehab", "M", 2020 };


			hashmap.Insert(book.Isbn, book);
			hashmap.Insert(book_2.Isbn, book_2);

			hashmap.Remove(123456789);
			hashmap.Remove(1234);

			Assert::AreEqual(0ull, hashmap.Count());
		}
		TEST_METHOD(CountGreaterThanSizeTest)
		{
			const CrtCheckMemory check;

			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			const Book book_2{ 1234, "Caf Rehab", "M", 2020 };

			hashmap.Insert(book.Isbn, book);

			Assert::IsFalse(hashmap.Count() == 2);
		}
		TEST_METHOD(CountGreaterThanSizeTest_CheckThatIsTrue)
		{
			const CrtCheckMemory check;

			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			const Book book_2{ 1234, "Caf Rehab", "M", 2020 };

			hashmap.Insert(book.Isbn, book);

			Assert::IsTrue(hashmap.Count() == 1);
		}

		TEST_METHOD(RemoveAlreadyDeletedItemTest)
		{
			const CrtCheckMemory check;
			const auto exceptionThrown = []
			{
				const int kTableSize = 23;

				const auto hash_function = [&](long key) -> int
				{
					return key % kTableSize;
				};

				HashMap<long, Book> hashmap(kTableSize, hash_function);

				const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };

				hashmap.Insert(book.Isbn, book);

				Assert::IsTrue(hashmap.Contains(book.Isbn));

				hashmap.Remove(book.Isbn);
				hashmap.Remove(book.Isbn);
			};
			Assert::ExpectException<AdtException>(exceptionThrown);

		}

		TEST_METHOD(RemoveTest_second)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };

			hashmap.Insert(book.Isbn, book);

			hashmap.Remove(book.Isbn);

			Assert::IsTrue(!hashmap.Contains(book.Isbn));
		}

		TEST_METHOD(CallContainsOnAlreadyDeletedItemTest)
		{
			const CrtCheckMemory check;
			const auto exceptionThrown = []
			{
				const int kTableSize = 23;

				const auto hash_function = [&](long key) -> int
				{
					return key % kTableSize;
				};

				HashMap<long, Book> hashmap(kTableSize, hash_function);

				const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };

				hashmap.Insert(book.Isbn, book);
				hashmap.Remove(book.Isbn);

				Assert::IsFalse(hashmap.Contains(book.Isbn));
			};
		}
		TEST_METHOD(CallContainsOnAlreadyDeletedItemTest_NewInsert_CheckThatItIsTrue)
		{
			const CrtCheckMemory check;
			const auto exceptionThrown = []
			{
				const int kTableSize = 23;

				const auto hash_function = [&](long key) -> int
				{
					return key % kTableSize;
				};

				HashMap<long, Book> hashmap(kTableSize, hash_function);

				const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
				const Book book2{ 123456789, "Luis Olvera", "M", 2020 };

				hashmap.Insert(book.Isbn, book);
				hashmap.Remove(book.Isbn);
				hashmap.Insert(book2.Isbn, book2);

				Assert::IsTrue(hashmap.Contains(book.Isbn));
			};
		}

		TEST_METHOD(CallsGetOrAddOnAlreadyDeletedItemTest)
		{
			const CrtCheckMemory check;
			const auto exceptionThrown = []
			{

				const int kTableSize = 23;

				const auto hash_function = [&](long key) -> int
				{
					return key % kTableSize;
				};

				HashMap<long, Book> hashmap(kTableSize, hash_function);

				const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
				const Book book_2{ 6789, "Caffeine Rehab", "M", 2020 };

				const auto vector_creation_function = [&]() -> Book {
					return Book(book_2);
				};

				hashmap.Insert(book.Isbn, book_2);
				hashmap.Remove(book_2.Isbn);
				hashmap.GetOrAdd(book_2.Isbn, vector_creation_function);
			};
			Assert::ExpectException<AdtException>(exceptionThrown);

		}

		TEST_METHOD(VisitTest_second)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };

			hashmap.Insert(book.Isbn, book);
			hashmap.Insert(123987456, Book{ 123987456 , "Book2", "M", 2020 });

			vector<long> visit_keys;
			const auto visit_function = [&](const long& key, const Book& value) -> void
			{
				visit_keys.push_back(key);
			};
			hashmap.Traverse(visit_function);

			vector<long> expected{ 123456789, 123987456 };

			Assert::AreEqual(expected.size(), visit_keys.size());

			for (auto i = 0u; i < visit_keys.size(); ++i)
			{
				Assert::AreEqual(expected[i], visit_keys[i]);
			}
		}
		/* TEST_METHOD(VisitDifferentMapsWithMultipleBooksWithSameDataTest)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);
			HashMap<long, Book> hashmap_1(kTableSize, hash_function);
			HashMap<long, Book> hashmap_2(kTableSize, hash_function);
			HashMap<long, Book> hashmap_3(kTableSize, hash_function);

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };

			for (auto i = 0u; i < kTableSize; ++i)
			{
				hashmap.Insert(book.Isbn, book);
				hashmap.Insert(123987456, Book{ 123987456 , "Book2", "M", 2020 });

				hashmap_1.Insert(book.Isbn, book);
				hashmap_1.Insert(123987456, Book{ 123987456 , "Book2", "M", 2020 });

				hashmap_2.Insert(book.Isbn, book);
				hashmap_2.Insert(123987456, Book{ 123987456 , "Book2", "M", 2020 });

				hashmap_3.Insert(book.Isbn, book);
				hashmap_3.Insert(123987456, Book{ 123987456 , "Book2", "M", 2020 });
			}
			vector<long> visit_keys;
			const auto visit_function = [&](const long& key, const Book& value) -> void
			{
				visit_keys.push_back(key);
			};
			hashmap.Traverse(visit_function);
			hashmap_1.Traverse(visit_function);
			hashmap_2.Traverse(visit_function);
			hashmap_3.Traverse(visit_function);

			vector<long> expected{ 123456789, 123987456 };

			Assert::AreEqual(expected.size(), visit_keys.size());

			for (auto i = 0u; i < visit_keys.size(); ++i)
			{
				Assert::AreEqual(expected[i], visit_keys[i]);
			}

			for (auto i = 0u; i < kTableSize; ++i)
			{
				Assert::IsTrue(hashmap_1.Count() && hashmap_2.Count() && hashmap_3.Count() == 23);
			}

			Assert::IsTrue(hashmap_1.Contains(123456789) == hashmap_2.Contains(123456789));
		} */
		TEST_METHOD(CheckThatSizeIsZero_WithNewHashMap)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			Assert::IsTrue(hashmap.Count() == 0);
		}
		TEST_METHOD(CheckThatSizeIsZero_WithNewHashMap_CopyConstructor)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			HashMap<long, Book> second_hashmap(hashmap);

			Assert::IsTrue(second_hashmap.Count() == 0);
		}
		TEST_METHOD(CheckThatSizeIsZero_WithNewHashMap_AssignmentOperator)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			HashMap<long, Book> second_hashmap(kTableSize, hash_function);
			second_hashmap = (hashmap);

			Assert::IsTrue(second_hashmap.Count() == 0);
		}
		TEST_METHOD(CheckThatSize_WithNewHashMap_AndInserting_1_value)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			size_t key = book.Isbn;

			HashMap<long, Book> hashmap(kTableSize, hash_function);
			hashmap.Insert(key, book);

			Assert::IsTrue(hashmap.Count() == 1);
		}
		TEST_METHOD(CheckThatSize_WithNewHashMap_AndInserting_1_value_CopyConstructor)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			size_t key = book.Isbn;

			HashMap<long, Book> hashmap(kTableSize, hash_function);
			hashmap.Insert(key, book);

			auto second_hashmap(hashmap);

			Assert::AreEqual(1ull, second_hashmap.Count());
		}
		TEST_METHOD(CheckThatSize_WithNewHashMap_AndInserting_1_value_AssignmentOperator)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			size_t key = book.Isbn;

			HashMap<long, Book> hashmap(kTableSize, hash_function);
			hashmap.Insert(key, book);

			HashMap<long, Book> second_hashmap(kTableSize, hash_function);
			second_hashmap = hashmap;

			Assert::IsTrue(second_hashmap.Count() == 1ull);
		}
		TEST_METHOD(CheckThatSizeIsZero_WithInsertAndRemove_WithNewHashMap)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			size_t key = book.Isbn;

			HashMap<long, Book> hashmap(kTableSize, hash_function);
			hashmap.Insert(key, book);
			hashmap.Remove(key);

			Assert::IsTrue(hashmap.Count() == 0);
		}
		TEST_METHOD(CheckThatSizeIsZero_WithInsertAndRemove_WithNewHashMap_CopyConstructor)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			size_t key = book.Isbn;

			HashMap<long, Book> hashmap(kTableSize, hash_function);
			hashmap.Insert(key, book);
			hashmap.Remove(key);

			HashMap<long, Book> second_hashmap(hashmap);

			Assert::IsTrue(second_hashmap.Count() == 0);
		}
		TEST_METHOD(CheckThatSizeIsZero_WithInsertAndRemove_WithNewHashMap_AssignmentOperator)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			size_t key = book.Isbn;

			HashMap<long, Book> hashmap(kTableSize, hash_function);
			hashmap.Insert(key, book);
			hashmap.Remove(key);

			HashMap<long, Book> second_hashmap(kTableSize, hash_function);
			second_hashmap = (hashmap);

			Assert::IsTrue(second_hashmap.Count() == 0);
		}

		TEST_METHOD(TestContains_WithNewHashMap_AndInserting_ONE)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			size_t key = book.Isbn;

			HashMap<long, Book> hashmap(kTableSize, hash_function);
			hashmap.Insert(key, book);

			Assert::IsTrue(hashmap.Contains(key));
		}
		TEST_METHOD(TestContains_WithNewHashMap_AndInserting_ONE_CopyConstructor)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			size_t key = book.Isbn;

			HashMap<long, Book> hashmap(kTableSize, hash_function);
			hashmap.Insert(key, book);

			auto second_hashmap(hashmap);

			Assert::IsTrue(second_hashmap.Contains(key));
		}
		TEST_METHOD(TestContains_WithNewHashMap_AndInserting_One_AssignmentOperator)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 123456789, "Caffeine Rehab", "M", 2020 };
			size_t key = book.Isbn;

			HashMap<long, Book> hashmap(kTableSize, hash_function);
			hashmap.Insert(key, book);

			HashMap<long, Book> second_hashmap(kTableSize, hash_function);
			second_hashmap = hashmap;

			Assert::IsTrue(second_hashmap.Contains(key));
		}
		TEST_METHOD(TestContains_WithNewHashMap_AndInserting_FIVE)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 12345, "Book A", "M", 2020 };
			const Book book2{ 123456, "Book B", "M", 2020 };
			const Book book3{ 1234567, "Book C", "M", 2020 };
			const Book book4{ 12345678, "Book D", "M", 2020 };
			const Book book5{ 123456789, "Book E", "M", 2020 };

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			hashmap.Insert(book.Isbn, book);
			hashmap.Insert(book2.Isbn, book2);
			hashmap.Insert(book3.Isbn, book3);
			hashmap.Insert(book4.Isbn, book4);
			hashmap.Insert(book5.Isbn, book5);

			Assert::IsTrue(hashmap.Contains(book3.Isbn));
		}
		TEST_METHOD(TestContains_WithNewHashMap_AndInserting_FIVE_CopyConstructor)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 12345, "Book A", "M", 2020 };
			const Book book2{ 123456, "Book B", "M", 2020 };
			const Book book3{ 1234567, "Book C", "M", 2020 };
			const Book book4{ 12345678, "Book D", "M", 2020 };
			const Book book5{ 123456789, "Book E", "M", 2020 };

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			hashmap.Insert(book.Isbn, book);
			hashmap.Insert(book2.Isbn, book2);
			hashmap.Insert(book3.Isbn, book3);
			hashmap.Insert(book4.Isbn, book4);
			hashmap.Insert(book5.Isbn, book5);

			auto second_hashmap(hashmap);

			Assert::IsTrue(second_hashmap.Contains(book3.Isbn));
		}
		TEST_METHOD(TestContains_WithNewHashMap_AndInserting_FIVE_AssignmentOperator)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 12345, "Book A", "M", 2020 };
			const Book book2{ 123456, "Book B", "M", 2020 };
			const Book book3{ 1234567, "Book C", "M", 2020 };
			const Book book4{ 12345678, "Book D", "M", 2020 };
			const Book book5{ 123456789, "Book E", "M", 2020 };

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			hashmap.Insert(book.Isbn, book);
			hashmap.Insert(book2.Isbn, book2);
			hashmap.Insert(book3.Isbn, book3);
			hashmap.Insert(book4.Isbn, book4);
			hashmap.Insert(book5.Isbn, book5);

			HashMap<long, Book> second_hashmap(kTableSize, hash_function);
			second_hashmap = hashmap;

			Assert::IsTrue(second_hashmap.Contains(book3.Isbn));
		}

		TEST_METHOD(TestCount_WithNewHashMap_AndInserting_THREE)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 12345, "Book A", "M", 2020 };
			const Book book2{ 123456, "Book B", "M", 2020 };
			const Book book3{ 1234567, "Book C", "M", 2020 };

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			hashmap.Insert(book.Isbn, book);
			hashmap.Insert(book2.Isbn, book2);
			hashmap.Insert(book3.Isbn, book3);

			Assert::IsTrue(hashmap.Count() == 3ull);
		}
		TEST_METHOD(TestCount_WithNewHashMap_AndInserting_THREE_CopyConstructor)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 12345, "Book A", "M", 2020 };
			const Book book2{ 123456, "Book B", "M", 2020 };
			const Book book3{ 1234567, "Book C", "M", 2020 };

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			hashmap.Insert(book.Isbn, book);
			hashmap.Insert(book2.Isbn, book2);
			hashmap.Insert(book3.Isbn, book3);

			auto second_hashmap(hashmap);

			Assert::IsTrue(second_hashmap.Count() == 3ull);
		}
		TEST_METHOD(TestCount_WithNewHashMap_AndInserting_THREE_AssignmentOperator)
		{
			const CrtCheckMemory check;
			const int kTableSize = 23;
			const auto hash_function = [&](long key) -> int
			{
				return key % kTableSize;
			};

			const Book book{ 12345, "Book A", "M", 2020 };
			const Book book2{ 123456, "Book B", "M", 2020 };
			const Book book3{ 1234567, "Book C", "M", 2020 };

			HashMap<long, Book> hashmap(kTableSize, hash_function);

			hashmap.Insert(book.Isbn, book);
			hashmap.Insert(book2.Isbn, book2);
			hashmap.Insert(book3.Isbn, book3);

			HashMap<long, Book> second_hashmap(kTableSize, hash_function);
			second_hashmap = hashmap;

			Assert::IsTrue(second_hashmap.Count() == 3ull);
		}
		
	};
}