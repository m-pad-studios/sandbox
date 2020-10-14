#include <iostream>
#include <crtdbg.h>

#include "array_stack.hpp"
#include "array_queue.hpp"
#include "array_deque.hpp"



using std::cout;
using std::endl;

using namespace data_structures;

class Driver
{
	public:
		void Drive()
		{
			system("Color F3");
			//ArrayStack Main Output showing method functionality & no leaky ship here Captain for all classes

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				//Act
			ArrayStack<int> the_big_le_stacky(15);
			ArrayQueue<int> the_big_le_queue(15);
			ArrayDeque<int> the_big_le_deck(7);

			cout << std::string("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~") << endl;
			cout << std::string("ARRAY STACK FUNCTION OUTPUT TESTS") << endl;
			cout << std::string("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~") << endl;

			the_big_le_stacky.Push(7);
			cout << std::string("PUSHED TO FRONT : ") << the_big_le_stacky.Peek() << endl;

			the_big_le_stacky.Push(1);
			cout << std::string("PUSHED TO FRONT : ") << the_big_le_stacky.Peek() << endl;

			the_big_le_stacky.Push(3);
			cout << std::string("~~~~~~~~~~~~~~~~~~~") << endl;
			cout << std::string("PUSHED TO FRONT : ") << the_big_le_stacky.Peek() << endl;
			cout << std::string("~~~~~~~~~~~~~~~~~~~") << endl;

			cout << endl;

			cout << std::string("~~~~~POP DAT STACK~~~~~") << endl;

			cout << endl;

			cout << std::string("~~~~~~~~~~~~~~~~~~~") << endl;
			cout << std::string("POPPED : ") << the_big_le_stacky.Peek() << endl;
			cout << std::string("~~~~~~~~~~~~~~~~~~~") << endl;

			the_big_le_stacky.Pop();

			cout << endl;

			cout << std::string("~~~~~PEEK A BOO~~~~~") << endl;

			cout << std::string("~~~~~~~~~~~~~~~~~~~") << endl;
			cout << std::string("PEEKING AT : ") << the_big_le_stacky.Peek() << endl;
			cout << std::string("~~~~~~~~~~~~~~~~~~~") << endl;

			cout << endl;
			cout << std::string("~~~~~CLEAR DAT STACK~~~~~") << endl;
			the_big_le_stacky.Clear();

			if (the_big_le_stacky.Empty())
			{
				cout << std::string("~~~~~~~~~~~~~~~~~~~") << endl;
				cout << std::string("STACK IS SUCCESSFULLY EMPTY") << endl;
				cout << std::string("~~~~~~~~~~~~~~~~~~~") << endl;
			}
			//test to make sure code is following either LIFO or FILO principle

			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			//ArrayQueue main output showing method functionality
			cout << std::string("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~") << endl;
			cout << std::string("ARRAY QUEUE FUNCTION OUTPUT TESTS") << endl;
			cout << std::string("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~") << endl;

			for (auto i = 0u; i < the_big_le_queue.Size(); ++i)
			{
				the_big_le_queue.Enqueue(i);
			}
		


			if(the_big_le_queue.Full())
			cout << std::string("YA BUDDY THIS PUPPY IS FULL!") << the_big_le_queue.Full() << endl;

			cout << std::string("~~~~~PEEK A QUEUE~~~~~") << endl;

			cout << endl;

			cout << std::string("PEEKING AT : ") << the_big_le_queue.Front() << endl;

			cout << endl;

			cout << std::string("~~~~~QUEUE UP~~~~~") << endl;

			cout << endl;

			the_big_le_queue.Clear();

			int adder = 0;
			for (auto i = 0u; i < the_big_le_queue.Size(); ++i)
			{
				cout << std::string("ADDED TO BACK : ") << i << endl;
				the_big_le_queue.Enqueue(adder);
				++adder;
			}

			cout << endl;

			cout << std::string("~~~~~UNWIND THE QUEUE~~~~~") << endl;

			cout << endl;

			 the_big_le_queue.Clear();

			 if (the_big_le_queue.Empty())
			 {
				 //makes sure list is empty so the -1 returned is my flag that it is empty by returning the front
				 cout << the_big_le_queue.Front() << endl;
			 }

			 //ArrayQueue main output showing method functionality
			 cout << std::string("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~") << endl;
			 cout << std::string("ARRAY DEQEUE FUNCTION OUTPUT TESTS") << endl;
			 cout << std::string("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~") << endl;
			 
			 the_big_le_deck.PushFront(7);
			 cout << std::string("PUSHED TO FRONT : ") << the_big_le_deck.Front() << endl;

			the_big_le_deck.PushFront(0);
			cout << std::string("PUSHED TO FRONT : ") << the_big_le_deck.Front() << endl;

			the_big_le_deck.PushFront(7);
			cout << std::string("PUSHED TO FRONT : ") << the_big_le_deck.Front() << endl;

			the_big_le_deck.PushBack(13);
			cout << std::string("PUSHED TO BACK : ") << the_big_le_deck.Back() << endl;

			the_big_le_deck.PushBack(0);
			cout << std::string("PUSHED TO BACK : ") << the_big_le_deck.Back() << endl;

			the_big_le_deck.PushBack(13);
			cout << std::string("PUSHED TO BACK : ") << the_big_le_deck.Back() << endl;

			the_big_le_deck.PushFront(0);
			cout << std::string("PUSHED TO BACK : ") << the_big_le_deck.Front() << endl;

			cout << std::string("~~~~~~~~~~") << endl;
			cout << std::string("NOW CLEARING DECK...") << endl;

			the_big_le_deck.Clear();
			 if (the_big_le_deck.Empty())
			 {
				 cout << std::string("~~~~~~~~~~~") << endl;
				 cout << std::string("EMPTY DECK") << endl;
				 cout << std::string("~~~~~~~~~~~");
			 }
		}
	};