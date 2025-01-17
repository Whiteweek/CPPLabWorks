#include "pch.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

void textprocess(const char* text) {
	cout << "Исходный текст:\n" << text << endl;
	cout << "\nНажмите Enter, чтобы обработать каждое предложение...\n";
	cin.ignore();

	const char* s_start = text; // sentence start
	while (*s_start != '\0') {
		const char* s_end = strchr(s_start, '.'); // sentence end
		if (!s_end) {
			s_end = s_start + strlen(s_start);
		}

		char* sentence = new char[s_end - s_start + 2];
		strncpy_s(sentence, s_start, s_end - s_start + 1);
		sentence[s_end - s_start + 1] = '\0';

		cout << "\nОбрабатываю предложение: " << sentence << endl;

		for (size_t i = 0; i < strlen(sentence); ++i) {
			if (!isalpha(sentence[i]) && !isspace(sentence[i])) {
				cout << "Небуквенный/пробеловый символ: " << sentence[i] << endl;
			}
		}

		delete[] sentence;

		if (*s_end == '\0') break;
		s_start = s_end + 1;
	}
}

void countShortWords(const char* text, int k) {
	const char* s_end = strchr(text, '.');
	if (!s_end) {
		cout << "В тексте не найдено ни одного предложения.\n";
		return;
	}

	char* sentence = new char[s_end - text + 2];
	strncpy_s(sentence, text, s_end - text + 1);
	sentence[s_end - text + 1] = '\0';

	cout << "\nПервое предложение: " << sentence << endl;

	char* copy = new char[strlen(sentence) + 1];
	strcpy_s(copy, sentence);

	char* word = strtok_s(copy, " ");
	int count = 0;

	cout << "Слова с длиной < " << k << ":\n";

	while (word) {
		int wlength = strlen(word); // word length
		while (wlength > 0 && !isalpha(word[wlength - 1])) {
			word[wlength - 1] = '\0';
			wlength--;
		}

		if (wlength < k) {
			cout << word << endl;
			++count;
		}
		word = strtok_s(nullptr, " ");
	}

	cout << "Всего коротких слов: " << count << endl;

	delete[] sentence;
	delete[] copy;
}

void findnum(const char* text, int N) {
	const char* s_start = text;

	const char* fs_end = strchr(s_start, '.'); // first sentence end
	if (!fs_end || *(fs_end + 1) == '\0') {
		cout << "Второе предложение не найдено.\n";
		return;
	}
	s_start = fs_end + 1;

	const char* s_end = strchr(s_start, '.');
	if (!s_end) s_end = s_start + strlen(s_start);

	char* sentence = new char[s_end - s_start + 2];
	strncpy_s(sentence, s_start, s_end - s_start + 1);
	sentence[s_end - s_start + 1] = '\0';

	cout << "\nВторое предложение: " << sentence << endl;

	char* copy = new char[strlen(sentence) + 1];
	strcpy_s(copy, sentence);

	char* word = strtok_s(copy, " ");
	cout << "Числа <= " << N << " с двоичным палиндромным представлением:\n";

	while (word) {
		bool isnum = true; // is number
		for (size_t i = 0; i < strlen(word); ++i) {
			if (!isdigit(word[i])) {
				isnum = false;
				break;
			}
		}

		if (isnum) {
			int number = atoi(word);
			if (number <= N) {
				string binary = "";
				int temp = number;
				while (temp > 0) {
					binary = (temp % 2 == 0 ? "0" : "1") + binary;
					temp /= 2;
				}
				string reversedbinary = binary;
				reverse(reversedbinary.begin(), reversedbinary.end());
				if (binary == reversedbinary) {
					cout << number << " (Binary: " << binary << ")\n";
				}
			}
		}

		word = strtok_s(nullptr, " ");
	}

	delete[] sentence;
	delete[] copy;
}

void reorder(const char* sentence) {
	char* copy = new char[strlen(sentence) + 1];
	strcpy_s(copy, sentence);

	char* words[100];
	int wordcount = 0;

	char* word = strtok_s(copy, " ");
	while (word) {
		words[wordcount++] = word;
		word = strtok_s(nullptr, " ");
	}

	string result = "";
	bool used[100] = { false };

	for (int i = 0; i < wordcount; ++i) {
		if (!used[i]) {
			string chain = words[i];
			used[i] = true;
			char lastchar = tolower(words[i][strlen(words[i]) - 1]);

			for (int j = 0; j < wordcount; ++j) {
				if (!used[j] && tolower(words[j][0]) == lastchar) {
					chain += " " + string(words[j]);
					lastchar = tolower(words[j][strlen(words[j]) - 1]);
					used[j] = true;
				}
			}

			if (result.empty() || chain.length() > result.length()) {
				result = chain;
			}
		}
	}

	cout << "Переупорядоченные слова: " << result << endl;

	delete[] copy;
}

void wcoutput(const char* text, int wordcount) {
	const char* s_start = text;

	cout << "\nПредложения с " << wordcount << " словами в алфавитном порядке:\n";

	while (*s_start != '\0') {
		const char* s_end = strchr(s_start, '.');
		if (!s_end) {
			s_end = s_start + strlen(s_start);
		}

		char* sentence = new char[s_end - s_start + 2];
		strncpy_s(sentence, s_start, s_end - s_start + 1);
		sentence[s_end - s_start + 1] = '\0';

		char* copy = new char[strlen(sentence) + 1];
		strcpy_s(copy, sentence);

		int count = 0;
		char* word = strtok_s(copy, " ");
		while (word) {
			++count;
			word = strtok_s(nullptr, " ");
		}

		if (count == wordcount) {
			cout << sentence << endl;
		}

		delete[] copy;
		delete[] sentence;

		if (*s_end == '\0') break;
		s_start = s_end + 1;
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	const int MTL = 1000; // maximum text length
	char* text = new char[MTL];

	cout << "Введите текст, состоящий из нескольких предложений:\n";
	cin.getline(text, MTL);

	textprocess(text);

	int k;
	cout << "\nВведите значение k для коротких слов: ";
	cin >> k;
	cin.ignore();
	countShortWords(text, k);

	int N;
	cout << "\nВведите натуральное число N: ";
	cin >> N;
	cin.ignore();
	findnum(text, N);

	cout << "\nИзменение порядка слов в первом предложении...\n";
	const char* fs_end = strchr(text, '.');
	if (fs_end) {
		char* fs = new char[fs_end - text + 2];
		strncpy_s(fs, text, fs_end - text + 1);
		fs[fs_end - text + 1] = '\0';

		reorder(fs);
		delete[] fs;
	}

	int wordcount;
	cout << "\nВведите количество слов для предложений в алфавитном порядке: ";
	cin >> wordcount;
	cin.ignore();
	wcoutput(text, wordcount);

	delete[] text;
	return 0;
}
