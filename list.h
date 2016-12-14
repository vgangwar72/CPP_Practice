#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

using namespace std;

template <class T>
class list
{
	private:
		struct Node
		{
			Node ()
			{
				mData = 0;
				mNext = NULL;
				cout << "Structure default Constructor" << endl;
			}
			Node (T aData, Node* aNext, Node* aPrev)
			{
				cout << "Paramaterized Constructor" << endl;
				mData = aData;
				mNext = aNext;
				mPrev = aPrev;
			}

			Node (const Node& aNode)
			{
				cout << "Node Copy Constructor" << endl;
				mData = aNode.Data;
				if (aNode.mNext != NULL)
					mNext = new Node (aNode.mNext->mData);
				else
					mNext = NULL;
				if (aNode.mPrev != NULL)
					mPrev = new Node (aNode.mPrev->mData);
				else
					mPrev = NULL;
			}

//			private:

				T 		mData;
				Node* 	mNext;
				Node*	mPrev;
		};

		Node* mHead, mTail;

	public:
		list ();
		~list ();
		list (const list &);
		//creating assignment operator using copy and swap idiom
		list& operator= (list obj);

		template <class X>
		friend void swap (X& aDest, X& aSrc);

	public:
		void push_back (T aData);
		void push_front (T aData);

		T pop_back ();
		T pop_front ();

		Node* begin () const;
		Node* end () const;

		void print ();
	
};

#include "list.tpp"

#endif
