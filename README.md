Blandx
======

PB's Directory Parser


== Why?

My dad has a ton of files stored and he wanted a way to find all the duplicates to free up some space. This should really be a simple script to iterate the through a directory tree and return the duplicates. I (as always) want to get more involved with C++ development. I was researching boost libraries at the time and decided to give it a shot.

Given a directory the application will parse through the entire tree and capture all file duplicates. In this first (only) version duplicates are strictly based on filename. We considered looking at partial filenames and filesize but never got to it.
