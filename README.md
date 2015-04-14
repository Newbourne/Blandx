Blandx (Deprecated)
======

PB's Directory Parser

Development: Deprecated

Start Date: Summer 2014
End Date: Summer 2014

## Why?

My dad has a ton of files stored and he wanted a way to find all the duplicates to free up some space. This should really be a simple script to iterate the through a directory tree and return the duplicates. I (as always) want to get more involved with C++ development. I was researching boost libraries at the time and decided to give it a shot.

Given a directory the application will parse through the entire tree and capture all file duplicates. In this first (only) version duplicates are strictly based on filename. We considered looking at partial filenames and filesize but never got to it.

## How?

We parse a directory tree and store all filenames in memory. We then use a merge sort to order the filenames in a list. Once we have the filenames sorted in a list we iterate over the names and look for duplicates.

I'll be the first to tell you that this isn't the most efficient way to do this. The only dependecy I wanted was the boost libraries. The application performed well for our needs.
