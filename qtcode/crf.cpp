#include "crf.h"


string wstr2str_(const wstring &wstr)
{

	string result;
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
	char* buffer = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';
	result.append(buffer);
	delete[] buffer;
	return result;

}

wstring str2wstr_(const string& s)
{
	setlocale(LC_ALL, "chs");
	const char* _Source = s.c_str();
	size_t _Dsize = s.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest, _Source, _Dsize);
	std::wstring result = _Dest;
	delete[]_Dest;
	setlocale(LC_ALL, "C");
	return result;
}

void testfile_format(string filepath, string filename) {
	string file = filepath + filename;
	string newfile = filepath + "test_format.data";
	fstream newfile_exist;
	newfile_exist.open(newfile);
	if (newfile_exist) {
		remove(newfile.c_str());
	}
	newfile_exist.close();

	ifstream openfile(file);
	ofstream writefile(newfile);

	string get_line;
	while (getline(openfile, get_line, '\n')) {
        wstring temp_ws = str2wstr_(get_line);

		boost::wregex wreg(L"([\u0001-\u0009\u000b-\u000c\u000e-\u001f\u0021-\uffff]+)", boost::regex::perl | boost::regbase::icase);
		boost::smatch what;
		boost::wsmatch wswhat;
		wstring::const_iterator start = temp_ws.begin();
		wstring::const_iterator end = temp_ws.end();
		while (boost::regex_search(start, end, wswhat, wreg)) {
			wstring temp_split_ws = wstring(wswhat[0].first, wswhat[0].second);
            string temp_split_s = wstr2str_(temp_split_ws);

			
			if (temp_split_s.length() % 2 != 0) {
				cout << temp_split_s << endl;
				cout << "test split fail" << endl;
				system("pause");
			}

			

			if (temp_split_s.length() == 2) {//B
				string first_ch = temp_split_s.substr(0, 2);
				writefile << first_ch << ' ' << 'S' << '\n';
			}
			else if (temp_split_s.length() == 4) {//BE
				string first_ch = temp_split_s.substr(0, 2);
				string last_ch = temp_split_s.substr(2, 2);
				writefile << first_ch << ' ' << 'B' << '\n';
				writefile << last_ch << ' ' << 'E' << '\n';
			}
			else {//BME
				string first_ch = temp_split_s.substr(0, 2);
				string last_ch = temp_split_s.substr(temp_split_s.length() - 2, 2);
				writefile << first_ch << ' ' << 'B' << '\n';
				for (int i = 2; i <= temp_split_s.length() - 4; i += 2) {
					string middle_ch = temp_split_s.substr(i, 2);
					writefile << middle_ch << ' ' << 'M' << '\n';
				}
				writefile << last_ch << ' ' << 'E' << '\n';

			}
		

			start = wswhat[0].second;
		}


	}

}

