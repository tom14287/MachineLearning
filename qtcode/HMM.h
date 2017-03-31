
#include <iostream>
#include <string>
#include <tchar.h>
#include <boost/regex.hpp>
#include <boost/xpressive/basic_regex.hpp>
#include <boost/xpressive/xpressive_dynamic.hpp>  
#include <boost/xpressive/regex_primitives.hpp>
#include <boost/xpressive/match_results.hpp>
#include <boost/xpressive/regex_compiler.hpp>
#include <boost/tr1/regex.hpp>
#include <locale.h>  
#include <Windows.h>  
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <float.h>
#include <set>


#define TEST_FILE 0
#define TEST_STR 1
#define MODEL_FROM_DATA 0
#define MODEL_FROM_TRAINFILE 1
#define SENTENCE_SIZE 1<<15
#define NAX_LINE 1<<14
#define CHARACTER_NUM 1<<14
#define STATE_NUM 4
#define STATE_ERROR -1
#define STATE_CONTRADICT -2
#define STATE_B 0
#define STATE_E 1
#define STATE_M 2
#define STATE_S 3

using namespace std;

string wstr2str(const wstring &wstr);
wstring str2wstr(const string& s);
string delete_punctuation(const wstring wstr);
wstring num_transform(wstring num_input);
void stopword_readin(string filename);
void testtxtfile_readin_split(string filename);
void traintxtfile_readin(string filename);
double get_prob_emit(string data);
void prob_emit_readin();
void prob_start_readin();
void prob_trans_readin();
void init_Viterbi();
double prob_emit_value(int state, string character);
double prob_start_value(int state);
double prob_trans_value(int statefrom, int stateto);
void weight_first_element(string first_character);
int Viterbi();
void input_str_transform(string input);
void get_HMM_model();
void load_stopword();
void setup_HMM_model_data();
void setup_HMM_model_train(string filepath, string filename);
string HMM_teststr(string input, bool use_stopword, int model_choose);
void HMM_testfile(string filepath, string filename,bool use_stopword, int model_choose);
