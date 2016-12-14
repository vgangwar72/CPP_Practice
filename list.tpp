
template <class T>
list <T>::list ()  
{
	cout << "List Default COntructor" << endl;
	mHead = NULL;
}

template <class T>
list <T>::~list ()
{
	cout << "List destructor" << endl;
}

template <class T>
list <T>::list (const list& aObj)
{
	cout << "Copy Constructor" << endl;
	Node* temp = aObj.mHead->mPrev;
	while (temp != NULL)
	{
		mHead = temp;
//		mHead->mData = temp->mData;
		//now it is shallow copy
//		mHead->mNext = temp->mNext;
		temp = temp->mNext;
	}
}

template <class T>
list <T>& list <T>::operator= (list aObj)
{
	using std::swap;
   swap (mHead->mData, aObj.mHead->mData);
   // this is also shallow copy
   swap (mHead->mNext, aObj.mHead->mNext);
}

template <class X>
void swap (X& aDest, X& aSrc)
{
	aDest = aSrc;
}

template <class T>
void list <T>::push_back (T aData)
{
	cout << "push_back call with " << aData << " data" << endl;
	Node* temp = mHead;
	Node* prev = NULL;
	while (temp != NULL)
	{
		prev = temp;
		temp = temp->mNext;
	}
	temp = new Node(aData, NULL, NULL);
	if (prev)
		prev->mNext = temp;
	if(!mHead)
		mHead = temp;
	temp->mNext = NULL;
}

template <class T>
void list <T>::print ()
{
	Node* temp = mHead;
	while (temp != NULL)
	{
		cout << temp->mData  << endl;
		temp = temp->mNext;
	}
}




