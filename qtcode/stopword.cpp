#include "stopword.h"


string stopword_filepath = "email/stopword/";
string stopword_filename = "english_stopword.txt";
set<string> stopword;//���ֹͣ�ʱ�
void prepare_stopword() {//����ֹͣ�ʱ�
	ifstream ifs(stopword_filepath + stopword_filename);
	string line ;
	while (getline(ifs, line, '\n')) {
		stopword.insert(line);
	}
	ifs.close();

}
