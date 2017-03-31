// HW_1_DJR.cpp : 定义控制台应用程序的入口点。
//

#include "nb.h"


int choose_file[MAX_NN] = { 0 };//随机选取40个文档用作训练集，剩余10个作为测试集
int error_num;//判断测试集错误数

int create_new_file[MAX_NN] = { 0 };
string file_path_1[2] = { "email/ham/" ,"email_new/ham/" };
string file_path_2[2] = { "email/spam/","email_new/spam/" };
string now_path_1 = "";
string now_path_2 = "";
string new_file_path_1 = "email_new/ham/";
string new_file_path_2 = "email_new/spam/";

string large_data_1[2] = { "email_large/ham/","email_large_new/ham/" };
string large_data_2[2] = { "email_large/spam/","email_large_new/spam/" };

string new_large_file_path_1 = "email_large_new/ham/";
string new_large_file_path_2 = "email_large_new/spam/";

int use_stopword = 0;//是否使用停止词表

double smooth = SMOOTH;//拉普拉斯平滑

int num_ham_file = N / 2; //文件数
int num_spam_file = N / 2;
int choose_num = CHOOSE_N;
int choose_ham = 0;
int choose_spam = 0;

double rate_ham, rate_spam;// p(c = ham) p(c = spam)

int error_ham, error_spam;

int sum_ham, sum_spam;//记录ham,spam单词总数

int sum_word;//记录单词类型总数

map<string, int> docwordinclude[MAX_NN];//记录每个文档单词频度表

map<string, int> ham;//记录ham与spam单词频度表
map<string, int> spam;

set<string> wordlist;//记录单词类型表(选取40个）
string get_ui_testfile(int email_class, bool stemmed, bool large, int fileno) {// email_class = 0 : ham       email_class = 1 : spam
	string testfilename;
	string testfilepath;
	if (large == true) {
        testfilepath = "email_large";
	}
	else {
        testfilepath = "email";
	}
	if (stemmed == true) {
		testfilepath = testfilepath + "_new";
	}
    testfilepath = testfilepath + "/";

	if (email_class == 0) {
		testfilepath = testfilepath + "ham/";
	}
	else {
		testfilepath = testfilepath + "spam/";
	}

	IntToString(testfilename, fileno);
	
	return testfilepath + testfilename + ".txt";



}

void get_random() {//取随机数决定训练集与测试集
	int size, random;
	size = 0;
	srand((unsigned)time(NULL));
	while (size < choose_num) {
		random = rand() % (num_ham_file+num_spam_file);
		if (choose_file[random] == 0) {
			size++;
			choose_file[random] = 1;
			if (random < num_ham_file) {
				choose_ham++;
			}
			else {
				choose_spam++;
			}
		}
	}
}


void IntToString(std::string& out, const int value)//int到string的类型转换
{
	std::strstream temp;
	temp << value;
	temp >> out;
}


void find_words_indoc(string file_path, int fileno) {//构建单词频度表
    string filename;
	IntToString(filename, fileno);
	ifstream ifs(file_path + filename + ".txt");
	string line;
	string word;
	int map_num = 0;
	if (file_path == now_path_1) {
		map_num = fileno - 1;
	}
	else if (file_path == now_path_2) {
		map_num = fileno + (num_ham_file - 1);
	}
	else {
		cout << "READ ERROR" << endl;
		system("pause");
	}
	while (getline(ifs, line, '\n'))
	{	

        boost::regex e1("[$'0-9a-zA-Z]+");
		std::string::const_iterator start, end;
		start = line.begin();
        end = line.end();
        //boost::match_all<std::string::const_iterator> what;
        boost::match_results<std::string::const_iterator> what;
        boost::match_flag_type flags = boost::match_default;
        while (boost::regex_search(start, end, what, e1, flags))
		{
			string temp = string(what[0].first, what[0].second);
	//		transform(temp.begin(), temp.end(), temp.begin(), ::tolower); //忽略大小写
			if (use_stopword == 1) {
				set<string>::iterator find_stop;
				find_stop = stopword.find(temp);
				if (find_stop != stopword.end()) {
					start = what[0].second;
					continue;
				}
			}
			if (temp.length() <= 1) {//剔除长度小于等于1的单词
				start = what[0].second;
			}
			else {
				if (choose_file[map_num] == 1) {
					wordlist.insert(temp);
				}
				map<string, int>::iterator iter;
				iter = docwordinclude[map_num].find(temp);
				if (iter != docwordinclude[map_num].end()) {
					int word_num = iter->second;
					iter->second = word_num + 1;
				}
				else {
					docwordinclude[map_num].insert(pair<string, int>(temp, 1));
				}

				start = what[0].second;
            }

        }
	}
	ifs.clear();
    ifs.close();
}



