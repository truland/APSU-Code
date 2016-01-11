/*
Thomas Ruland
CSCI 3250 assignment#2
compiled on ubuntu 14.04 using g++
*/
#ifndef Myvector_HPP
#define MyVector_HPP

using namespace std;

template<class T>
class MyVector{
private:
	int mCap;	//capacity of the array
	int mSize;	//size of the array
	int mAssign;	//number of assignments done to the array
	T* mArr;	//dynamic array for the vector
public:
	MyVector()
	{
		mAssign=0;	//number of assignments done to the array
		mSize=0;	//number of items stored in the array
		mCap=0;	//capacity of the array
		mArr=new T[mCap];	//dynamic array set to default to 0
		for(int i=0; i<mCap; i++)	//setting the initial values to zero
		{
			mArr[i]=0;
			mAssign++;		//technically assignments
		}
	}
	MyVector(const int vecSize)
	{
		mAssign=0;	
		mSize=0;
		mCap=vecSize;
		mArr=new T[mCap];
		for(int i=0; i<mCap; i++)
		{
			mArr[i]=0;
			mAssign++;
		}
	}
	MyVector(const MyVector <T>& Vec)
	{
		this->mSize=Vec.mSize;
		this->mAssign=0;
		this->mCap=Vec.mCap;
		this->mArr=new T[mCap];
		for(int i=0; i<mCap; i++)
		{
			this->mArr[i]=Vec.mArr[i];
			this->mAssign++;
		}
	}
	~MyVector()
	{
		if(mCap>0)
		{
			delete [] mArr;
		}
		mArr=NULL;
	}
	void Reserve(const int newcap)
	{
		if(mCap==0){
			mCap=newcap;
			mSize=0;
			mArr=new T[mCap];
			for(int i=0; i<mCap; i++)
			{
				mArr[i]=0;
				mAssign++;
			}
		}else if(mCap>=newcap)
		{
			return ;
		}else{
			T* temparr=new T[newcap];
			for(int i=0; i<mCap; i++)
			{
				temparr[i]=mArr[i];
				mAssign++;
			}
			delete [] mArr;
			mArr=new T[newcap];
			for(int i=0; i<mCap; i++)
			{
				mArr[i]=temparr[i];
				mAssign++;
			}
			mCap=newcap;
			delete [] temparr;
		}
	}
	void PushBack(const T item)
	{
		if(mCap==0)
		{
			mCap++;
			delete [] mArr;
			mArr=new T[mCap];
			mArr[0]=item;
			mSize++;
			mAssign++;
		}else if((mSize+1)>=mCap)
		{
			Reserve(2*mCap);
			mSize++;
		}else{
			mArr[mSize+1]=item;
			mSize++;
			mAssign++;
		}
	}
	MyVector& operator=(const MyVector& rhs)
	{
		if(this != &rhs)
		{
			if(this->mCap!=0)
			{
				delete [] this->mArr;
			}
			this->mArr=new T[rhs.mCap];
			this->mCap=rhs.mCap;
			this->mSize=rhs.mSize;
			for(int i=0; i<rhs.mCap; i++)
			{
				this->mArr[i]=rhs.mArr[i];
				this->mAssign++;
			}
		}
		return *this;
	}
	int getAssign() const
	{
		return mAssign;
	}
	int getCap() const
	{
		return mCap;
	}
	int getSize() const
	{
		return mSize;
	}
};

#endif
