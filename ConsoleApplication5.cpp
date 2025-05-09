#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

wstring makePlural(wstring word) {
    // Удаляем "(с)" если есть
    if (word.find(L"(с)") != wstring::npos) {
        word = word.substr(0, word.size() - 3);
    }

    // Проверяем исключения
    if (word == L"ребенок") return L"дети";
    if (word == L"бесенок") return L"бесенята";
    if (word == L"звонок") return L"звонки";
    if (word == L"позвонок") return L"позвонки";
    if (word == L"подонок") return L"подонки";
    if (word == L"колонок") return L"колонки";
    if (word == L"жаворонок") return L"жаворонки";
    if (word == L"бочонок") return L"бочонки";

    // Проверяем окончания
    if (word.size() < 4) return word; // слишком короткое слово

    wstring ending = word.substr(word.size() - 4);
    if (ending != L"онок" && ending != L"ёнок") return word;

    // Определяем последнюю согласную
    wchar_t last_consonant = word[word.size() - 5];
    bool is_shushing = (last_consonant == L'ж' || last_consonant == L'ч' ||
        last_consonant == L'ш' || last_consonant == L'щ');

    // Формируем множественное число
    wstring stem = word.substr(0, word.size() - 4);
    if (is_shushing) {
        return stem + L"ата";
    }
    else {
        return stem + L"ята";
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    wstring input;
    wcout << L"Введите слово (например 'цыпленок(с)'): ";
    getline(wcin, input);

    wstring plural = makePlural(input);
    wcout << L"Множественное число: " << plural << endl;

    return 0;
}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// Функция для проверки, является ли символ буквой
//bool isLetter(char c) {
//    return (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я') || c == 'ё' || c == 'Ё';
//}
//
//// Функция для преобразования существительного во множественное число
//string pluralizeNoun(const string& noun) {
//    // Проверяем исключения
//    if (noun == "ребенок") return "дети";
//    if (noun == "бесенок") return "бесенята";
//    if (noun == "звонок") return "звонки";
//    if (noun == "позвонок") return "позвонки";
//    if (noun == "подонок") return "подонки";
//    if (noun == "колонок") return "колонки";
//    if (noun == "экаворонок") return "экаворонки";
//    if (noun == "бочонок") return "бочонки";
//
//    // Проверяем окончания
//    if (noun.size() < 4) return noun;
//
//    string ending = noun.substr(noun.size() - 4);
//    if (ending != "онок" && ending != "ёнок") return noun;
//
//    // Определяем последнюю согласную
//    char last_consonant = noun[noun.size() - 5];
//    bool is_shushing = (last_consonant == 'ж' || last_consonant == 'ч' ||
//        last_consonant == 'ш' || last_consonant == 'щ');
//
//    // Формируем множественное число
//    string stem = noun.substr(0, noun.size() - 4);
//    if (is_shushing) {
//        return stem + "ата";
//    }
//    else {
//        return stem + "ята";
//    }
//}
//
//// Функция для обработки текста
//void processText(const string& text) {
//    string currentWord;
//    vector<string> words;
//
//    // Разбиваем текст на слова
//    for (char c : text) {
//        if (isLetter(c)) {
//            currentWord += tolower(c);
//        }
//        else {
//            if (!currentWord.empty()) {
//                // Проверяем, заканчивается ли слово на "онок" или "ёнок"
//                if (currentWord.size() >= 4) {
//                    string ending = currentWord.substr(currentWord.size() - 4);
//                    if (ending == "онок" || ending == "ёнок") {
//                        string plural = pluralizeNoun(currentWord);
//                        cout << currentWord << "(с) → " << plural << endl;
//                    }
//                }
//                currentWord.clear();
//            }
//        }
//    }
//}
//
//int main() {
//    string text = "В лесу жил волчонок(с), который дружил с медвежонком(с). "
//        "Они нашли ребёнка(с), а рядом прыгал зайчонок(с). "
//        "В траве был мышонок(с), а на ветке - воронёнок(с).";
//
//    cout << "Оригинальный текст:\n" << text << "\n\n";
//    cout << "Найденные существительные и их множественное число:\n";
//
//    processText(text);
//
//    return 0;
//}