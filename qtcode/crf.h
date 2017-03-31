
#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<fstream>
#include<string>
#include <locale.h>  
#include <Windows.h>  
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <float.h>
#include <set>

#include <boost/regex.hpp>
#include <boost/xpressive/xpressive_dynamic.hpp>  
#include <boost/xpressive/regex_primitives.hpp>
#include <boost/tr1/regex.hpp>

using namespace std;


string wstr2str_(const wstring &wstr);
wstring str2wstr_(const string& s);
void testfile_format(string filepath, string filename);
void trainfile_format(string filepath, string filename);
void evaluation(string filepath, string filename);
string teststr(string inputstr, string crf_model_file);
void ui_testfile(string filepath, string filename);
