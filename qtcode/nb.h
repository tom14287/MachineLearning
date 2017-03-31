#pragma once

#include <cmath>
#include <map>
#include <cassert>
#include <vector>
#include <string>
#include <ctime>
#include <ctype.h>
#include "common.h"
#include <boost/regex.hpp>
using namespace std;

#define N 50

#define CHOOSE_N 40

#define L_CHOOSE_N 3462

#define L_N_HAM 2949

#define L_N_SPAM 1378

#define TRAIN_NUM 1

#define MAX_NN 6000

#define SMOOTH 1

#define SMOOTH_STEP 0.05

#define SPAM_ERROR_COST 1

#define HAM_ERROR_COST 20


extern void prepare_stopword();
extern set<string> stopword;



string get_ui_testfile(int email_class, bool stemmed, bool large, int fileno);
void get_random();
void IntToString(std::string& out, const int value);
void find_words_indoc(string file_path, int fileno);
void wordlist_prepare();
void train_hamspam_prepare();
void rate_prepare();
double get_ham_value(int no);
double get_spam_value(int no);
void define_class();
void NaiveBayes(bool largedataset, bool stemmed, bool banstopword,int& get_choose_ham, int& get_choose_spam,int& get_error_ham, int& get_error_spam);
bool classify_single_file(bool dataset, int fileno, int file_type);
