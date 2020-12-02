#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Message {
private:
	string workMenu = "n:다음 페이지, p:이전 페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장 후 종료";
	string workSpace = "---------------------------------------------------------------------------------------------";
	int temp = 0;

public:
	void printLineAndMenu() {
		cout << workMenu << "\n" << workSpace << endl;
	}
	void printInputAndLine(string input) {
		cout << "입력 : " << input << "\n" << workSpace << endl;
	}
	void consoleMessage(string message) {
		cout << message << "\n" << workSpace << endl;
	}
	void consoleErrorMessage() {
		cout << "The input value is invalid." << "\n" << workSpace << endl;
	}

	void printPrevPage(vector <string> textLine, int& lineIndex, bool& firstPage, bool& lastPage) {
		if (lineIndex >= 20) {	// 21번째 줄부터의 출력
			lineIndex -= 20;
			for (int i = lineIndex; i < lineIndex + 20; i++) {
				cout << setw(2) << i + 1 << "| " << textLine[i] << endl;
				if (i == 0) {
					firstPage = true;
				}
			}
		}
		else {	// 20번째 줄까지의 출력
			temp = lineIndex - 20;	// 차이를 저장하기 위한 변수
			lineIndex = 0;
			for (int i = lineIndex; i < lineIndex + 20 + temp; i++) {
				cout << setw(2) << i + 1 << "| " << textLine[i] << endl;
				if (i == 0) {
					firstPage = true;
				}
			}
		}
		lastPage = false;
		cout << workSpace << endl;
	}

	void printNextPage(vector <string> textLine, int &lineIndex, bool& firstPage, bool& lastPage) {
		if (lineIndex < (int)textLine.size() - 20) {
			lineIndex += 20;
		}
		for (int i = lineIndex; i < lineIndex + 20; i++) {
			cout << setw(2) << i + 1 << "| " << textLine[i] << endl;
			if (i == textLine.size()-1) {
				lastPage = true;
				break;
			}
		}
		firstPage = false;
		cout << workSpace << endl;
	}

	void printPage(vector <string> textLine, int& lineIndex, bool& firstPage, bool& lastPage) {
		for (int i = lineIndex; i < lineIndex + 20; i++) {
			cout << setw(2) << i + 1 << "| " << textLine[i] << endl;
			if (i == textLine.size() - 1) {
				lastPage = true;
				break;
			}
		}
		firstPage = false;
		cout << workSpace << endl;
	}
};