void trainfile_format(string filepath, string filename) {
	string file = filepath + filename;
	string newfile = filepath + "train_format.data";
	fstream newfile_exist;
	newfile_exist.open(newfile, ios::in);
	if (newfile_exist) {
		remove(newfile.c_str());
	}
	newfile_exist.close();

	ifstream openfile(file);
	ofstream writefile(newfile);

	string get_line;
	while (getline(openfile, get_line, '\n')) {
		//cout << get_line << endl;
        wstring temp_ws = str2wstr_(get_line);
		//boost::wregex wreg(L"([\u002D\u002F\u0041-\u005A\u0061-\u007A\u0030-\u0039\u2E80-\uFFEE]+)", boost::regex::perl | boost::regbase::icase);
		boost::wregex wreg(L"([\u0001-\u0009\u000b-\u000c\u000e-\u001f\u0021-\uffff]+)", boost::regex::perl | boost::regbase::icase);
		boost::smatch what;
		boost::wsmatch wswhat;
		wstring::const_iterator start = temp_ws.begin();
		wstring::const_iterator end = temp_ws.end();
		bool flag = false;
		while (boost::regex_search(start, end, wswhat, wreg)) {
			if (flag == false) {
				start = wswhat[0].second;
				flag = true;
				continue;
			}
			wstring temp_split_ws = wstring(wswhat[0].first, wswhat[0].second);
            string temp_split_s = wstr2str_(temp_split_ws);
			
			if (temp_split_s.substr(0, 1) == "[") {	
				temp_split_s = temp_split_s.substr(1, temp_split_s.length() - 1);
			}

			if (temp_split_s[temp_split_s.length() - 3] == ']'){
				temp_split_s = temp_split_s.substr(0, temp_split_s.length() - 3);
					
			}

			int len = temp_split_s.length();
			
			int label_pos = 0;
			int label_len = 0;
			for (int j = temp_split_s.length() - 1; j >= 0; j--) {
				if (!((temp_split_s[j] >= 'a' && temp_split_s[j] <= 'z') || (temp_split_s[j] >= 'A' && temp_split_s[j] <= 'Z') )) {
					
					label_pos = j;
					label_len = temp_split_s.length() - label_pos;
					
					break;
				}

			}

			string get_label = temp_split_s.substr(label_pos + 1, temp_split_s.length() - label_pos -1);
			
			if ((len - label_len) % 2 !=0 || (len - label_len <= 0)) {
				cout << "sentence split fail" << endl;
				system("pause");

			}
			else if ((len - label_len) <= 2) {//S
				string first_ch = temp_split_s.substr(0, (len - label_len));
				writefile << first_ch << ' ' << get_label << ' ' << 'S' << '\n';
				if (first_ch == "。") {
					writefile << '\n';
				}
			}
			else if ((len - label_len) == 4) {//BE
				string first_ch = temp_split_s.substr(0, 2);
				string last_ch = temp_split_s.substr(label_pos - 2, 2);
				writefile << first_ch << ' ' << get_label << ' ' << 'B' << '\n';
				writefile << last_ch << ' ' << get_label << ' ' << 'E' << '\n';
			}
			else {//BME
				string first_ch = temp_split_s.substr(0, 2);
				writefile << first_ch << ' ' << get_label << ' ' << 'B' << '\n';
				string last_ch = temp_split_s.substr(label_pos - 2, 2);
				for (int i = 2; i <= temp_split_s.length() - 6; i += 2) {
					string middle_ch = temp_split_s.substr(i, 2);
					writefile << middle_ch << ' ' << get_label << ' ' << 'M' << '\n';
				}
				writefile << last_ch << ' ' << get_label << ' ' << 'E' << '\n';
			}
			start = wswhat[0].second;
		}

	}
	writefile << '\n';
	openfile.close();
	writefile.close();
}

void evaluation(string filepath, string filename) {
	string file = filepath + filename;
	ifstream openfile(file);
	string get_line;

	double recall = 0;
	double precision = 0;
	double Fscore = 0;

	int gold_word_cnt = 0;
	int predict_word_cnt = 0;
	int predict_correct_cnt = 0;

	int now_word_length = 0;
	int now_word_match = 0;

	while (getline(openfile, get_line, '\n')) {
		if (get_line[3] == 'B' || get_line[3] == 'S') {
			gold_word_cnt++;
		}
		if (get_line[5] == 'B' || get_line[5] == 'S') {
			predict_word_cnt++;
		}

		if (get_line[3] == 'S') {
			if (get_line[5] == 'S') {
				predict_correct_cnt++;
			}
			now_word_length = 0;
			now_word_match = 0;
		}
		else {
			if (get_line[3] == get_line[5]) {
				now_word_match++;
			}
			if (get_line[3] == 'B') {
				now_word_length = 1;
			}
			else if (get_line[3] == 'M') {
				now_word_length++;
			}
			else if (get_line[3] == 'E') {
				now_word_length++;

				if (now_word_length == now_word_match) {
					predict_correct_cnt++;
				}

				now_word_length = 0;
				now_word_match = 0;
			}



		}
	}
	recall = predict_correct_cnt * 1.0 / gold_word_cnt;
	precision = predict_correct_cnt * 1.0 / predict_word_cnt;
	Fscore = 2 * recall * precision / (recall + precision);

	cout << "precision : " << precision << endl;
	cout << "recall : " << recall << endl;
	cout << "F1-score : " << Fscore << endl;
	openfile.close();

}