void wordlist_prepare() {//构建各文档单词频度表
	get_random();
	for (int i = 0; i < num_ham_file; i++) {
		find_words_indoc(now_path_1, i + 1);
	}
	for (int j = num_ham_file; j < (num_ham_file+num_spam_file); j++) {
		find_words_indoc(now_path_2, j - num_ham_file + 1);
	}

	sum_word = wordlist.size();
}

void train_hamspam_prepare() {//构建训练集
	for (int k = 0; k < (num_ham_file+num_spam_file); k++) {
		if (choose_file[k] == 1) {
			if (k < num_ham_file) {//ham训练集
				map<string, int>::iterator iter1;
				for (iter1 = docwordinclude[k].begin(); iter1 != docwordinclude[k].end(); iter1++) {
					wordlist.insert(iter1->first);
					map<string, int>::iterator iter_find_1;
					iter_find_1 = ham.find(iter1->first);
					if (iter_find_1 != ham.end()) {
						int word_num = iter_find_1->second;
						iter_find_1->second = word_num + 1;
					}
					else {
						ham.insert(pair<string, int>(iter1->first, 1));
					}
				}

			}
			else {//spam训练集
				map<string, int>::iterator iter2;
				for (iter2 = docwordinclude[k].begin(); iter2 != docwordinclude[k].end(); iter2++) {
					wordlist.insert(iter2->first);
					map<string, int>::iterator iter_find_2;
					iter_find_2 = spam.find(iter2->first);
					if (iter_find_2 != spam.end()) {
						int word_num = iter_find_2->second;
						iter_find_2->second = word_num + 1;
					}
					else {
						spam.insert(pair<string, int>(iter2->first, 1));
					}
				}

			}
		}
	}
}

void rate_prepare() {//计算p(class = c0)与p(class = c1)
	map<string, int>::iterator iter1;
	for (iter1 = ham.begin(); iter1 != ham.end(); iter1++) {
		sum_ham += iter1->second;
	}

	map<string, int>::iterator iter2;
	for (iter2 = spam.begin(); iter2 != spam.end(); iter2++) {
		sum_spam += iter2->second;
	}

	rate_ham = (sum_ham * 1.0) / (sum_ham + sum_spam);
	rate_spam = (sum_spam*1.0) / (sum_ham + sum_spam);

}

double get_ham_value(int no) {//计算p(x | c = ham)
	double Mole;
	double Deno = wordlist.size()*smooth + sum_ham;
	double temp_res;
	double Res = 0;// Res = ∏(Mole/Deno)^n -> Σn(log(Mode/Deno))
	map<string, int>::iterator get;
	map<string, int>::iterator find_;
	for (get = docwordinclude[no].begin(); get != docwordinclude[no].end(); get++) {
		find_ = ham.find(get->first);
		if (find_ != ham.end()) {
			Mole = smooth + find_->second;
		}
		else {
			Mole = smooth;
		}
		temp_res = get->second * log(Mole / Deno);
		Res += temp_res;
	}
	return Res;
}