class evaluteParameter {
public:
	bool evalutePrevNextParameter(string userWork) {
		if (userWork.size() == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool evaluteInsertParameter(string& userWork) {
		if (userWork.size() >= 8) {	// i ( 1 , 2 , a )
			userWork.erase(userWork.begin());
			if ((userWork[0] == '(') & (userWork[userWork.size() - 1] == ')')) {
				for (int i = 0; i < (int)userWork.size(); i++) {
					if (userWork[i] == ' ') {	// 공백은 무조건 오류
						return false;
					}
				}
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	bool evaluteDeleteParameter(string& userWork) {
		if (userWork.size() >= 6) {	// d ( 1 , 2 ) 
			userWork.erase(userWork.begin());
			if ((userWork[0] == '(') & (userWork[userWork.size() - 1] == ')')) {
				for (int i = 0; i < (int)userWork.size(); i++) {
					if (userWork[i] == ' ') {	// 공백은 무조건 오류
						return false;
					}
				}
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	bool evaluteChangeParameter(string& userWork) {
		if (userWork.size() >= 6) {	// d ( a , b )
			userWork.erase(userWork.begin());
			if ((userWork[0] == '(') & (userWork[userWork.size() - 1] == ')')) {
				for (int i = 0; i < (int)userWork.size(); i++) {
					if (userWork[i] == ' ') {	// 공백은 무조건 오류
						return false;
					}
				}
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	bool evaluteSearchParameter(string& userWork) {
		if (userWork.size() >= 4) {	// s ( a )
			userWork.erase(userWork.begin());
			if ((userWork[0] == '(') & (userWork[userWork.size() - 1] == ')')) {
				for (int i = 0; i < (int)userWork.size(); i++) {
					if (userWork[i] == ' ') {	// 공백은 무조건 오류
						return false;
					}
				}
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
};

class splitParameter {
private:
	string stringBuffer;
public:
	vector <string> findThreeParameter(string userWork) {	// 입력인자가 3개 일 때
		userWork = userWork.replace(userWork.find("("), 1, "");
		userWork = userWork.replace(userWork.find(")"), 1, "");

		stringstream s(userWork);
		vector <string> inputUser;
		while (getline(s, stringBuffer, ',')) {
			inputUser.push_back(stringBuffer);
		}
		return inputUser;
	}
	vector <string> findTwoParameter(string userWork) {	// 입력인자가 2개 일 때
		userWork = userWork.replace(userWork.find("("), 1, "");
		userWork = userWork.replace(userWork.find(")"), 1, "");

		stringstream s(userWork);
		vector <string> inputUser;
		while (getline(s, stringBuffer, ',')) {
			inputUser.push_back(stringBuffer);
		}
		return inputUser;
	}
	string findOneParameter(string userWork) {	// 입력인자가 1개 일 때
		userWork = userWork.replace(userWork.find("("), 1, "");
		userWork = userWork.replace(userWork.find(")"), 1, "");
		return userWork;
	}
};

class invertText {
public:
	vector <string> changeWordToString(vector <vector<string>> textWord) {	// 단어 단위를 문장 단위로
		vector <string> textLine;
		string text;
		for (int i = 0; i < (int)textWord.size(); i++) {
			text = "";
			for (int j = 0; j < (int)textWord[i].size(); j++) {
				text += textWord[i][j];
				text += ' ';
			}
			textLine.push_back(text);
		}
		return textLine;
	}

	vector<vector<string>> changeStringToWord(vector <string> textLine) {	// 문장 단위를 단어 단위로
		vector <vector <string>> changeStringToWord(textLine.size());
		string stringBuffer;

		for (int i = 0; i < (int)textLine.size(); i++) {
			string inputString = textLine[i];	// (lineIndex-1)번째 줄 문자열을 저장
			stringstream s(inputString);
			while (getline(s, stringBuffer, ' ')) {
				changeStringToWord[i].push_back(stringBuffer);
			}
		}
		return changeStringToWord;
	}

	vector <char> changeStringToChar(vector<string> textline) {	// 문장 단위를 1바이트 단위로
		vector <char> textWord;
		for (int i = 0; i < (int)textline.size(); i++) {
			for (int j = 0; j < int(textline[i].size()); j++) {
				textWord.push_back(textline[i][j]);
			}
		}
		return textWord;
	}

	vector <string> arrangeText(vector<char> textWord) {	// 75바이트 단위로 정렬
		int lineIndex = 0;
		int byteIndex = -1;
		int putNextWordCount = 0;
		bool eofFile = false;
		string sentence;
		string putNextWord;
		vector <string> textLine;
		for (int i = 0; i < (int)textWord.size(); i++) {
			if (textWord[i] != '\n') {
				sentence += textWord[i];
				byteIndex++;
			}
			if (i == textWord.size() - 1) {
				eofFile = true;
			}
			if (textWord[i] == '\n') {
				textLine.push_back(sentence);
				lineIndex++;	// 다음 줄 vector에 넣을 수 있게 index + 1
				byteIndex = -1;	// 75byte를 셀 수 있게 byteIndex를 다시 초기화
				sentence = ""; // 문자열 초기화
			}
			if (((byteIndex % 75 == 0) & (byteIndex != 0)) || eofFile == true) {
				if ((textWord[i] == ' ') || (eofFile == true)) {	// 75번째 문자가 개행인 경우
					textLine.push_back(sentence);
					lineIndex++;	// 다음 줄 vector에 넣을 수 있게 index + 1
					byteIndex = -1;	// 75byte를 셀 수 있게 byteIndex를 다시 초기화
					sentence = ""; // 문자열 초기화
				}
				else {	// 75번째가 문자인 경우
					for (int j = i; j >= 0; j--) {
						if (textWord[j] == ' ') {
							break;
						}
						putNextWord += textWord[j];	// 다음 줄로 이동시킬 단어가 역으로 저장
						putNextWordCount++;
					}
					reverse(putNextWord.begin(), putNextWord.end());	// 단어를 원래의 형태로 저장
					sentence = sentence.substr(0, 76 - putNextWordCount);	// 잘린 단어를 제외한 문장을 저장
					textLine.push_back(sentence);	// 문장을 vector에 저장
					lineIndex++;	// 다음 줄 vector에 넣을 수 있게 index + 1
					sentence = "";	// 문자열 초기화
					sentence = putNextWord;	// 다음 문장으로 이동시킬 단어
					byteIndex = putNextWordCount - 1;
					putNextWord = "";
					putNextWordCount = 0;
				}
			}
		}
		return textLine;
	}
};

class textWork {
private:
	int checkIndex;
	int findCount;

public:
	int insertword(int lineIndex, int wordIndex, int pageNumber, int eofFile, string word, vector<vector <string>>& textWord) {	// ?번째 줄의 ?번째 뒤에 단어 삽입
		if (((lineIndex > 0 + pageNumber*20) & (lineIndex <= 20 + pageNumber*20)) & (wordIndex > 0) & (lineIndex <= eofFile)) {
			if ((wordIndex - 1 < (int)textWord[lineIndex - 1].size()) & (wordIndex >= 1) & (word.size() <= 75)) {
					textWord[lineIndex - 1].insert(textWord[lineIndex - 1].begin() + wordIndex, word);
					return 0;
			}
			else {
				return -1;	// 비정상종료
			}
		}
		else {
			return -1;	// 비정상종료
		}
	}

	int deleteword(int lineIndex, int wordIndex, int pageNumber, int eofFile, vector<vector <string>>& textWord) {	// ?번째 줄의 ?번째 단어 삭제
		if (((lineIndex > 0 + pageNumber * 20) & (lineIndex <= 20 + pageNumber * 20)) & (wordIndex > 0) & (lineIndex <= eofFile)) {
			if ((wordIndex - 1 < (int)textWord[lineIndex - 1].size()) & (wordIndex >= 1)) {
				textWord[lineIndex - 1].erase(textWord[lineIndex - 1].begin() + (wordIndex - 1));
				return 0;
			}
			else {
				return -1;	// 비정상종료
			}
		}
		else {
			return -1;	// 비정상종료
		}
	}

	int changeWord(string word1, string word2, vector <string>& textLine) {
		findCount = 0;
		for (int i = 0; i < (int)textLine.size(); i++) {
			checkIndex = textLine[i].find(word1);
			if (checkIndex != string::npos) {
				findCount += 1;
				textLine[i] = textLine[i].replace(checkIndex, word1.size(), word2);
			}
		}
		if (findCount != 0) {
			return 0;
		}
		else {
			return -1;
		}
	}

	int findStringReturnIndex(vector <string> textLine, string findWord) {
		for (int i = 0; i < (int)textLine.size(); i++) {
			if (textLine[i].find(findWord) != string::npos) {
				return i;
			}
		}
		return -1;	// 해당 문자열이 존재하지 않는 경우
	}
};

int main() {
	Message message;
	evaluteParameter checkParameter;
	splitParameter splitpara;
	textWork textwork;
	invertText inverttext;
	vector <char> textWord;
	vector <string> textLine;
	string userWork;
	string inputWord;
	vector <string> inputUser;
	vector <vector <string>> stwWord;
	vector <string> wtsString;
	vector <char> stcChar;
	string findWord;
	int word;
	int changeWordCheck;
	int temp = 0;
	int lineIndex = 0;
	int wordIndex = 0;
	int pageNumber = 0;
	int eofFile = 0;
	bool firstPage = false;
	bool lastPage = false;

	ifstream in("test.txt");

	while ((word = in.get()) != EOF) {
		textWord.push_back(word);
	}
	
	textLine = inverttext.arrangeText(textWord);
	eofFile = textLine.size();
	message.printPage(textLine, lineIndex, firstPage, lastPage);
	message.printLineAndMenu();

	getline(cin, userWork);
	message.printInputAndLine(userWork);

	while (userWork[0] != 't') {
		switch (userWork[0]) {
		case 'n':	// 다음 페이지 출력
			if (checkParameter.evalutePrevNextParameter(userWork)) {
				if (!lastPage) {
					message.printNextPage(textLine, lineIndex, firstPage, lastPage);
					pageNumber++;
				}
				else {
					message.consoleMessage("This is the Last Page");
					firstPage = false;
				}
				message.printLineAndMenu();
				getline(cin, userWork);
				message.printInputAndLine(userWork);
			}
			else {
				message.consoleErrorMessage();
				message.printLineAndMenu();
				getline(cin, userWork);
				message.printInputAndLine(userWork);
			}
			break;

		case 'p':	// 이전 페이지 출력
			if (checkParameter.evalutePrevNextParameter(userWork)) {
				if (!firstPage) {
					message.printPrevPage(textLine, lineIndex, firstPage, lastPage);
					pageNumber--;
				}
				else {
					message.consoleMessage("This is the First Page");
					lastPage = false;
				}
				message.printLineAndMenu();
				getline(cin, userWork);
				message.printInputAndLine(userWork);
			}
			else {
				message.consoleErrorMessage();
				message.printLineAndMenu();
				getline(cin, userWork);
				message.printInputAndLine(userWork);
			}
			break;

		case 'i':	// 삽입
			if (checkParameter.evaluteInsertParameter(userWork)) {
				inputUser = splitpara.findThreeParameter(userWork);
				temp = lineIndex;
				try {
					lineIndex = stoi(inputUser[0]);
					wordIndex = stoi(inputUser[1]);
				}
				catch (invalid_argument) {
					lineIndex = temp;
					message.consoleErrorMessage();
					message.printLineAndMenu();
					getline(cin, userWork);
					message.printInputAndLine(userWork);
					break;
				}
				inputWord = inputUser[2];
				stwWord = inverttext.changeStringToWord(textLine);
				if (textwork.insertword(lineIndex, wordIndex, pageNumber, eofFile, inputWord, stwWord) == 0) {	// 정상적으로 삽입
					wtsString = inverttext.changeWordToString(stwWord);	// 단어 단위를 문장 단위로
					stcChar = inverttext.changeStringToChar(wtsString);	// 문장 단위를 1바이트 단위로
					textLine = inverttext.arrangeText(stcChar);	// 75바이트 단위로
					eofFile = textLine.size();
					lineIndex = temp;
					message.printPage(textLine, lineIndex, firstPage, lastPage);
					message.printLineAndMenu();
					getline(cin, userWork);
					message.printInputAndLine(userWork);
				}
				else {	// 다시
					lineIndex = temp;
					message.consoleErrorMessage();
					message.printLineAndMenu();
					getline(cin, userWork);
					message.printInputAndLine(userWork);
				}
			}
			else {
				lineIndex = temp;
				message.consoleErrorMessage();
				message.printLineAndMenu();
				getline(cin, userWork);
				message.printInputAndLine(userWork);
			}
			break;

		case 'd':	// 삭제
			if (checkParameter.evaluteDeleteParameter(userWork)) {
				inputUser = splitpara.findTwoParameter(userWork);
				temp = lineIndex;
				try {
					lineIndex = stoi(inputUser[0]);
					wordIndex = stoi(inputUser[1]);
				}
				catch (invalid_argument) {
					lineIndex = temp;
					message.consoleErrorMessage();
					message.printLineAndMenu();
					getline(cin, userWork);
					message.printInputAndLine(userWork);
				}
				stwWord = inverttext.changeStringToWord(textLine);	// 문장 단위를 단어 단위로
				if (textwork.deleteword(lineIndex, wordIndex, pageNumber, eofFile, stwWord) == 0) {	// 정상적으로 삭제
					wtsString = inverttext.changeWordToString(stwWord);	// 단어 단위를 문장 단위로
					stcChar = inverttext.changeStringToChar(wtsString);	// 문장 단위를 1바이트 단위로
					textLine = inverttext.arrangeText(stcChar);	// 75바이트 단위로
					eofFile = textLine.size();
					lineIndex = temp;
					message.printPage(textLine, lineIndex, firstPage, lastPage);
					message.printLineAndMenu();
					getline(cin, userWork);
					message.printInputAndLine(userWork);
				}
				else {
					lineIndex = temp;
					message.consoleErrorMessage();
					message.printLineAndMenu();
					getline(cin, userWork);
					message.printInputAndLine(userWork);
				}
			}
			else {
				lineIndex = temp;
				message.consoleErrorMessage();
				message.printLineAndMenu();
				getline(cin, userWork);
				message.printInputAndLine(userWork);
			}
			break;

		case 'c':	// 변경
			if (checkParameter.evaluteChangeParameter(userWork)) {
				inputUser = splitpara.findTwoParameter(userWork);
				changeWordCheck = textwork.changeWord(inputUser[0], inputUser[1], textLine);
				if (changeWordCheck == 0) {
					stcChar = inverttext.changeStringToChar(textLine);	// 문장 단위를 1바이트 단위로
					textLine = inverttext.arrangeText(stcChar);	// 75바이트 단위로
					message.printPage(textLine, lineIndex, firstPage, lastPage);
					message.printLineAndMenu();
					getline(cin, userWork);
					message.printInputAndLine(userWork);
				}
				else {
					message.consoleMessage("No Exist Word");
					message.printLineAndMenu();
					getline(cin, userWork);
					message.printInputAndLine(userWork);
				}
			}
			else {
				message.consoleErrorMessage();
				message.printLineAndMenu();
				getline(cin, userWork);
				message.printInputAndLine(userWork);
			}
			break;

		case 's':	// 찾기 (완료)
			if (checkParameter.evaluteSearchParameter(userWork)) {
				findWord = splitpara.findOneParameter(userWork);
				temp = lineIndex;
				lineIndex = textwork.findStringReturnIndex(textLine, findWord);
				if (lineIndex != -1) {
					message.printPage(textLine, lineIndex, firstPage, lastPage);
					message.printLineAndMenu();
					getline(cin, userWork);
					message.printInputAndLine(userWork);
				}
				else {
					lineIndex = temp;
					message.consoleMessage("No Exist Word");
					message.printLineAndMenu();
					getline(cin, userWork);
					message.printInputAndLine(userWork);
				}
			}
			else {
				message.consoleErrorMessage();
				message.printLineAndMenu();
				getline(cin, userWork);
				message.printInputAndLine(userWork);
			}
			break;

		default:// 오류 - 재입력
			message.consoleErrorMessage();
			message.printLineAndMenu();
			getline(cin, userWork);
			message.printInputAndLine(userWork);
			break;
		}
	}

	ofstream out("test.txt");	// 파일 저장
	for (int i = 0; i < (int)textLine.size(); i++) {
		out << textLine[i];
	}
}