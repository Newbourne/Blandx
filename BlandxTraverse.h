#include "MergeSort.h"
#include "string.h"
#include <list>
#include <fstream>
#include <boost/filesystem.hpp>

using namespace std;
namespace fs = boost::filesystem;

class BlandxTraverse
{
private:
    size_t file_count;
    list<BlandxFile> files;
	BlandxFile* sorted_files;

	void traverse_directory(string directory)
	{
		fs::path filepath(directory);

		if (fs::exists(filepath))
		{
			if (is_regular_file(filepath))
			{
				// Create BlandxFile
				BlandxFile file;

				// Capture Filename, properties
				string filename = filepath.filename().string();
				boost::algorithm::to_lower(filename);

				file.Filename = filename;
				file.Extension = filepath.extension().string();
				file.Size = fs::file_size(filepath);
				file.FullPath = filepath.string();

				// Add to list
				files.push_back(file);
			}
			else if (is_directory(filepath))
			{
				// Traverse directory tree
				fs::directory_iterator end;

				for (fs::directory_iterator iter(filepath); iter != end; ++iter)
				{
					traverse_directory(iter->path().string());
				}
			}
		}
	}

	void sort_files()
	{
		MergeSort sorter;
		sorted_files = new BlandxFile[files.size()];
		sorter.start(files, sorted_files);
	}

	void parse_duplicates()
	{
		files.clear();

		string compare1 = "";
		string compare2 = "";
		string compare3 = "";

        for (int i = 0; i < (int)file_count - 1; i++)
		{
			compare1 = sorted_files[i].Filename;
			compare2 = sorted_files[i + 1].Filename;

			if (compare1 == compare2)
				files.push_back(sorted_files[i]);
			else if (files.size() > 0)
				compare3 = files.back().Filename;
				if (compare3 == compare1)
					files.push_back(sorted_files[i]);

			if (i == file_count - 2)
			{
				if (files.back().Filename == compare2)
					files.push_back(sorted_files[i + 1]);
			}
		}
	}

	void write()
	{
		string filename = "Duplicates.txt";

		if (fs::exists(filename))
			fs::remove(filename);

		ofstream myFile;
		myFile.open(filename);
		
		string previous_file = "";
		for (list<BlandxFile>::iterator it = files.begin(); it != files.end(); it++)
		{
			if (it->Filename != previous_file)
				myFile << endl;
			myFile << it->FullPath << endl;
			previous_file = it->Filename;
		}
			
		myFile.close();
	}

public:
	BlandxTraverse()
	{
	}

	~BlandxTraverse()
	{
	}

	void compile(string directory)
	{
		try
		{
			cout << "Clearing Cache..." << endl;
			files.clear();

			cout << "Parsing Directory.." << endl;
			traverse_directory(directory);
			file_count = files.size();

			cout << "Sorting Files..." << endl;
			sort_files();	

			cout << "Collecting Duplicates..." << endl;
			parse_duplicates();

			cout << "Writing results to output..." << endl;
			write();
		}
		catch (exception ex)
		{
			throw ex;
		}
	}

	list<BlandxFile> get_files()
	{
		return files;
	}
};