string teststr(string inputstr, string crf_model_file) {
	string temp_data_file = "temp_str_data.txt";
	fstream tempfile_exist;
	tempfile_exist.open(temp_data_file, ios::in);
	if (tempfile_exist) {
		remove(temp_data_file.c_str());
	}
	tempfile_exist.close();

	ofstream writefile(temp_data_file);

    wstring inputstr_ws = str2wstr_(inputstr);

	boost::wregex wreg(L"([\u0001-\u0009\u000b-\u000c\u000e-\u001f\u0021-\uffff])", boost::regex::perl | boost::regbase::icase);
	boost::smatch what;
	boost::wsmatch wswhat;
	wstring::const_iterator start = inputstr_ws.begin();
	wstring::const_iterator end = inputstr_ws.end();

	while (boost::regex_search(start, end, wswhat, wreg)) {
		wstring temp_split_ws = wstring(wswhat[0].first, wswhat[0].second);
        string temp_split_s = wstr2str_(temp_split_ws);

		writefile << temp_split_s << '\n';

		start = wswhat[0].second;
	}

	writefile.close();

	system("crf_test -m model_pku temp_str_data.txt > temp_str_output.txt");

	string result = "";

	ifstream openfile("temp_str_output.txt");
	string get_line_res;
	while (getline(openfile, get_line_res, '\n')) {
		if (get_line_res.length() <= 0) {
			break;
		}
		string get_state = get_line_res.substr(get_line_res.length() - 1, 1);
		string get_ch = get_line_res.substr(0, get_line_res.length() - get_state.length() - 1);

		result += get_ch;
		if (get_state == "S" || get_state == "E") {
			result += "/ ";
		}
	}

	result += '\n';

	return result;
}

void ui_testfile(string filepath, string filename) {
    string testfile = filepath + filename;
    string newtest_file = testfile + ".data";

    fstream newfile_exist;
    newfile_exist.open(newtest_file);
    if (newfile_exist) {
        remove(newtest_file.c_str());
    }
    newfile_exist.close();

    ofstream writefile(newtest_file);
    ifstream openfile(testfile);

    string get_line;
    while (getline(openfile, get_line, '\n')) {
        wstring temp_ws = str2wstr_(get_line);
        boost::wregex wreg(L"([\u0001-\u0009\u000b-\u000c\u000e-\u001f\u0021-\uffff])", boost::regex::perl | boost::regbase::icase);
        boost::smatch what;
        boost::wsmatch wswhat;
        wstring::const_iterator start = temp_ws.begin();
        wstring::const_iterator end = temp_ws.end();
        while (boost::regex_search(start, end, wswhat, wreg)) {
            wstring temp_split_ws = wstring(wswhat[0].first, wswhat[0].second);
            string temp_split_s = wstr2str_(temp_split_ws);

            writefile << temp_split_s << '\n';

            start = wswhat[0].second;
        }
    }

    openfile.close();
    writefile.close();

    string output_file = "testfile_output.txt";

    fstream output_exist;
    output_exist.open(output_file);
    if (output_exist) {
        remove(output_file.c_str());
    }
    output_exist.close();
    //cout << "cmd" << endl;
    string command = "crf_test -m model_pku " + newtest_file + " > " + output_file;
    system(command.c_str());

    string res_file = "testfile_res.txt";
    fstream res_exist;
    res_exist.open(res_file);
    if (res_exist) {
        remove(res_file.c_str());
    }

    res_exist.close();

    ofstream writeres(res_file);
    ifstream openoutput(output_file);
    string get_line_;
    while (getline(openoutput, get_line_, '\n')) {
        if (get_line_.length() <= 0) {
            break;
        }
       // cout << get_line_ << endl;
       // system("pause");
        string get_state_ = get_line_.substr(get_line_.length() - 1, 1);
        string get_ch_ = get_line_.substr(0, get_line_.length() - get_state_.length() - 1);

        writeres << get_ch_;
        if (get_state_ == "E" || get_state_ == "S") {
            writeres << "/ ";
        }
    }
    writeres.close();
    openoutput.close();

}
/*int main() {
	//system("crf_learn template train.data model2");
	//system("crf_test -m model_pku test_format.data > output_format_test.txt");
	//trainfile_format("", "pku_training_2.txt");
	//cout << " train format finish!" << endl;
	//system("crf_learn template train_format.data model_pku");
	//testfile_format("", "pku_test_gold.txt");
	//evaluation("", "output_format_test.txt");
	cout << teststr("小明硕士毕业于复旦大学计算机系。", "model_pku");
	system("pause");
	return 0;
}*/
