#include <list>
#include "BlandxFile.h"
#include <boost/algorithm/string.hpp>
using namespace std;

class MergeSort
{
private:

public:
	MergeSort()
	{

	}

	~MergeSort()
	{

	}

	void start(list<BlandxFile> files, BlandxFile*& collection)
	{
        size_t count = files.size();
		int index = 0;
		BlandxFile* collection_a = new BlandxFile[count];
		for (list<BlandxFile>::iterator it = files.begin(); it != files.end(); it++)
		{
			collection_a[index] = *it;
			index++;
		}

		split_merge(collection_a, 0, count, collection);
	}

    void split_merge(BlandxFile* A, size_t iBegin, size_t iEnd, BlandxFile* B)
	{
		if (iEnd - iBegin < 2)
			return;
        size_t iMiddle = (iEnd + iBegin) / 2;
		split_merge(A, iBegin, iMiddle, B);
		split_merge(A, iMiddle, iEnd, B);
		merge(A, iBegin, iMiddle, iEnd, B);
		copy_array(B, iBegin, iEnd, A);
	}

    void merge(BlandxFile* A, size_t iBegin, size_t iMiddle, size_t iEnd, BlandxFile* B)
	{
        size_t iter1 = iBegin;
        size_t iter2 = iMiddle;

        for (size_t i = iBegin; i < iEnd; i++)
		{
			if (iter1 < iMiddle && (iter2 >= iEnd || compare_filename(A[iter1].Filename, A[iter2].Filename)))
			{
				B[i] = A[iter1];
				iter1++;
			}
			else
			{
				B[i] = A[iter2];
				iter2++;
			}
		}
	}

    void copy_array(BlandxFile* B, size_t iBegin, size_t iEnd, BlandxFile* A)
	{
        for (size_t i = iBegin; i < iEnd; i++)
			A[i] = B[i];
	}

	bool compare_filename(string filename1, string filename2)
	{
		string target = filename1;
		string compare = filename2; 
			
		for (int i = 0; i < (int)target.length(); i++)
		{
			if (i < ((int)compare.length()))
			{
				if (target[i] == compare[i])
					continue;
				else if (target[i] < compare[i])
					return true;
				else
					return false;
			}
		}
		return true;
	}
};