double get_spam_value(int no) {//计算p(x | c = spam)
	double Mole;
	double Deno = wordlist.size()*smooth + sum_spam;
	double temp_res;
	double Res = 0;// Res = ∏(Mole/Deno)^n -> Σn(log(Mole/Deno))
	map<string, int>::iterator get;
	map<string, int>::iterator find_;
	for (get = docwordinclude[no].begin(); get != docwordinclude[no].end(); get++) {
		find_ = spam.find(get->first);
		if (find_ != spam.end()) {
			Mole = smooth + find_->second;
		}
		else {
			Mole = smooth;
		}
		temp_res = get->second * log(Mole / Deno);
		Res += temp_res;
	}
	return Res;

}
void define_class() {//测试
	for (int i = 0; i < (num_spam_file+num_ham_file); i++) {
		if (choose_file[i] == 0 && i < num_ham_file) {
			double class_0 = get_ham_value(i) + log(rate_ham);
			double class_1 = get_spam_value(i) + log(rate_spam);
		//	cout << "define_class_first" << class_0 << "  " << class_1 << endl;
		//	system("pause");
			if (class_1 > class_0) {
				error_ham += 1;
				error_num += 1;
			}
		}
		else if (choose_file[i] == 0 && i >= num_ham_file) {
			double class_0 = get_ham_value(i) + log(rate_ham);
			double class_1 = get_spam_value(i) + log(rate_spam);
	//		cout << "define_class_second" << class_0 << "  " << class_1 << endl;
	//		system("pause");
			if (class_0 > class_1) {
				error_num += 1;
				error_spam += 1;
			}
		}
	}
}

void NaiveBayes(bool largedataset, bool stemmed, bool banstopword,int& get_choose_ham, int& get_choose_spam,int& get_error_ham, int& get_error_spam){
    if(largedataset == true){
        num_ham_file = L_N_HAM;
        num_spam_file = L_N_SPAM;
        choose_num = L_CHOOSE_N;
        file_path_1[0] = large_data_1[0];
        file_path_1[1] = large_data_1[1];
        file_path_2[0] = large_data_2[0];
        file_path_2[1] = large_data_2[1];
        new_file_path_1 = new_large_file_path_1;
        new_file_path_2 = new_large_file_path_2;
    }
    else{
        num_ham_file = N/2;
        num_spam_file = N/2;
        choose_num = CHOOSE_N;
        file_path_1[0] = "email/ham/";
        file_path_1[1] = "email_new/ham/";
        file_path_2[0] = "email/spam/";
        file_path_2[1] = "email_new/spam/";
        new_file_path_1 = "email_new/ham/";
        new_file_path_2 = "email_new/spam/";

    }
    if(stemmed == true){
        now_path_1 = file_path_1[1];
        now_path_2 = file_path_2[1];
    }
    else{
        now_path_1 = file_path_1[0];
        now_path_2 = file_path_2[0];
    }
    if(banstopword==true){
        prepare_stopword();
        use_stopword = 1;
    }
    else{
        use_stopword = 0;
    }
    smooth = SMOOTH;

    /*programming*/

    error_num = 0;
    error_spam = 0;
    error_ham = 0;

    int sum_choose_ham = 0;
    int sum_choose_spam = 0;
    for (int j = 0; j < TRAIN_NUM; j++) {
        sum_ham = 0;//初始化
        sum_spam = 0;
        sum_word = 0;
        rate_ham = 0.0;
        rate_spam = 0.0;
        choose_ham = 0;
        choose_spam = 0;
        ham.clear();
        spam.clear();
        wordlist.clear();
        for (int i = 0; i < (num_ham_file + num_spam_file); i++) {
            choose_file[i] = 0;
            docwordinclude[i].clear();
        }
        wordlist_prepare();
        train_hamspam_prepare();
        rate_prepare();
        define_class();
        sum_choose_spam = choose_spam;
        sum_choose_ham = choose_ham;
    }

    get_choose_ham = sum_choose_ham;
    get_choose_spam = sum_choose_spam;
    get_error_ham = error_ham;
    get_error_spam = error_spam;
}
bool classify_single_file(bool dataset, int fileno, int file_type){
    if(file_type == 0){
        if(get_spam_value(fileno) > get_ham_value(fileno)){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        if(dataset == 0){
            fileno += N/2;
        }
        else{
            fileno += L_N_HAM;
        }

        if(get_ham_value(fileno) > get_spam_value(fileno)){
            return false;
        }
        else{
            return true;
        }
    }
}
