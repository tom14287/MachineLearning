#include "stopword.h"


string stopword_filepath = "email/stopword/";
string stopword_filename = "english_stopword.txt";
set<string> stopword;//存放停止词表
void prepare_stopword() {//构建停止词表
	ifstream ifs(stopword_filepath + stopword_filename);
	string line ;
	while (getline(ifs, line, '\n')) {
		stopword.insert(line);
	}
	ifs.close();

}
